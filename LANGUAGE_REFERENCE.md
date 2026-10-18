Rosalind Language Reference
===========================

This language reference is a work in progress. In it, I describe the language
structure from the top down.

Modules
-------

A `MODULE` keyword begins a module. A module has a name, an import list, and a
list of symbols. Symbols can be functions, procedures, records, or globals.
While identifier names are case sensitive, there is no hard rule that they must
start with a capital or lowercase letter. I recommend capitalization, and that
the name should reflect the name of the source file. Module names can be
extended with dots. When searching modules for import, each dot level represents
a subdirectory. So the source file for the `Foo.Bar.Baz` module should be
located in `Foo/Bar/` and named `Baz.rls`.

```
    MODULE Foo.Bar.Baz;
```

The import list consists of zero or more imports. An import starts with the
`IMPORT` keyword, then lists a module name, with an optional `AS` keyword for a
shorthand reference, then an optional list of symbols to import into the
module's namespace. By default, any public symbol for a module (e.g. `Mod`) can
be referenced with the module name or shorthand name, dot, symbol name. For
instance, the `x` variable defined in `Mod` can be referenced as `Mod.x`. In the
following example, if `closeFile` is defined as a public symbol in
`System.File`, it can be referenced as `System.File.closeFile` or `F.closeFile`.
Since `createFile` is explicitly referenced for inclusion in this module's
namespace, it can be referenced directly as `createFile`.

```
    IMPORT System.File AS F (createFile, closeFile);
```

Global Variables
----------------

A global variable is defined at the module scope, using a visibility modifier
(`PUBLIC` or `PRIVATE`), a name, and a type. For example:

```
    PRIVATE singletonInitialized : BOOLEAN = FALSE;
```

Pure Functions
--------------

A function is a subprogram that performs some operation and returns a value. By
default, functions are *pure*, which means that they do not have any
side-effects. For example, this function squares a number.

```
    PUBLIC square(a: REAL): REAL
    BEGIN
        square := a * a;
    END;
```

Impure Functions
----------------

The compiler automatically verifies the purity of a function. If any impure
action is taken, this is an error unless the function contracts are relaxed to
document this impurity.

For example, this function finds the roots for a given quadratic equation given
its `a`, `b`, and `c` coefficients. Because there can be zero, one, or two
roots, the function takes a zero based `index` argument, returning `TRUE` if the
root is available, and `FALSE` otherwise. If the function returns `TRUE`, the
`result` pointer is set to the root.

This function presents a challenge: the `result` output parameter and the return
value of the function are linked. This output parameter should be set to a valid
root if the return value is `TRUE`. For sake of illustration, we will set the
output parameter to `0` if the return value is `FALSE`. There is nothing but
documentation to explain this relationship, which isn't very stable. How do we
ensure that this side-effect is accounted for, and happens as we document it no
matter which branch the function takes? How do we ensure that no other
side-effects occur? For this, we relax the purity of the function by overriding
the default function contract to include a **pre-condition** requiring that the
output parameter references a valid `REAL` variable, and we include a
**post-condition** requiring that the function has updated this output
parameter, and if the function does not find a valid root, this output parameter
is set to `0`.

```
    PUBLIC quadraticRoot(
        result: POINTER TO REAL, index: INT(8), a: REAL, b: REAL, c: REAL):
            BOOLEAN
    PRECONDITIONS
    BEGIN
        ASSERT PropertyValidReferenceToREAL(result);
    END;
    POSTCONDITIONS
    BEGIN
        ASSERT PropertyVariableModified(result);

        IF quadraticRoot <> TRUE THEN
            ASSERT (result^ = 0);
    END;
    BEGIN
        CONST discriminant: REAL = b * b - 4 * a * c;

        IF     (a = 0)
            OR (discriminant < 0)
            OR (index > 0 AND discriminant = 0)
            OR (index > 1)
        THEN
        BEGIN
            result^ := 0;
            quadraticRoot := FALSE;
        END
        ELSE
        BEGIN
            quadraticRoot := TRUE;

            IF index = 0 THEN
                result^ := ((b * -1) + SQRT(discriminant)) / (2 * a)
            ELSE
                result^ := ((b * -1) - SQRT(discriminant)) / (2 * a);
        END;
    END;
```
