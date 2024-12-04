### Please remember in interview

#### Routine
1. Ask constraint
2. Variable name
3. Think brute force first and say its time & space complexity
4. Ask the interviewer if I can start coding
5. Talking when still thinking (they may give more hints)
6. Add title to the notes like `Problem Description`, `Intuition`, `Solution` and `Implementation`
7. Think more case and edge case
8. Test your algorithm with example

#### C++
* Remember to add `std::`
* You may use `static`
* `const + pass by reference`: Ensuring Parameters Are Not Modified and Avoiding Unnecessary Copies

GO for it!






Here is an overview of the key concepts you should understand:

### **1. Processes and Threads**
- **Processes**: Independent units that execute an application; they have separate memory spaces and system resources.
- **Threads**: Lightweight sub-units of processes that share resources like memory; multiple threads within a process can execute concurrently.

Thread is a software concept that map to a hardware functional unit

A **thread** is indeed a software construct, but it also has a direct relationship with hardware functionality. Specifically:

- **Threads** represent units of execution within a process that can be scheduled independently by the operating system. They exist in software as sequences of programmed instructions.
- In modern multi-core CPUs, threads can map to **hardware execution units** known as cores. Each core can execute a thread, allowing true parallel execution.
- Advanced CPUs can support **Simultaneous Multithreading (SMT)**, like Intel's Hyper-Threading, where a single core executes multiple threads, improving resource utilization.

Threads are thus closely tied to how hardware manages execution, and they directly leverage the hardware's capabilities to achieve concurrency and parallelism.
### **2. Concurrency Issues**
- **Race Conditions**: Occur when multiple threads access shared data simultaneously, leading to unpredictable outcomes.
- **Data Races**: When two threads write/read shared data concurrently without proper synchronization.

### **3. Locks, Mutexes, Semaphores, and Monitors**
- **Locks and Mutexes**: Mechanisms to ensure only one thread can access a shared resource at a time, preventing race conditions.
- **Semaphores**: Signaling mechanisms to control access to a pool of resources, with counting (general) and binary semaphores.
- **Monitors**: High-level abstraction for synchronizing access to shared resources, often used in programming languages to manage concurrent access.

### **4. Deadlock, Livelock, and Avoidance**
- **Deadlock**: A state where two or more processes are waiting indefinitely for resources held by each other.
- **Livelock**: Similar to deadlock, but threads keep changing states without progressing towards completion.
- **Avoidance**: Techniques include resource ordering, avoiding circular waits, or using protocols like Banker's algorithm.

### **5. Resources Needed by Processes and Threads**
- **Processes**: Memory, CPU time, file descriptors, and other system resources.
- **Threads**: Share process resources, like memory and open files, but each thread has its own registers and stack.

### **6. Context Switching**
- **Definition**: The process of saving the state of a running process/thread and loading the state of another, enabling multitasking.
- **Initiation**: Initiated by the operating system through software interrupts, system calls, or hardware timers.

### **7. Scheduling**
- **Scheduling**: Determines which process/thread runs at any given time.
- **Common Algorithms**: Round-robin, priority-based, shortest job first, and multilevel queue scheduling.

### **8. Modern Concurrency Constructs**
- With multi-core systems, concurrency is crucial for optimal utilization:
  - **Atomic Operations**: Simplifies synchronization by ensuring indivisible operations.
  - **Futures and Promises**: Abstractions that manage results of asynchronous tasks.
  - **Thread Pools**: Efficient management of concurrent workloads by reusing worker threads.
  - **Fork/Join Framework**: Splits tasks into smaller pieces, runs them in parallel, and merges results, suitable for divide-and-conquer algorithms.

### **Avoiding Common Issues**
- **Deadlock Prevention**: Break one of the four Coffman conditions (mutual exclusion, hold-and-wait, no preemption, circular wait).
- **Concurrency Control**: Using locks or high-level concurrency constructs to protect shared data and avoid race conditions.

Let me know if you need more specific information on any of these topics!