# Samsung RISC-V
The program focuses on the RISC-V architecture and utilizes open-source tools to educate individuals about VLSI chip design and RISC-V. The program is led by Kunal Ghosh Sir.

# ESSENTAIL DETAILS
NAME: BHAVANA RAMAKRISHNA    
COLLEGE: DAYANANDA SAGAR COLLEGE OF ENGINEERING      
EMAIL ID: [bhavramki@gmail.com](bhavramki@gmail.com)      
GITHUB USERNAME :[Bhavramsi](https://github.com/Bhavramsi)         
LINKEDIN PROFILE :[Bhavana Ramakrishna](https://www.linkedin.com/in/bhavana-ramakrishna-1520922ba?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)        

# TASK 1
 This Task involves reviewing C-based and RISC-V-based lab videos and performing the compilation of C code using both GCC and the RISC-V compiler.

 # TASK 2
 Performing SPIKE simulation and debugging the C code using Spike's interactive debugging mode.

 What is SPIKE in RISCV?
A RISC-V ISA is a simulator, enabling the testing and analysis of RISC-V programs without the need for actual hardware.
Spike is a free, open-source C++ simulator for the RISC-V ISA that models a RISC-V core and cache system. It can be used to run programs and a Linux kernel, and can be a starting point for running software on a RISC-V target.
What is pk (Proxy Kernel)?
The RISC-V Proxy Kernel, pk , is a lightweight application execution environment that can host statically-linked RISC-V ELF binaries.

Testing the Spike Simulator

The objective is to execute the sum1ton.c program using both the gcc compiler and the riscv compiler, ensuring that both compilers produce identical output on the terminal. To compile the code with the gcc compiler.       
```
gcc sum1ton.c
./a.out
```

And to compile the code using RISCV Compiler                       
```
spike pk sum1ton.o
```

RISCV Objdump with -Ofast        
```
riscv64-unknown-elf-objdump -d sum1ton.o
riscv64-unknown-elf-objdump -d sum1ton.o | less
 ```

Open the Objdump of code by using the following command                   
```
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum1ton.o | less
```


Debugging the Assembly Language Program of sum1ton.c                   
```
riscv64-unknown-elf-objdump -d sum1ton.o | less 
spike -d pk sum1ton.o
```

Open the debugger in another terminal by using the following command.         
```
spike -d pk sum1ton.o
```
We can follow similar steps for debugging -O1 format after finding the object dump of -O1 

Open the Objdump of code by using the following command                   
```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum1ton.o | less
```

# TASK 3
## "Decoding RISC-V Instructions: A Visual Guide"
### "Understanding I-Type, S-Type, B-Type, U-Type, and J-Type Instructions"
  ## Introduction Section:
RISC-V (Reduced Instruction Set Computer - V) is an open standard instruction set architecture (ISA) based on established reduced instruction set computing principles. Unlike proprietary ISAs, RISC-V is free and open, enabling unrestricted academic and commercial use without licensing fees. This has made RISC-V an attractive option for research, education, and industry applications, fostering innovation and development across various domains.
### Importance of Understanding Instruction Formats
Understanding instruction formats is crucial for several reasons:
1. **Instruction Decoding**: Knowing the structure of different instruction formats enables the correct decoding of instructions, which is essential for the CPU to execute them correctly.
2. **Pipeline Design**: Instruction formats impact the design of the CPU pipeline. Proper handling of instruction formats ensures efficient instruction fetch, decode, execution, memory access, and write-back stages.
3. **Compiler Design**: Compilers generate machine code that adheres to the ISA's instruction formats. A deep understanding of these formats helps in optimizing code generation, leading to better performance and efficiency.
4. **Debugging and Verification**: Understanding instruction formats aids in debugging and verifying hardware and software. It helps in identifying issues related to incorrect instruction execution or pipeline hazards.
5. **Extensibility and Customization**: RISC-V's modular and extensible nature allows for custom extensions. Understanding the base instruction formats is essential for creating and integrating custom instructions tailored to specific applications or performance needs.
# BASICS
 ## Instruction Types and Fields
The RISC-V instructions are categorized into types based on their field organization. Each type has specific fields like opcode, func3, func7, immediate values, and register numbers. The types include:
- **R-type**: Register type
- **I-type**: Immediate type
- **S-type**: Store type
- **B-type**: Branch type
- **U-type**: Upper immediate type
- **J-type**: Jump type
## Opcode and Function Fields
- **Opcode**: Determines the type of instruction.
- **func3** and **func7**: Further specify the operation within the instruction type.
  - Example: In R-type instructions, func3 and func7 differentiate between operations like addition and subtraction.
## Immediate Values and Registers
- **Immediate Values**: Encoded in specific fields within the instruction.
  - Example: I-type instructions use a 12-bit immediate value field along with source and destination registers.
- **Registers**: Specified in fields such as rd (destination register), rs1 (source register 1), and rs2 (source register 2).
### Example - U-Type Instruction
Consider the `lui` (Load Upper Immediate) instruction:
- **Assembly**: `lui x5, 0x12345`
- **Encoding**: The immediate value `0x12345` is placed in the instruction’s immediate field, and the destination register `x5` is specified in the rd field.
- **Machine Execution**: The machine loads the upper 20 bits of the immediate value into the upper 20 bits of register `x5`.
   ## Arithmetic Instructions
- **ADD**: Adds values in two registers and stores the result in a third register.
  - Example: `ADD rd, rs1, rs2` (rd = rs1 + rs2)
- **ADDI**: Adds a register and an immediate value (constant) and stores the result.
  - Example: `ADDI rd, rs1, imm` (rd = rs1 + imm)
## Logical Instructions
- **AND, OR, XOR**: Perform bitwise operations.
  - Example: `AND rd, rs1, rs2` (rd = rs1 & rs2)
## Branch Instructions
- **BEQ**: Branch if equal.
  - Example: `BEQ rs1, rs2, offset` (if rs1 == rs2, PC = PC + offset)
- **BNE**: Branch if not equal.
  - Example: `BNE rs1, rs2, offset` (if rs1 != rs2, PC = PC + offset)
## Load and Store Instructions
- **LW**: Load word from memory.
  - Example: `LW rd, offset(rs1)` (rd = memory[rs1 + offset])
- **SW**: Store word to memory.
  - Example: `SW rs1, offset(rs2)` (memory[rs2 + offset] = rs1)
## Special Instructions
- **AUIPC**: Add upper immediate to PC.
  - Example: `AUIPC rd, imm` (rd = PC + imm << 12)
## Branch and Jump Instructions
- **Jump (J)**: Unconditional branch to a specified address.
- **Branch (B)**: Conditional branch based on a comparison.
## RV32I Extensions
RISC-V allows optional extensions for additional functionality:
- **M**: Integer multiplication and division.
- **A**: Atomic instructions.
- **F, D, Q**: Floating-point operations (32-bit, 64-bit, 128-bit).
- **C**: Compressed instructions.
### RISC-V R-Type Instructions
R-type instructions are used for operations that involve only registers. These instructions typically perform arithmetic, logical, and shift operations.
#### Format: 
![image](https://github.com/user-attachments/assets/e01d8bbe-710e-4927-8fec-51f162d384ca)
- **opcode**: Specifies the operation (e.g., 0110011 for integer register-register operations).
- **rd**: Destination register.
- **funct3**: Further specifies the operation.
- **rs1**: First source register.
- **rs2**: Second source register.
- **funct7**: Further specifies the operation.
### I-Type Instructions
I-Type instructions cover various operations, including immediate arithmetic, load operations, and certain control flow instructions.
### Extracting Immediate Value
- The immediate value spans bits [31:20].
- To extract this value:
  - Mask the instruction to isolate the relevant bits.
  - Perform a right shift to align the immediate value to the least significant bits (LSBs).
- **Example**: If the instruction value is `0x12345678`, the immediate value is extracted as follows:
  ```cpp
  uint32_t imm_i = (instruction & 0xFFF00000) >> 20;
![image](https://github.com/user-attachments/assets/3d035720-dc62-45d5-9a2c-2a6b263ade74)
**Example: ADDI rd, rs1, imm**
- **opcode**: 0010011 (for immediate arithmetic operations)
- **funct3**: 000 (for ADDI)
- **imm**: Immediate value
- **rs1**: Source register 1
- **rd**: Destination register
### S-Type Instructions
![image](https://github.com/user-attachments/assets/eb224238-c0ef-42ca-82d0-c42ed8293320)
**Example: SW rs2, imm(rs1)**
- **opcode**: 0100011 (for store operations)
- **funct3**: 010 (for SW)
- **imm**: Immediate value (split into imm[11:5] and imm[4:0])
- **rs1**: Base address register
- **rs2**: Source register to be stored
### B-Type Instructions
![image](https://github.com/user-attachments/assets/7f138e24-cb0c-4506-9875-c4b3b14a2670)
**Example: BEQ rs1, rs2, imm**
- **opcode**: 1100011 (for branch operations)
- **funct3**: 000 (for BEQ)
- **imm**: Immediate value (split into imm[12], imm[10:5], imm[4:1], imm[11])
- **rs1**: Source register 1
- **rs2**: Source register 2
### U-Type Instructions
U-Type instructions are used for operations like loading upper immediate (LUI) and adding upper immediate to PC (AUIPC).
### Extracting Immediate Value
- The immediate value in U-type instructions spans bits [31:12].
- To extract this value, you can mask the instruction with `0xFFFFF000`.
- **Example**: If the instruction value is `0x12345000`, applying the mask will yield `0x12345000`.
### Encoding and Usage
- The immediate value extracted directly forms part of the U-type instruction.
  - For **LUI**, this value is loaded into the destination register.
  - For **AUIPC**, this value is added to the current PC.
![image](https://github.com/user-attachments/assets/d6269585-d85a-4675-b13f-4ae4ed1ea05a)
**Example: LUI rd, imm**
- **opcode**: 0110111 (for LUI)
- **imm**: Upper 20 bits of the immediate value
- **rd**: Destination register
### J-Type Instructions
![image](https://github.com/user-attachments/assets/9b35cad7-8fd8-41da-be46-aec4cf712657)
**Example: JAL rd, imm**
- **opcode**: 1101111 (for JAL)
- **imm**: Immediate value (split into imm[20], imm[10:1], imm[11], imm[19:12])
- **rd**: Destination register (stores the return address)

# 15 UNIQUE RISC-V INSTRUCTIONS 
! [IMAGE] ("D:\vsdworkshop\obj dump using -O1.png")
### Machine Code for `addi sp, sp, -16`
*addi (Add Immediate):* This instruction adds an immediate value to a register, storing the result in the destination register.

#### Instruction: `addi sp, sp, -16`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** -16 (12 bits, two's complement)
- **Source Register (rs1):** sp (x2, 5 bits)
- **Destination Register (rd):** sp (x2, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (-16):** `111111111000` (12 bits, two's complement)
- **rs1 (sp = x2):** `00010`
- **funct3:** `000`
- **rd (sp = x2):** `00010`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi sp, sp, -16`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 111111111000        | 00010        | 000             | 00010       | 0010011         |

#### Binary Representation:
- **Binary:** `111111111000 00010 000 00010 0010011`
- **Hex:** `ff5013`

---

### 2. `sd ra, 8(sp)`
*sd (Store Doubleword):* This instruction stores a 64-bit value from a source register into memory.

#### Instruction: `sd ra, 8(sp)`
- **Opcode:** 0100011 (7 bits)
- **Immediate:** 8 (12 bits, split into two parts: imm[11:5] and imm[4:0])
- **Source Register (rs2):** ra (x1, 5 bits)
- **Base Register (rs1):** sp (x2, 5 bits)
- **Function (funct3):** 011 (3 bits)

#### Breakdown:
- **Immediate (8):** `000000001000` (split into imm[11:5] = `0000000` and imm[4:0] = `01000`)
- **rs2 (ra = x1):** `00001`
- **rs1 (sp = x2):** `00010`
- **funct3:** `011`
- **Opcode:** `0100011`

### Machine Code Breakdown for `sd ra, 8(sp)`
| imm[11:5] (7 bits) | rs2 (5 bits) | rs1 (5 bits) | funct3 (3 bits) | imm[4:0] (5 bits) | Opcode (7 bits) |
|--------------------|--------------|--------------|-----------------|-------------------|-----------------|
| 0000000            | 00001        | 00010        | 011             | 01000             | 0100011         |

#### Binary Representation:
- **Binary:** `0000000 00001 00010 011 01000 0100011`
- **Hex:** `0001023f`

---

### 3. `li a5, 500`
*li (Load Immediate):* This instruction loads a 32-bit immediate value into a register.

#### Instruction: `li a5, 500`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 500 (12 bits, sign-extended)
- **Destination Register (rd):** a5 (x15, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (500):** `000000111110100` (12 bits)
- **rd (a5 = x15):** `01111`
- **funct3:** `000`
- **Opcode:** `0010011`

### Machine Code Breakdown for `li a5, 500`
| Immediate (12 bits) | rd (5 bits) | funct3 (3 bits) | Opcode (7 bits) |
|---------------------|-------------|-----------------|-----------------|
| 000000111110100     | 01111       | 000             | 0010011         |

#### Binary Representation:
- **Binary:** `000000111110100 01111 000 00111 0010011`
- **Hex:** `01f30313`

---

### 4.`addiw a5, a5, -1`
*addiw (Add Immediate Word):* This instruction adds a 32-bit immediate value to a register and stores the result in the destination register.

#### Instruction: `addiw a5, a5, -1`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** -1 (12 bits, two's complement)
- **Source Register (rs1):** a5 (x15, 5 bits)
- **Destination Register (rd):** a5 (x15, 5 bits)
- **Function (funct3):** 001 (3 bits)

#### Breakdown:
- **Immediate (-1):** `111111111111` (12 bits, two's complement)
- **rs1 (a5 = x15):** `01111`
- **funct3:** `001`
- **rd (a5 = x15):** `01111`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addiw a5, a5, -1`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 111111111111        | 01111        | 001             | 01111       | 0010011         |

#### Binary Representation:
- **Binary:** `111111111111 01111 001 01111 0010011`
- **Hex:** `fff30313`

---

### 5. `bnez a5, 10190 <main+0xc>`
*Branch if Not Equal to Zero:* This instruction performs a branch if the value in the source register is not zero.

#### Instruction: `bnez a5, 10190 <main+0xc>`
- **Opcode:** 1100011 (7 bits)
- **Immediate:** 10190 (12 bits, sign-extended)
- **Source Register (rs1):** a5 (x15, 5 bits)
- **Function (funct3):** 001 (3 bits)

#### Breakdown:
- **Immediate (10190):** `00000000000101001110` (split into imm[12|10:5] = `0000000` and imm[4:1|11] = `101001110`)
- **rs1 (a5 = x15):** `01111`
- **funct3:** `001`
- **Opcode:** `1100011`

### Machine Code Breakdown for `bnez a5, 10190 <main+0xc>`
| imm[12|10:5] (7 bits) | rs1 (5 bits) | funct3 (3 bits) | imm[4:1|11] (5 bits) | Opcode (7 bits) |
|-----------------------|--------------|-----------------|-----------------------|-----------------|
| 0000000               | 01111        | 001             | 01001110              | 1100011         |

#### Binary Representation:
- **Binary:** `0000000 01111 001 01001110 1100011`
- **Hex:** `000f13f3`

---

### 6.`lui a2, 0x1f`
*lui (Load Upper Immediate):* This instruction loads a 20-bit immediate value into the upper 20 bits of a register, setting the lower 12 bits to zero.

#### Instruction: `lui a2, 0x1f`
- **Opcode:** 0110111 (7 bits)
- **Immediate:** 0x1f (20 bits, upper 20 bits of the immediate value)
- **Destination Register (rd):** a2 (x6, 5 bits)

#### Breakdown:
- **Immediate (0x1f):** `0000000000011111` (20 bits, shifted left by 12 bits to be placed in the upper 20 bits of the register)
- **rd (a2 = x6):** `00110`
- **Opcode:** `0110111`

#### Binary Representation:
- **Binary:** `00000000000000000000 00110 0110111`
- **Hex:** `00030337`

### Machine Code Breakdown for `lui a2, 0x1f`
| imm[19:12] (8 bits) | imm[11:0] (12 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|----------------------|-------------|-----------------|
| 00000000            | 0000000001111111     | 00110       | 0110111         |

---

### 7. `addi a2, a2, -1726`
*addi (Add Immediate):* This instruction adds an immediate value to a register.

#### Instruction: `addi a2, a2, -1726`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** -1726 (12 bits, two's complement)
- **Source Register (rs1):** a2 (x6, 5 bits)
- **Destination Register (rd):** a2 (x6, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (-1726):** `1111111011100010` (12 bits, two's complement)
- **rs1 (a2 = x6):** `00110`
- **funct3:** `000`
- **rd (a2 = x6):** `00110`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi a2, a2, -1726`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 111111101110        | 00110        | 000             | 00110       | 0010011         |

#### Binary Representation:
- **Binary:** `111111101110 00110 000 00110 0010011`
- **Hex:** `ffd30393`

---

### 8. `li a1, 500`
*li (Load Immediate):* This instruction loads an immediate value into a register.

#### Instruction: `li a1, 500`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 500 (12 bits)
- **Destination Register (rd):** a1 (x11, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (500):** `0000000111110100` (12 bits)
- **rd (a1 = x11):** `01011`
- **funct3:** `000`
- **Opcode:** `0010011`

### Machine Code Breakdown for `li a1, 500`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000011111        | 00000        | 000             | 01011       | 0010011         |

#### Binary Representation:
- **Binary:** `000000011111 00000 000 01011 0010011`
- **Hex:** `01f30393`

---

### 9. `lui a0, 0x21`
*lui (Load Upper Immediate):* This instruction loads a 20-bit immediate value into the upper 20 bits of a register.

#### Instruction: `lui a0, 0x21`
- **Opcode:** 0110111 (7 bits)
- **Immediate:** 0x21 (20 bits)
- **Destination Register (rd):** a0 (x10, 5 bits)

#### Breakdown:
- **Immediate (0x21):** `0000000000100001` (20 bits, shifted to upper 20 bits)
- **rd (a0 = x10):** `01010`
- **Opcode:** `0110111`

### Machine Code Breakdown for `lui a0, 0x21`
| imm[19:12] (8 bits) | imm[11:0] (12 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|----------------------|-------------|-----------------|
| 00000000            | 000000100001         | 01010       | 0110111         |

#### Binary Representation:
- **Binary:** `00000000000000000000 01010 0110111`
- **Hex:** `00052137`

---

### 10. `addi a0, a0, 400`
*addi (Add Immediate):* This instruction adds an immediate value to a register.

#### Instruction: `addi a0, a0, 400`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 400 (12 bits)
- **Source Register (rs1):** a0 (x10, 5 bits)
- **Destination Register (rd):** a0 (x10, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (400):** `0000000110010000` (12 bits)
- **rs1 (a0 = x10):** `01010`
- **funct3:** `000`
- **rd (a0 = x10):** `01010`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi a0, a0, 400`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000011001        | 01010        | 000             | 01010       | 0010011         |

#### Binary Representation:
- **Binary:** `000000011001 01010 000 01010 0010011`
- **Hex:** `00066093`

---

### 11. `jal ra, 10418`
*jal (Jump and Link):* This instruction performs a jump to a target address, saving the return address in the link register (ra).

#### Instruction: `jal ra, 10418`
- **Opcode:** 1101111 (7 bits)
- **Immediate:** 10418 (20 bits, sign-extended)
- **Destination Register (rd):** ra (x1, 5 bits)

#### Breakdown:
- **Immediate (10418):** `00000000001010011100` (20 bits, shifted by 1)
- **rd (ra = x1):** `00001`
- **Opcode:** `1101111`

### Machine Code Breakdown for `jal ra, 10418`
| imm[19:12] (8 bits) | imm[11:1] (11 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|----------------------|-------------|-----------------|
| 00000000            | 00101001110          | 00001       | 1101111         |

#### Binary Representation:
- **Binary:** `00000000000000000000 00001 1101111`
- **Hex:** `0005286f`

---

### 12. `li a0, 0`
*li (Load Immediate):* This instruction loads an immediate value into a register.

#### Instruction: `li a0, 0`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 0 (12 bits)
- **Destination Register (rd):** a0 (x10, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (0):** `000000000000`
- **rd (a0 = x10):** `01010`
- **funct3:** `000`
- **Opcode:** `0010011`

### Machine Code Breakdown for `li a0, 0`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000000000        | 00000        | 000             | 01010       | 0010011         |

#### Binary Representation:
- **Binary:** `000000000000 00000 000 01010 0010011`
- **Hex:** `00030393`

---

### 13. `ld ra, 8(sp)`
*ld (Load Doubleword):* This instruction loads a 64-bit value from memory into a register.

#### Instruction: `ld ra, 8(sp)`
- **Opcode:** 0000011 (7 bits)
- **Immediate:** 8 (12 bits)
- **Base Register (rs1):** sp (x2, 5 bits)
- **Destination Register (rd):** ra (x1, 5 bits)
- **Function (funct3):** 011 (3 bits)

#### Breakdown:
- **Immediate (8):** `000000000010`
- **rs1 (sp = x2):** `00010`
- **funct3:** `011`
- **rd (ra = x1):** `00001`
- **Opcode:** `0000011`

### Machine Code Breakdown for `ld ra, 8(sp)`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000000010        | 00010        | 011             | 00001       | 0000011         |

#### Binary Representation:
- **Binary:** `000000000010 00010 011 00001 0000011`
- **Hex:** `00028283`

---

### 14. `addi sp, sp, 16`
*addi (Add Immediate):* This instruction adds an immediate value to a register.

#### Instruction: `addi sp, sp, 16`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** 16 (12 bits)
- **Source Register (rs1):** sp (x2, 5 bits)
- **Destination Register (rd):** sp (x2, 5 bits)
- **Function (funct3):** 000 (3 bits)

#### Breakdown:
- **Immediate (16):** `000000010000`
- **rs1 (sp = x2):** `00010`
- **funct3:** `000`
- **rd (sp = x2):** `00010`
- **Opcode:** `0010011`

### Machine Code Breakdown for `addi sp, sp, 16`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 000000010000        | 00010        | 000             | 00010       | 0010011         |

#### Binary Representation:
- **Binary:** `000000010000 00010 000 00010 0010011`
- **Hex:** `00050393`

---

### 15. `ret`
*ret (Return from Function):* This instruction returns from a function by jumping to the address stored in `ra`.

#### Instruction: `ret`
- **Opcode:** 1100111 (7 bits)
- **Immediate:** 0 (12 bits, the value of `ra` is used directly)
- **Source Register (rs1):** ra (x1, 5 bits)

#### Breakdown:
- **Immediate (0):** `000000000000`
- **rs1 (ra = x1):** `00001`
- **funct3:** `000`
- **Opcode:** `1100111`

### Machine Code Breakdown for `ret`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-----------------|
| 000000000000        | 00001        | 000             | 1100111         |

#### Binary Representation:
- **Binary:** `000000000000 00001 000 1100111`
- **Hex:** `00008067`

