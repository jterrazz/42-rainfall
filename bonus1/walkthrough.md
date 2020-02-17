# Bonus1

We can see a call to `/bin/sh` but some conditional jumps prevent its execution 
If after passing it to `atoi()` the first argument is superior or equal to 9, the process will exit 
Otherwise it will use that number * 4 as a size parameter to `memcpy()` `argv[2]` into a buffer 

The last conditional jump compares a dword value placed 40 bytes after the start of the buffer  
This means we need the `memcpy()` size to reach at least 44 bytes in length

The jle instruction treats the input as signed, this means we can enter a negative signed integer that will equate 44 after being multiplied by 4
```
./bonus1 -1073741813 $(python -c "print 'A' * 40 + 'FLOW")
cat /home/user/bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```
