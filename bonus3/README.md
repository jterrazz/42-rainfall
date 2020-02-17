# Bonus3

`su bonus3 #71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587`

## Steps

This program prepares two buffers, opens `.pass` with `fopen()`and copies the contents into each buffer with `fread()`.  
Our use of `gdb` and `ltrace` is limited for this execise because of the early `fopen()` (gdb and ltrace have user permissions so the process is stopped when it tries to open the .pass owned by user end).

It takes one parameter that it will use for two things:
- converting it to an int, it will place a `\0` in the first buffer at its offset. 
- it will be compared to the contents of the first buffer and if contents are found to be the same, `/bin/sh` will be run.

If we input an empty string as first argument, it will replace the first character in the buffer with a `\0`, and since `strcmp` stops at `\0` both string will be considered identical.

```bash
./bonus3 ""

cat /home/user/end/.pass
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c
```
