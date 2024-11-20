# x64 NASM cheat sheet

## 🔗 Useful links
- [syscall table](https://filippo.io/linux-syscall-table/)
- [syscalls](https://man7.org/linux/man-pages/man2/syscall.2.html)

## 💻 Program structure

- `global <entry>` -> exposes entry point
- `extern <function>` -> declares a function in another linked .o file (e.g. C function, other asm file)
- `section <sectiontype>` -> sets section, usually:
  - `.text` -> program code
  - `.data` -> data
  - `.bss` -> uninitialized data

The program entry point of a standalone program is the label `_start`.  When
compiled with gcc, C provides `_start`, which inits and then jumps to `main`,
which should then be implemented by the program.

## 📊 Data

| Bytes | Bits | Prefix | .data  | .bss       |
|-------|------|--------|--------|------------|
| 1     | 8    | byte   | db     | resb       |
| 2     | 16   | word   | dw     | resw       |
| 4     | 32   | dword  | dd     | resd       |
| 8     | 64   | qword  | dq     | resq       |
| 10    | 80   | tword  | dt     | rest       |
| 16    | 128  | oword  | do/ddq | reso/resdq |
| 32    | 256  | yword  | dy     | resy       |
| 64    | 512  | zword  | dz     | resz       |

## 🔢 Registers

<table>
  <tr>
    <td>00000000</td><td>00000000</td><td>00000000</td><td>00000000</td>
    <td>00000000</td><td>00000000</td><td>00000000</td><td>00000000</td>
  </tr>
  <tr><td colspan="7"></td><td colspan="1" align="center">al</td></tr>
  <tr><td colspan="6"></td><td colspan="2" align="center">ax</td></tr>
  <tr><td colspan="4"></td><td colspan="4" align="center">eax</td></tr>
  <tr><td colspan="8" align="center">rax</td></tr>
</table>

| 8 bits (low) | 8 bits (high) | 16 bits | 32 bits | 64 bits | Role                | Preserved* |
|--------------|---------------|---------|---------|---------|---------------------|------------|
| `AL`         | `AH`          | `AX`    | `EAX`   | `RAX`   | Accumulator         | ❌         |
| `BL`         | `BH`          | `BX`    | `EBX`   | `RBX`   | Base, addressing    | ✅         |
| `CL`         | `CH`          | `CX`    | `ECX`   | `RCX`   | Counter, iterations | ❌         |
| `DL`         | `DH`          | `DX`    | `EDX`   | `RDX`   | Data                | ❌         |
| `DIL`        |               | `DI`    | `EDI`   | `RDI`   | -                   | ❌         |
| `SIL`        |               | `SI`    | `ESI`   | `RSI`   | -                   | ❌         |
| `SPL`        |               | `SP`    | `ESP`   | `RSP`   | Stack               | ✅         |
| `BPL`        |               | `BP`    | `EBP`   | `RBP`   | Frame               | ✅         |
| `R8B`        |               | `R8W`   | `R8D`   | `R8`    | -                   | ❌         |
| `R9B`        |               | `R9W`   | `R9D`   | `R9`    | -                   | ❌         |
| `R10B`       |               | `R10W`  | `R10D`  | `R10`   | -                   | ❌         |
| `R11B`       |               | `R11W`  | `R11D`  | `R11`   | -                   | ❌         |
| `R12B`       |               | `R12W`  | `R12D`  | `R12`   | -                   | ✅         |
| `R13B`       |               | `R13W`  | `R13D`  | `R13`   | -                   | ✅         |
| `R14B`       |               | `R14W`  | `R14D`  | `R14`   | -                   | ✅         |
| `R15B`       |               | `R15W`  | `R15D`  | `R15`   | -                   | ✅         |

*Preserved across function calls

### Registers as pointers

The default registers can be treated as pointers to memory addresses. To do so, use the square brackets `[]` to dereference the register. For example, to access the memory address stored in the `RDI` register, use `[RDI]`.

```asm
mov rax, rdi ; copy the value of RDI to RAX
mov rax, [rdi] ; copy the value at the memory address stored in RDI to RAX
```

## 📞 Syscalls

| syscall | Unix (rax) | Arg_1 (rdi) | Arg_2 (rsi) | Arg_3 (rdx) | Arg_4 (r10) | Arg_5 (r8) | Arg_6 (r9) | Return (rax)    |
|---------|------------|-------------|-------------|-------------|-------------|------------|------------|-----------------|
| write   | 1          | fd          | buf         | count       |             |            |            | Bytes written   |
| read    | 0          | fd          | buf         | count       |             |            |            | Bytes read      |
| open    | 2          | filename    | flags       | mode        |             |            |            | File descriptor |
| close   | 3          | fd          |             |             |             |            |            | 0 on success    |
| exit    | 60         | status      |             |             |             |            |            |                 |


## 🚩 Conditionals

| Instruction | Description               |
|-------------|---------------------------|
| `j~ x`      | Jump to x if ~            |
| `cmov~ x, y`| Conditional mov x, y if ~ |
| `setc~ x`   | Set x to 1 if ~           |

### Conditions

| Signed | Unsigned | Description       |
|--------|----------|-------------------|
| `~e`   |          | Equal             |
| `~ne`  |          | Not equal         |
| `~g`   | `~a`     | Greater           |
| `~ge`  | `~ae`    | Greater or equal  |
| `~l`   | `~b`     | Less              |
| `~le`  | `~be`    | Less or equal     |
| `~z`   |          | Zero              |
| `~nz`  |          | Not zero          |
| `~s`   |          | Sign              |
| `~ns`  |          | Not sign          |
| `~o`   |          | Overflow          |
| `~no`  |          | Not overflow      |

## 🛠️ Instructions

### Arithmetic

| Instruction | Description          | Signed |
|-------------|----------------------|--------|
| `add x, y`  | x += y               | ✅     |
| `sub x, y`  | x -= y               | ✅     |
| `mul x`     | rax *= x             | ❌     |
| `imul x`    | rax *= x             | ✅     |
| `div x`     | rax /= x             | ❌     |
| `idiv x`    | rax /= x             | ✅     |
| `inc x`     | x++                  | ✅     |
| `dec x`     | x--                  | ✅     |
| `neg x`     | x = -x               | ✅     |
| `cmp x, y`  | Compare x and y      | ✅     |

### Logic

| Instruction | Description          |
|-------------|----------------------|
| `and x, y`  | x &= y               |
| `or x, y`   | x \|= y              |
| `xor x, y`  | x ^= y               |
| `not x`     | x = ~x               |
| `shl x, y`  | x <<= y              |
| `shr x, y`  | x >>= y              |

### Control flow

| Instruction | Description           |
|-------------|-----------------------|
| `jmp x`     | Jump to x             |
| `call x`    | Call x                |
| `ret`       | Return                |
| `nop`       | No operation          |
| `loop x`    | Jump to x if rcx != 0 |

### Data movement

| Instruction | Description          |
|-------------|----------------------|
| `mov x, y`  | x = y                |
| `push x`    | Push x to stack      |
| `pop x`     | Pop x from stack     |
| `xchg x, y` | Swap x and y         |

### String manipulation

| Instruction | Description          |
|-------------|----------------------|
| `rep x`     | Repeat x             |
| `movs`      | Move string          |
| `cmps`      | Compare strings      |
| `scas`      | Scan string          |
| `lods`      | Load string          |
| `stos`      | Store string         |

## 📦 Stack

- The stack grows downwards
- `push` decrements `rsp` and writes to the new address
- `pop` reads from the current address and increments `rsp`
- `call` pushes the return address to the stack
- `ret` pops the return address from the stack

## 📜 Example

```asm
section .text
global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, message
    mov rdx, message_len
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall

section .data
    message db "Hello, World!", 0xa
    message_len equ $ - message
```

## `call x wrt ..plt`

The `wrt ..plt` directive in assembly language is used when dealing with Position-Independent Code (PIC), which is common in shared libraries. `wrt` stands for "with respect to," and `..plt` refers to the Procedure Linkage Table (PLT).

When you use `call x wrt ..plt`, you are instructing the assembler to generate a call to the function `x` through the PLT. The PLT is a mechanism used by the dynamic linker to resolve function addresses at runtime. This allows the code to call functions whose addresses are not known until the program is loaded into memory.

In summary, `call x wrt ..plt` ensures that the function call is made in a way that is compatible with dynamic linking, enabling the function `x` to be resolved correctly at runtime.