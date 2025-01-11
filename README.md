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
