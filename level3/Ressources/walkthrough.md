This time there is no possible buffer overflow because fgets() is used instead of gets() (there is a specified buffer size)
There is a /bin/sh call but it is skipped by a hardcoded numerical comparison. obj.m (which is 0) is compared to 0x40 (64)
We need to find a way to eithe avoid this comparison or make it true
The input is used for printf, this opens some vulnerabilities
%n format will write the number of printed characters at the address specified in the parameter
additionally we can use the 1$ modifier to specify which parameter to use
each parameter has 4bytes and they are read in succession in the stack, and because printf takes an undefined number of parameters, we can use the 1$ modifier to go as high up as we want in the stack
We can write the address of obj.m in our buffer, pad it to have 64 characters, include %n format and specify a parameter number that will point to the address of obj.m in our buffer
This will write 64, make the comparison true, and run /bin/sh with the binary elevated permissions

address of obj.m + padding to have 64 characters + 4th arg on stack is the buffer
python -c "print '\x08\x04\x98\x8c'[::-1] + 60 * 'a' + '%4\$n'" > /tmp/inj3
cat /tmp/inj3 - | ./level3

cat /home/user/level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
