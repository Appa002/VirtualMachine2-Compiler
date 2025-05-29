# VM 2.0 Compiler

A simple compiler that abstracts away some parts of writing vm2.0 bytecode directly.
The vm2.0 spec, while incomplete, could be useful https://github.com/batburger/VirtualMachine2/blob/master/specs/specs.pdf .

(This was created in 2018 / This is a hobby High School project)

## Usage
vmc [FILE]

Compiles the `FILE` and outputs it as out.vm2.

## Language
Every line of the program contains, at most, one instruction.
Most lines will look like this:
`[INSTRUCTION NAME] [ARG1] [ARG2]...`
where the `INSTRUCTION NAME` is the name of any instruction defined in the vm2.0 specs (except `push`).
For the arguments, `ARGn`, you can write regular numbers (`3`), negative numbers(`-3`), floats(`0.5`) or hex numbers(`0x0d`).
Every argument is 32 bits in size.

### Special lines
If a line starts with a `'`, it defines a scoped symbol as a string of uninterrupted ASCII characters. The compiler can only resolve a scoped symbol in the file the symbol is defined in and marks the address of the following instruction. Id est `mySym` in `'mySym jmp 0x00` would refer to the address of the `jmp` instruction.

If a line starts with a `''`, then it's defining a global Symbol which works like the scoped symbol above, except the compiler will resolve it in any included file.

A line that starts with a `#` includes a file which is "copy-pasted" at the location of the include. That is, `#./otherFile.txt` would copy-paste otherFile to the included location.

### Special Args
If an argument starts with an `@`, it resolves a scoped symbol, inserting the address the scoped symbol refers to at the location of the `@`. That is in
```
'mySymbol cmp 3 4
jmp @mySymbol
```
`jmp`'s argument is the address of the `cmp`.


If an argument starts with a `@@`, then it's resolving a global symbol. This works the same way as above but can be done from any file e.g.:
```
''myGlobalSymbol cmp 3 4
jmp @@myGlobalSymbol
```
`jmp`'s argument is the address of the `cmp`.

If an argument is just `STACK`, then it's not loading any extra values and uses the value at the top of the stack.
NOTE: due to the first-in-last-out nature of the stack, this would be ill-formed: `cmp STACK 0.5`,
but `cmp STACK STACK` and `cmp 0.5 STACK` would be fine.
That is `cmp 4 STACK` would compare the value stored on the stack with 4.

`$0 ... $9` refers to the virtual machine's ten registers. For example, `jmp $0` would jump to the value specified in the register 0.

`*123` refers to reading from linear memory, essentially an array on the heap that the VM can arbitrarily write to. The content at the address after`*` is used as the value for the argument.
That is, `jmp *123` would jump to the value specified at the address 123 in linear memory.

One can combine `*` and `$0...$9`:
`jmp *$4` jump sto the value stored in linear memory at the address stored in register 4.

## Dependencies
* C++17 standard library

## Building
```
mkdir build
cd build
cmake ..
cmake --build .
```
