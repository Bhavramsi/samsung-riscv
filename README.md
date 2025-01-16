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
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rvi -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum_1ton.o | less
```


Debugging the Assembly Language Program of sum1ton.c                   
```
riscv64-unknown-elf-objdump -d sum_1ton.o | less 
spike -d pk sum_1ton.o
```

Open the debugger in another terminal by using the following command.         
```
spike -d pk sum_1ton.o
```
We can follow similar steps for debugging -O1 format after finding the object dump of -O1 

Open the Objdump of code by using the following command                   
```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rvi -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum_1ton.o | less
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
### Machine Code for `addi sp, sp, -128`
![image](https://github.com/user-attachments/assets/f0e7f858-5ca8-46f6-b42f-40133048e731)
1. #### Instruction: `addi sp, sp, -128`
- **Opcode:** 0010011 (7 bits)
- **Immediate:** -128 (12 bits, two's complement)
- **Source Register (rs1):** sp (x2, 5 bits)
- **Destination Register (rd):** sp (x2, 5 bits)
- **Function (funct3):** 000 (3 bits)
#### Breakdown:
- **Immediate (-128):** `111111110000`
- **rs1 (sp = x2):** `00010`
- **funct3:** `000`
- **rd (sp = x2):** `00010`
- **Opcode:** `0010011`
### Machine Code Breakdown for `addi sp, sp, -128`
| Immediate (12 bits) | rs1 (5 bits) | funct3 (3 bits) | rd (5 bits) | Opcode (7 bits) |
|---------------------|--------------|-----------------|-------------|-----------------|
| 111111110000        | 00010        | 000             | 00010       | 0010011         |
![image](https://github.com/user-attachments/assets/51869d32-1bc8-45b6-b559-9682c34ed699)
2. ### `sd s0, 112(sp)`
*sd (Store Doubleword):* This instruction stores a 64-bit value from a source register into memory.
```
