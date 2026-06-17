Rosalind Programming Language
=============================

Rosalind is a strongly typed and model checked programming language written in a
Wirthian style. The type checker is simple; it is meant to enable stronger
contracts in the model checker.

Rosalind is named after the Uranian moon as a nod to Wirth languages. The
moon itself was named after the character Rosalind from Shakespeare's "As You
Like It". Harold Bloom lauded Rosalind as a character. The name of the language
is also a nod to Rosalind Franklin, whose incredible work on X-ray
crystallography directly led to the discovery that DNA was a double helix.

Other languages in the heritage of Pascal, such as Ada, have function contracts.
These have been expanded by frameworks such as Ada SPARK to ensure that these
contracts are verified through proof automation. Rosalind tries to address one
of Wirth's biggest criticisms of Ada -- its complexity -- by providing similar
safety. It does this by relying on bounded model checking via an SMT solver to
discharge contract verification. This has one advantage of making loop invariant
reasoning optional when loop related properties can be discharged through
unwinding.

Type erasure in Rosalind is handled by the `HIDE` and `REVEAL` operators, which
can be used to reduce a pointer to a type to an `OPAQUE POINTER` type and later,
downcast this pointer to its original type.  `REVEAL` requires the use of a
function contract and model checking to verify that any indirect use of a
revealed type must actually point to a value of its original type.

This mechanism should be contrasted with more complex type erasure found in
Java Generics. Further, it avoids the template monomorphism found in C++
templates or Rust Generics. Rosalind provides generic containers (e.g.
`RedBlackTree`) and generic algorithms (e.g. `mergeSort`) through strict type
erasure. Developers explicitly `HIDE` the type of data when passing `OPAQUE
POINTER` parameters to generic containers or constructors, then can use `REVEAL`
in user provided callback functions to safely restore the concrete type.

Pointer verification in Rosalind's type checker is managed by maintaining a
pointer that is split between object type and offset. This makes program state
easier for the model checker to follow when it encounters pointer math and
pointer aliasing.

Bootstrapping
-------------

The Rosalind compiler is written in Rosalind. A smaller bootstrap compiler,
written in C, is used to transform a Rosalind subset language to C. This
bootstrap compiler is used to compile a first pass of the Rosalind compiler,
which is then used to compile a second pass of the compiler. A third and final
pass is compiled from this second pass compiler and then compared to the second
pass compiler to ensure that its output matches.
