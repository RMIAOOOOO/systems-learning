# Computer Systems, A Programmer's Perspective

## A Tour of Computer Systems

- compilation system
  - source program -> (preprocessor)
  - modified source program -> (compiler)
  - assembly program -> (assembler)
  - object program (binary) -> (linker)
  - Executable

- Hardware organization
```
CPU (PC, register file, ALU, bus interface)
      ^
    (system bus)
      v
IO Bridge < (memory bus) > Main Memory
      ^
    (IO bus)
      v
IO Devices (usb, disk, etc.)
```

### Processor Read and Interpret Instructions Stored in Memory
  - Main Memory
    - Temporary store program and data when processor executes program
    - Contains DRAM (dynamic random access memory)

  - Processor
    - CPU
    - Program Counter (PC) points to a instructions in main memory
    - Instruction Set Architecture (ISA)
      - A set of simple instruction model processor process on
      - Operates around main memory, register file, ALU
    - Microarchitecture
      - How the process are implemented


### Caches
- Caches
  - Implemented with SRAM (Static Random Access Memory)
  - L1 Cache
    - on the processor chip
    - KB
  - L2 Cache
    - connect to processor by special bus
    - MB

### Storage Devices Form a Hierarchy
- MemoryHierarchy
  - L0: Regs
  - L1: L1 cache (SRAM)
  - L2: L2 cache (SRAM)
  - L3: L3 cache (SRAM)
  - L4: Main Memory (DRAM)
  - L5: Local Secondary Storage (Local disks)
  - L6: Remote secondary storage (distributed, web)

### The Operating System Manages the Hardware
  - Layer view of systems
    - Application Programs
    - OS
    - Proessor, Main Memory, IO Devices

- OS proivded abstraction
  - Process (Processor + Main memroy + IO Devices)
  - Virtual Memory      (Main memory + IO Devices)
  - Files                             (IO Devices)           

- Kernel
  - collection of code and data structure for system to manage process.

- Process
  - OS' abstraction of a running program
    - multicore processors
    - multi process (concurrent)
    - context switch for passing control between process
      - OS kernel handles transition
      - system call
    - threads
      - running in same process context, shares code and global data
      - easier to share data
      - runs faster when multicore avaialbe
    - process virtual address spaces

- Virtual memory
  - abstraction to process for exclusive use of main memory
  - Virtual address space: process has uniform view of memory
  - Process Virtual address spaces (start from end/high)
    - Kernel virtual memory
    - User stack     (function stact, created at runtime)
    -   (available space for shared library and stack)
    - memory mapped region for shared libraires (print)
    -   (available space for heap)
    - run time heap  (malloc)
    - RW data        (from executable)
    - RO code & data (from executable)
    - Program_start

- Files
  - sequence of bytes
  - All IO devices, all inputs and output

### System Communicate with Other Systems using Networks
- network can be viewd as IO devices.

### Important Themes

- Amdahl's law
  - T_new = (1 - alpha) * T_old + alpha * T_old / k
          = T_old * ((1 - alpha) + (alpha / k))
    - alpha = part of system speed up
    - k = performance improvement factor
    - S (speed up) = T_old / T_new = 1 / ((1 - alpha) + (alpha / k))

- Concurrency and Parallelism
  - Concepts
    - concurrency: system with multiple, simultaneous activities
    - parallelism: use concurrency to make system run faster
  - Thread Level Concurrency
    - Types
      - Uniprocessor
        - Based on process abstraction, mutiple program run at same time => concurrency
        - Threads: multiple control flow in a single process.
      - Multiprocessors
        - 1 OS on multiple processors
        - Types
          - Multi-core
            - Multiple CPUs (cores) on one chip
            - One CPU executes 1 control flows
              - each has individual L1 L2 caches
              - Shares L3 caches
          - Hyper-threaded (simultaneous multi-threading)
            - Multiple CPUs (cores) on one chip
            - One CPU executes multiple control flows
            - One CPU = n Program Counter + n set registers + 1 ALU
              - CPU decieds which thread to execute with low thread shift cost
        - Speeds up in two ways
          - No need to simulate concurrency with multiple process
          - If processs implement multiple threads, program need to exploits
  - Instruction Level Parallelism
    - Concept: one processor execute multiple instructions at one time
    - Example: 3 clock cycle per instruction -> 2~4 instructions in one cycle
    - Pipelineing: partition instructions into steps
    - SuperScalar processor.
  - Single Instruction, Multiple Data (SIMD) Parallelism
    - one instruction causes multiple operations in parallel

- Importance of Abstraction
  - Formulate API for set of functions to use code without delve into inner work
  - Computer system provided abstraction:
    - Virtual Machine: OS + Processor + Main Memory + IO Devices
    - Process:              Processor + Main Memory + IO Devices
    - ISA:                  Processor
    - Virtual Memory:                   Main Memory + IO Devices
    - Files:                                          IO Devices

### Summary
- Computer system = (HW + system SW) cooperates to run application programs
- Programs ASCII text => (translated by compiler and linkers) => binary exe files
- Processor read binary in main memory.
- CPU stores in hierarchy: registers > hw cache > DRAM > disk stroage
  - Programmer exploit to speedup
- OS kernel: intermediary between application and HW
  - provides abstractions: process, virtual memory, files

## Representing and Manipulating Information

### Information Storage
- 1 bytes = 8 bits = smallest addressable unit of memory
- Machine level program views memory as virtual memory (large array of bytes).
  - Virtual address space: set of all possible address identifying bytes
  - Actual implementation: DRAM + Flash memory + disk storage + special HW + OS
- Compiler and Runtime system partition memory space into manageable units
  - program objects
    - program data
    - instructions
    - control information

- Hexadecimal representation

- Data Sizes
  - 32 bit word size: virtual address space = 4GB
  - 64 bit word size: virtual address space = 16 exabytes
  - exact number of bytes for data types depends on how program is compiled
    - C different for 32bit and 64bit machine:
      - long/ unsigned long:    4 bytes vs 8 bytes
      - char* :                 4 byte vs 8 byte
    - Same:
      - char / unsigned char:   1 byte
      - short / unsigned short  2 byte
      - int / unsigned int:     4 byte
      - int32_t / uint32_t:     4 byte
      - int64_t / uint64_t:     8 byte
      - float:                  4 byte
      - double:                 8 byte

- Addressing and Byte ordering
  - Big endian: most significant at start: 0x01 0x23 0x45 0x67
  - Little endian: most significat at end: 0x67 0x45 0x23 0x01
   