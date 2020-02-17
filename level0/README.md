# Level 0
```bash
su level0 #level0
```

## Steps

The binary compares `argv[1]` with the number **423** at the address `0x08048ed9`.

By passing `423` as the firt argument, the program calls `setuid`, `getuid` and will start a new `/bin/sh` process.

```bash
cat /home/user/level1/.pass
# 1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```
