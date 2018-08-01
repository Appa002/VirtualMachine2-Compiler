# VM 2.0 Compiler

A simple compiler that abstracts away some parts of writing vm2.0 bytecode directly.
You probably want to have read the vm2.0 spec https://github.com/batburger/VirtualMachine2/blob/master/specs/specs.pdf .

Beware messy code!

## Usage
vmc [FILE]

Will compile the `FILE` and output it as out.vm2.

## Language
Every line of the program contains at most one instruction.
Most lines will look like this:
`[INSTRUCTION NAME] [ARG1] [ARG2]...`
where the `INSTRUCTION NAME` is the name of any instruction defined in the vm2.0 specs (except `push`).
(https://github.com/batburger/VirtualMachine2/blob/master/specs/specs.pdf), and the `ARGn` are the arguments to that
instruction. One can write normal numbers (`3`), negative numbers(`-3`), floats(`0.5`) or hex numbers(`0x0d`).
Every argument is 32 bit in size.
e.g. `jmp 0x00`

### Special lines
If a line starts with a `'`, then it's defining a scoped symbol. (See special arguments later). The rest of the line is
interpreted as usual. A scoped symbol can only be resolved in the file it was defined in. A scoped symbols name must be 
a string of ASCII characters uninterrupted by white-spaces.
e.g. `'mySym jmp 0x00`.

If a line starts with a `''`, then it's defining a global Symbol (See special arguments later). The rest of the line is 
interpreted as usual. A global symbols name must be a string of ASCII characters uninterrupted by white-spaces. A global
symbol can be resolved from any file.
e.g. `''myGlobalSym jmp 0x00'`

If a line starts with a `#`, then it's including a file. The included file is "copy-pasted" at the end of the file
including it.
e.g. `#./otherFile.txt`

### Special Args
If a argument starts with a `@`, then it's resolving a scoped symbol. This means that the address of the instruction
where the scoped symbol was defined is inserted as that argument. A scoped symbol can only be resolved in the file it 
was defined in.
e.g.
```
'mySymbol cmp 3 4
jmp @mySymbol
```
`jmp`'s argument now is the address of the `cmp`.


If a argument starts with a `@@`, then it's resolving a global symbol. This means that the address of the instruction
where the global symbol was defined is inserted as that argument. A global symbol can be resolved from any file.
e.g.
```
''myGlobalSymbol cmp 3 4
jmp @@myGlobalSymbol
```
`jmp`'s argument now is the address of the `cmp`.

If a argument is just `STACK`, then it's not loading any extra values and just uses the value at the top of the stack.
NOTE: due to the first-in-last-out nature of the stack this would be ill-formed: `cmp STACK 0.5`,
but `cmp STACK STACK` and `cmp 0.5 STACK` would be fine.
e.g. `cmp 4 STACK` would compare the value stored on the stack with 4

`$0 ... $9` If a argument contains this, then it's reading a register. This means that the content of that register is used
as the value for the argument.
e.g. `jmp $0` would jump to the value specified in the register 0.

If a argument contains `*123`, then it's reading linear memory. This means that the content stored in linear memory at
the address specified by the number after the `*` is used as the value for the argument.
e.g. `jmp *123` would jump to the value specified at the address 123 in linear memory.

one can combine `*` and `$0...$9`:
e.g. `jmp *$4` would jump to the value stored in linear memory at a address, which is stored in register 4.

## Compiling
Compiling this program is easy as it only uses standard library stuff.
compilation steps:
```
mkdir build
cd build
cmake ..
make
```