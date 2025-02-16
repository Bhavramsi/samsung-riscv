# Samsung RISC-V
The program focuses on the RISC-V architecture and utilizes open-source tools to educate individuals about VLSI chip design and RISC-V. The program is led by Kunal Ghosh Sir.


# ESSENTAIL DETAILS
NAME: BHAVANA RAMAKRISHNA    
COLLEGE: DAYANANDA SAGAR COLLEGE OF ENGINEERING      
EMAIL ID: [bhavramki@gmail.com](bhavramki@gmail.com)      
GITHUB USERNAME :[Bhavramsi](https://github.com/Bhavramsi)         
LINKEDIN PROFILE :[Bhavana Ramakrishna](https://www.linkedin.com/in/bhavana-ramakrishna-1520922ba?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)        

<!-- Task 1 -->
<details>
<p><summary>
<b>Task 1:</b> Task is to install RISC-V toolchain using VDI link provided,Compiling the C code and Using RISV options O1 and Ofast
</summary></p>
<b>1. Install Ubuntu 18.04 LTS(beaver) on Oracle Virtual Machine Box and open VDI file provided</b>
<br><br>

<br><br>
<b>2. Compiling C code </b>
img=<"https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%201/c%20code%20complied%20using%20gcc%20complier.png">
<br><br>
<pre><code>cd
gedit sum1ton.c
gcc sum1ton.c
./a.out</code></pre>
<br>

<br><br>

<br><br>
<b>3. Object Dump and O1 & Ofast Output</b>
<img src="https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%201/c%20code%20complied%20using%20gcc%20complier.png">

<img src="https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%201/obj%20dump%20using%20-O1.png">


<br><br>
<pre><code>cat sum1ton.c
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
ls -ltr sum1ton.o
</code></pre>
<br>

<br><br>
<pre><code>riscv64-unknown-elf-objdump -d sum1ton.o |less </code></pre>


<br><br>
<b>For O1: The number of instructions were 15.</b><br><br>
<img src="https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%201/obj%20dump%20using%20-O1.png"   alt=-O1 output>
<br><br>
<pre><code>riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c</code></pre>
<br>
<b>For Ofast: the number of instructions were 12.</b><br><br>
<img src= "https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%201/obj%20dump%20using%20-Ofast.png" alt=-Ofast output>
<br><br>
</details>
<hr>
<!-- End of Task 1-->
<!-- Task 2 -->
<details>
<p><summary>
<b>Task 2:</b> Run and observe the performance of SPIKE Simulation and  under the -O1 and -Ofast Compiler optimization flags
</summary></p>

			
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
<br><br>
</details>  
</details>
<hr>
<!-- End of Task 2-->


<!-- Task 3 -->
<details>
<p><summary>
<b>Task 3:</b> 15 unique instructions are determined in the riscv-objdump of code,As it gives exact 32-bit instruction code in their respective instruction type formats.
</summary></p> 
  ## Introduction:
RISC-V (Reduced Instruction Set Computer - V) is an open standard instruction set architecture (ISA) based on established reduced instruction set computing principles. Unlike proprietary ISAs, RISC-V is free and open, enabling unrestricted academic and commercial use without licensing fees. This has made RISC-V an attractive option for research, education, and industry applications, fostering innovation and development across various domains.
### Importance of Understanding Instruction Formats
Understanding instruction formats is crucial for several reasons:
1. **Instruction Decoding**: Knowing the structure of different instruction formats enables the correct decoding of instructions, which is essential for the CPU to execute them correctly.
2. **Pipeline Design**: Instruction formats impact the design of the CPU pipeline. Proper handling of instruction formats ensures efficient instruction fetch, decode, execution, memory access, and write-back stages.
3. **Compiler Design**: Compilers generate machine code that adheres to the ISA's instruction formats. A deep understanding of these formats helps in optimizing code generation, leading to better performance and efficiency.
4. **Debugging and Verification**: Understanding instruction formats aids in debugging and verifying hardware and software. It helps in identifying issues related to incorrect instruction execution or pipeline hazards.
5. **Extensibility and Customization**: RISC-V's modular and extensible nature allows for custom extensions. Understanding the base instruction formats is essential for creating and integrating custom instructions tailored to specific applications or performance needs.

### Register Naming in RISC-V
RISC-V has 32 registers, named `x0` through `x31`. However, these registers are often assigned more descriptive names based on their typical usage:

- **x0 (zero)**: This register always holds the constant value 0.
- **x1 (ra)**: Return Address register, which stores the return address after a function call.
- **x2 (sp)**: Stack Pointer register, pointing to the top of the stack in memory.
- **x3 (gp)**: Global Pointer register.
- **x4 (tp)**: Thread Pointer register.

### Saved, Temporary, and Argument Registers
The remaining registers are divided into saved, temporary, and argument categories:

- **Saved Registers (s0-s11)**: These registers (x8, x9, x18-x27) store variables that need to be preserved across function calls.
- **Temporary Registers (t0-t6)**: These registers are used for intermediate calculations and temporary data storage.
- **Argument Registers (a0-a7)**: These registers (x10-x17) are used to pass arguments to functions and store return values.

  ### "Understanding I-Type, S-Type, B-Type, U-Type, and J-Type Instructions"

![image](https://github.com/user-attachments/assets/af936f03-ded7-4d6a-9e4b-38cf37695620)
### ABI : Application Binary Interface
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

# 15 UNIQUE RISC-V INSTRUCTIONS DECODING (OBJDUMP USIJNG -O1 FORMAT)
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

 </details>
</details>
<hr>
<!-- end of Task 3 -->

<!-- Task 4 -->
<details>
<p><summary>
<b>Task 4: </b>By using RISC-V Core: Verilog netlist and Testbench, perform an experiment of Functional Simulation using GTKWave and Observe the waveforms.
</summary></p>


## OBJECTIVE :  Perform a functional simulation of the given RISC-V Core Verilog netlist and testbench.

## Steps to perform functional simulation for RISC-V :
1. Using suitable commands install the iverilog and GTKWave in ubuntu.
2. Compile the RISC-V Core: Verilog netlist and Testbench.
3. Observe the waveform output in GTKWave window.

### Installing iverilog and GTKWave in Ubuntu :
```
sudo apt install iverilog gtkwave
```

### Simulate and run the verilog code :
```
iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
./iiitb_rv32i
gtkwave iiitb_rv32i.vcd
```


# GTKWAVE + TERMINAL COMMANDS
![GTKWAKE1](https://github.com/user-attachments/assets/f8aad947-7acf-4f28-b6f8-ef2dfc16e728)

# VERILOG COMMANDS 
![VERILOG COMMANDS](https://github.com/user-attachments/assets/da2220da-1da0-41e6-aebe-638947aa85e6)



# Ouput Waveforms :
The output waveforms showing the instructions performed in a 5-stage pipelined architecture

Instruction 1:
```
add r6,r1,r2
```
![add r6,r1,r2](https://github.com/user-attachments/assets/f24d7d3e-bd17-4097-a435-b1241f4c8332)

Instruction 2:
```
sub r7,r1,r2
```
![sub r7,r1,r2](https://github.com/user-attachments/assets/2b917eab-f62f-4f03-a3d2-9964bf382167)

Instruction 3:
```
and r8,r1,r3
```
![and r8,r1,r3](https://github.com/user-attachments/assets/d72c3bb0-3563-4c1a-99be-620095f11414)

Instruction 4:
```
or r9,r2,r5
```
![or r9,r2,r5](https://github.com/user-attachments/assets/6ba02ed0-73d1-4239-b573-d718d80972da)

Instruction 5:
```
xor r10,r1,r4
```
![xor r10,r1,r4](https://github.com/user-attachments/assets/e800f562-caf4-4179-b8e1-3231e7d461f2)

Instruction 6:
```
slt r11,r2,r4
```
![slt r11,r2,r4](https://github.com/user-attachments/assets/c9b46762-3317-402c-a64e-1d95aea18fe5)

Instruction 7:
```
addi r12,r4,5
```

![addi r12,r4,5](https://github.com/user-attachments/assets/db6673c6-c528-488d-9071-d1075794257f)

Instruction 8:
```
sw r3,r1,2.
```
![sw r3,r1,2](https://github.com/user-attachments/assets/93fd5389-019d-4e12-ac0f-e5e388fe2781)

Instruction 9:
```
lw r13,r1,2.
```
![lw r13,r1,2](https://github.com/user-attachments/assets/eb4edbf2-20a9-4eec-a8bb-c86dd35ce503)

Instruction 10:
```
beq r0,r0,15
```
![beq r0,r0,15](https://github.com/user-attachments/assets/9dcb5c6a-cc70-4d64-8078-875959c353a1)

Instruction 11:
```
add r14,r2,r2
```
![add r14,r2,r2](https://github.com/user-attachments/assets/58cd9cce-b4d5-4cb7-afa6-bdf25f5996a6)

Instruction 12:
```
bne r0,r1,20
```
![bne r0,r1,20](https://github.com/user-attachments/assets/7b26f8fb-c770-46e5-ae84-655889e49622)

Instruction 13:
```
addi r12,r4,5.
```

![addi r12,r4,5_1](https://github.com/user-attachments/assets/ee2e71cd-ce4f-4505-8c5e-4ec59154ad9e)

Instruction 14:
```
sll r15,r1,r2(2
```

![sll r15,r1,r2(2)](https://github.com/user-attachments/assets/e2fd47ca-edf3-4f51-a854-23ee90dc97b4)
<br><br>
</details>
</details>
<hr>   
<!-- end of Task 4 -->
		<!-- Task 5 -->
<details>
<p><summary>
<b>Task 5: </b> Task is to implement any digital circuits using VSDSquadron Mini and check whether the building and uploading of C program file on RISCV processor works </summary>
<h2>Implementation of GRAY TO BINARY CONVERTER using VSDSquadron Mini</h2>

<h3><b>Overview</b></h3>
<p>This project involves the implementation of GRAY TO BINARY CONVERTER circuit using VSDSquadron Mini, a RISCV based SoC development kit.

This project demonstrates the practical application of digital logic and RISC-V architecture in executing operations, reflecting the process of reading and writing of binary data through GPIO pins, implementing the operation of of GRAY TO BINARY CONVERTER through digital logic gates which is simulated using PlatformIO IDEand thus displaying the outputs using LEDs. </p> 

## Components Required to Build Binary to Gray Code converter
VSDSquadron Mini
LEDs (for output indication)
Buttons (for binary input)
Breadboard
Jumper Wires
PlatformIO
VS Code for software development

## Circuit Connection for GRAYto BINARY Code converter
1. LED’s Connection
LED1 (Gray Code Bit 2) connected to GPIO Pin_0
LED2 (Gray Code Bit 1) connected to GPIO Pin_2
LED3 (Gray Code Bit 0) connected to GPIO Pin_3
2. Buttons Connection
Button1 (Binary Input Bit 2) connected to GPIO Pin_4
Button2 (Binary Input Bit 1) connected to GPIO Pin_5
Button3 (Binary Input Bit 0) connected to GPIO Pin_6

## PIN DESCRIPTION ACCORDING TO Header File ch32v00x.h
PD0 => GPIO_Pin_0
PD1 => GPIO_Pin_1
PD2 => GPIO_Pin_2
PD3 => GPIO_Pin_3
PD4 => GPIO_Pin_4
PD5 => GPIO_Pin_5
PD6 => GPIO_Pin_6
PD7 => GPIO_Pin_7

<img src=https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%205/3%20bit%20gray_to_binary.png><br><br>


## HARDWARE CONNECTIONS 

<img src="https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%205/3%20bit%20gray%20to%20binary%20pin%20diagram.png">



A 3-bit Gray to Binary code converter follows a specific logic where each binary bit is derived from the corresponding Gray code bit. 

### Truth Table for 3-bit Gray to Binary Conversion

| Gray Code (G2 G1 G0) | Binary Code (B2 B1 B0) |
|----------------------|----------------------|
| 000  | 000  |
| 001  | 001  |
| 011  | 010  |
| 010  | 011  |
| 110  | 100  |
| 111  | 101  |
| 101  | 110  |
| 100  | 111  |

### **Conversion Formula:**
- **B2** = **G2**
- **B1** = **B2 ⊕ G1**
- **B0** = **B1 ⊕ G0**



## GRAY TO BINARY CODE CONVERTER 
Include header files 
```
#include <ch32v00x.h>
#include <debug.h>
```

define xor 
```
int xor(int bit1,int bit2)
{ int xor= bit1^bit2;
return xor
  }
  ```
Pin configuration 
```
void GPIO_Config(void)
{ GPIO_InitTypeDef GPIO_InitStructure = {0}; //structure variable used for the GPIO configuration
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); // to Enable the clock for Port D
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 ; // Defines which Pin to configure
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Defines Input Type
GPIO_Init(GPIOD, &GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3 ; // Defines which Pin to configure
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Defines Output Type
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Defines speed
GPIO_Init(GPIOD, &GPIO_InitStructure);
}
```

Main function

```
  int main(void)
{
uint8_t b0, b1, b2, g0 , g1, g2 = 0;
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
SystemCoreClockUpdate();
Delay_Init();
GPIO_Config();
while(1)
{
  g0=GPIO_ReadInputDataBit(GPIOD,GIPO_Pin_4);
  g1=GPIO_ReadInputDataBit(GPIOD,GIPO_Pin_5);
  g2=GPIO_ReadInputDataBit(GPIOD,GIPO_Pin_6);

  b2=xor(0,g2);
  b1=xor(g1,b2);
  b0=xor(g0,b1);
  
 if(b0==0)
 {GPIO_WriteBit(GPIOD, GPIO_Pin_0, RESET);}
 else
 {{GPIO_WriteBit(GPIOD, GPIO_Pin_0, SET);}
if(b1==0)
  {GPIO_WriteBit(GPIOD, GPIO_Pin_2, RESET);}
  else
  {GPIO_WriteBit(GPIOD, GPIO_Pin_2, SET);}
  if(b2==0)
    {GPIO_WriteBit(GPIOD, GPIO_Pin_3, RESET);}
  else
    {GPIO_WriteBit(GPIOD, GPIO_Pin_0, SET);}
}
}
```

 <br><br>
</details>
</details>
<hr>   
</summary></p>
<!-- end of Task 5 -->

<!-- Task 6 -->
<details>
<p><summary>
<b>Task 6: </b>  Application Demo
	
https://github.com/Bhavramsi/samsung-riscv/blob/main/TASK%206/3%20bit%20gray%20to%20binary.mp4







