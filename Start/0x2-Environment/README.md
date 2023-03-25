<h1 align="center">
  Control your environment
  <br>
  <a href="https://github.com/smadi0x86/CSC-RedOps"><img src="https://i.pinimg.com/originals/2f/35/42/2f35421b4bdaead24c9b8d1f7f228038.gif" alt="linux.logo"></a>
  <br>
  </h1>
 
 <h3 align="center">Your environment is any linux distribution you will be using in offensive operations</h3>
 
<p align="center">
  <a href="">
   <img src=https://img.shields.io/badge/Red-Team-darkred>
   <img src=https://img.shields.io/badge/Environment-Control-blue>
  </a>
  </p>
  
## Pick your distribution
```
Picking your linux distro is essential to ensure that you're comfortable and doing your attacks with full efficiency.
```
```
There are many distros you can pick from, some popular ones are:
```
- [***Kali Linux***](https://www.kali.org/get-kali/)
- [***ParrotOS***](https://www.parrotsec.org/download/)
- [***BlackArch***](https://blackarch.org/downloads.html)

```
We will not go over installing them, but here are videos that explains that:
```
- [***Installing Kali***](https://www.youtube.com/watch?v=3Iq7wHsNEXw)
- [***Installing Parrot***](https://www.youtube.com/watch?v=9z-_h7aChDI)
- [***Installing BlackArch***](https://www.youtube.com/watch?v=T0MBlWLZvpE)

```
I will be explaining terminal commands that is handy for offensive ops, meanwhile I'm assuming you know basics of terminal usage such as: cd, cat, grep, chmod etc...
```
```
Note: These commands are tested on Parrot and Kali, BlackArch terminal is slightly different, it uses pacman instead of apt for package managing for example.
```
## [Fire up your terminal](https://github.com/smadi0x86/CSC-RedOps/tree/main/Start/0x2-Environment/commands)
```
Let's start exploring more commands & utilities
```
### 1) Comparing Files:
```
Comparing files may seem irrelevant, but its so useful specially when you do multiple scans for same target and wanna check if there's duplication of results.
```
- ***The "comm" command displays comparison between two text files the 1st line is unique to scan-a & 2nd line is unique to scan-b & third is the same in both files:***
```bash
$~ comm scan-a.txt scan-b.txt
```

### 2) Managing Processes:
```
Linux manages multi tasks using processes + every process has a unique id, the terminal introduces jobs which suspend execution of processes or resume execution for later time.
```
- ***a) "bg"***
- ***Using an "&" at the end of a command to send it to background, we will send a 500 icmp echo request to ourselves and save it to a file then background it.***
- ***If we remove the "&" and run it again it will run in foreground and you can quit it by pressing CTRL+c or suspend it with CTRL+z.***
- ***If suspended we can return it with "bg" command***
```bash
$~ ping -c 500 localhost > ping_icmp.txt &
```

- ***b) "jobs" and "fg"***

- ***To check the status of our previous icmp echo request we need to use "jobs" and "fg"***
- ***This will list all jobs status that are running, suspended or stopped.***
```bash
$~ jobs
```
- ***This will return the process to foreground and you can edit or execute it again, %1 is just an example you can put any process number that you have 1,2,3,4 etc...***
```bash
$~ fg %1
```

- ***c) "ps" and "kill"***
- ***Unlike jobs command, ps lists all system processes not only for terminal session, It is useful after compromise to check software running on victim machine.***
- ***This gives more information and clues for further access.***
- ***This shows all processes, e: select all processes f: full format.***
```bash
$~ ps -ef
```
- ***This looks for the specific process name you give to it, such as notepad, firefox etc...***
```bash
$~ ps -fC notepad
```
- ***To terminate/kill any process, the pid is the process id for example: 1805, 950 etc... which is shown for every process when running the "ps -ef" command.***
```bash
$~ kill 1805
```

### 3) Downloading Files
