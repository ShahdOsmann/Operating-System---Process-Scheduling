# CPU Scheduling Program

Program simulates the CPU scheduling process using various scheduling algorithms.

## Process Scheduling

Process Scheduling is the process of the process manager handling the removal of an active process from the CPU and selecting another process based on a specific strategy.
 
## Supported Scheduling Algorithms

- **First Come First Serve (FCFS)**
  - Processes are executed in the order they arrive, resembling a first-come, first-served basis.

- **Shortest Job First (SJF)**
  - Processes with the shortest burst time are given priority for execution to minimize waiting time.

- **Longest Job First (LJF)**
  - Processes with the longest burst time are executed first, suitable for scenarios where long processes are prioritized.

- **Priority (Non-preemptive)**
  - Processes are executed based on their priority values. Higher priority processes are given precedence over lower priority ones.

- **Priority (Preemptive)**
  - Similar to non-preemptive priority scheduling, but with the ability to interrupt lower priority processes when higher priority ones become available.

- **Shortest Remaining Time First (SRTF)**
  - A preemptive version of SJF, where the CPU is allocated to the process with the shortest remaining execution time.

- **Longest Remaining Time First (LRTF)**
  - Processes with the longest remaining execution time are given priority, suitable for scenarios where long processes need to be completed first.

- **Round Robin**
  - Each process is given a fixed time slice to execute in a cyclic manner, ensuring fairness and preventing starvation.


