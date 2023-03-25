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
## Fire up your terminal
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
```
Downloading Files is the most powerful commands used, most malware authors use these commands to perform different techniques for delivering and execution of their malware on the target system.
```
- ***"wget"***
- ***This command can be used to download http and ftp protocols, it can be used with -O flag to save to a file with different name on the local machine.***
```bash
$~ wget -O wget_example.md https://https://github.com/smadi0x86/CSC-RedOps/edit/main/Start/0x2-Environment/README.md
```
- ***curl***
- ***To download or upload files and build complex requests, similar to wget you can use -o to save to a file with different name on local machine.***
```bash
$~ curl -o curl_example.md https://https://github.com/smadi0x86/CSC-RedOps/edit/main/Start/0x2-Environment/README.md
```
- ***axel***
- ***It's a download accelerator that transfer a file from http or ftp server through multiple connections, -n specifies the number of multiple connections used, -a: more concise progress indicator and -o for a different file name save on local machine.***
```bash
$~ axel -a -n 10 -o axel_example.md https://https://github.com/smadi0x86/CSC-RedOps/edit/main/Start/0x2-Environment/README.md
```

### Environment Variables
```
When opening a terminal window, a new bash process that has its own environment variables is initialized, these variables are form of global storage for various setting inherited by any applications that run during this terminal session, one of most common referenced environment variables are:
```
```bash
$~ echo $PATH
$~ echo $USER
$~ echo $PWD
$~ echo $HOME
```
- ***We can assign our own env variables, for example if we want to scan a target and don't want to type his IP several times we can do:***
- ***Then call this variable with a "$" as shown below.***
- ***If you define the variable without the "export" command you can use it in other terminal instances, its not tied only to the same terminal.***
- ***You can type "env" command in your terminal to view all environment variables.***
```bash
$~ export IP=192.168.1.1
$~ ping $IP
$~ var="Without export command"
$~ echo $var
$~ env
```

### Systemctl
```
The systemctl command manages both system and service configurations, enabling you to manage the OS and control the status of services.
```
- ***Common systemctl commands***
- ***The enable command is to launch a daemon background service that is launched with system boot, to keep a service running when restarting the system.***
- ***Starting and Stopping Services, I'll take ftp as a service example:***
```bash
$~ sudo systemctl start ftp
$~ sudo systemctl stop ftp
$~ sudo systemctl restart ftp
$~ sudo systemctl enable ftp
$~ $~ sudo systemctl disable ftp
$~ sudo systemctl status ftp
```

### Files to look for:
```
Here are some common files you need to watch for and this is just a short list off the top of my head:
```
- ***.rhosts (allows remote logins)***
- ***/etc/passwd (contains the user names)***
- ***/etc/shadow (contains the hashed passwords)***
- ***inittab (initialization sequence)***
- ***crontab files (scheduler)***
- ***inetd files (which can be used to start other network daemons)***
- ***/etc/init.d (all the startup scripts)***
- ***/var/log/wtmp (login log files)***
- ***/tmp***

### [Check More Commands Here](https://securityonline.info/some-useful-linux-command-for-your-penetration-testinglinux-command/) + use the --help on every command to check additional functionalities
