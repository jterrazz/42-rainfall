a binary file with elevated permissions can be found in the directory
./level0
Segmentation fault (core dumped)

./level0 test
No !

let's dissassemble with radare2 and see whats going on 
on host:
scp -P 4242 level0@localhost:/home/user/level0/level0 .

r2 level0
(in main) 
call sym.atoi
cmp eax, 0x1a7	; 423
jne 0x8048f58

a conditional jump after comparing atoi output to value 423
if we put as argument 423 the execution goes further

mov dword [esp], str.bin_sh	; "/bin/sh"
...
call sym.execv

This calls sh and waits for standard input
We can enter any command we like and have it be run with the binary's elevated permissions

./level0 423
$ cat /home/user/level1/.pass
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
