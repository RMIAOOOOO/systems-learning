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