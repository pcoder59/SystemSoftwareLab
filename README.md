# System Software Lab

System Software Lab Programs

<h2> Contents </h2>

Basic System Software Lab Programs included in some college degree programs.

All are simple C programs that can be compiled with GCC.

<h3> CPU Scheduling Algorithms </h3>

cpu_scheduling folder.

fcfs.c        - First Come First Served Scheduling<br><br>
sjf.c         - Shortest Job First Scheduling<br><br>
round_robin.c - Round Robin Scheduling<br><br>
priority.c    - Priority Scheduling<br>

<h3> File Organization Techniques </h3>

file_allocation folder

single_level.c  - Single Level File Organization Technique<br><br>
twolevel.c      - Two Level File Organization Technique<br>

<h3> File Organization Strategies </h3>

memory_allocation folder

squential.c - Sequential File Organization Strategy<br><br>
linked.c    - Linked File Organization Strategy<br><br>
indexed.c   - Indexed File Organization Strategy<br>

<h3> Page Replacement Algorithms </h3>

page_replacement folder

fifo.c  - First Come First Out Page Replacement<br><br>
lru.c   - Least Recently Used Page Replacement<br>

<h3> Symbol Table Functions </h3>

symbol_table folder

symbol.c          - Symbol Table Functions<br><br>
symbol_hashing.c  - Symbol Table Functions with Hashing<br>

<h3> Assembler </h3>

assembler folder

pass1.c - Pass 1 of 2 Pass Assembler<br>
          Uses input_pass1.txt and optab_pass1.txt as input<br>
          Output output_pass1.txt and symtab_pass1.txt<br><br>
pass2.c - Pass 2 of 2 Pass Assembler<br>
          Uses input_pass2.txtm optab_pass2.txt and symtab_pass2.txt as input<br>
          Output output_pass2.txt and lising_pass2.txt<br>
          
<h3> Loader </h3>

loaders folder

absoluteloader.c  - Absolute Loader<br>
                    Uses absolute_input.txt as input<br><br>
relocating.c      - Relocating Loader<br>
                    Uses relocating_input.txt as input<br>
                    Output relocating_output.txt as output<br>

<h3> Macroprocessor </h3>

macroprocessor folder

pass1.c - Macroprocessor<br>
          Uses macroin.txt as input<br>
          Output macroout.txt, namtab.txt and deftab.txt as output<br>
          
# Instructions to Compile and Run

-Requirements : GCC installed on your system

-Files Required : The .c file of the program to run and any input .txt files

-Compiling

gcc <filename.c> : Produces a file a, a.exe on windows, a.out on linux

OR

gcc <filename.c> -o outputfile : Produces executable file named as outputfile
  
-Running

Execute a.exe or a.out or outputfile from command line

./a.exe or ./a.out or ./outputfile
