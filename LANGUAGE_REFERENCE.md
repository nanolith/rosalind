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

Functions
---------

A function is a subprogram that performs some operation and returns a value. By
default, functions are *pure*, which means that they do not have any
side-effects. For example, this function squares a number.

```
    PUBLIC square(a: REAL): REAL
    BEGIN
        square := a * a;
    END;
```
