# (csci-5573) Operating System Principles
This repo is for materials pertaining to the University of Colorado at Denver's graduate level Operating System Principles class.
The class mainly consists of a project around kernels.
This project will focus around building an os from scratch using examples from Circle. The end goal is to compare execution on a simplified scheduler executing a simple set of programs with full kernels that have been optimized by my collegues. 
The metrics this will be based on will be
1) the speed at which it executes 
2) the temperature of the hardware

My collegues will be using os-bench for benchmarks, which means that I will need to write the following Functions:
   * create_thread
   * join_thread
   * create_process
   * wait_process
   * fork
   * execlp
   * waidpid
   * fopen
   * fwrite
   * fclose 
   * remove
   * malloc
   * free
</br>
or implement the benchmarks using the local apis.
For fun, I would also like to implement
   * GEMM utilizing vc4
    



### Hardware:
    Name: Raspberry PI Zero
    CPU: ARM1176JZF-S
    SoC: BCM2835
    ISA: ARMv6

### Firmware:
Firmware from April 2018

Resources:
[Bare Metal Project by David Welch](https://github.com/dwelch67/raspberrypi-zero) </br>
[Circle - Small Kernel](https://github.com/rsta2/circle) </br>
[crosstool-ng](https://crosstool-ng.github.io/docs/install/) </br>
[os-bench](https://github.com/mbitsnbites/osbench) </br>
[Benchmark games](https://benchmarksgame-team.pages.debian.net/benchmarksgame/fastest/c.html)</br>

References:

