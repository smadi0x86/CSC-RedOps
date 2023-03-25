<h1 align="center">
  Control your environment
  <br>
  <a href="https://github.com/smadi0x86/CSC-RedOps"><img src="https://i.pinimg.com/originals/2f/35/42/2f35421b4bdaead24c9b8d1f7f228038.gif" alt="linux.logo"></a>
  <br>
  </h1>
 
 <h3 align="center">Your environment is any linux distro you will be using in offensive operations</h3>
 
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
- ***"comm"***
- ***The comm command displays comparison between two text files the 1st line is unique to scan-a & 2nd line is unique to scan-b & third is the same in both files:***
```bash
comm scan-a.txt scan-b.txt
```
