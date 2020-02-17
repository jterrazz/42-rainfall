# Level 8
```bash
su level8 #5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```

## Steps

This binary runs an `execv("cat /home/user/level9/.pass")` after a series of conditional jumps.
We will have to dissassemble it to understand what conditions must be met to reach it.

We see that the binary compares the commands received in `gets()` to `login`, `auth `, `service` and `reset`.

- If we do `auth `, it will copy the `str` in a new memory and set the next bytes to `0`. 
- To trigger the call to `cat /home/user/level9/.pass`, we want to set the buffer `auth` + `0x20` to something different than 0. For the test instructions to be true, we can use the command `service` which will do another malloc with its `strdup`.

So we do:
- `auth `
- `service`
- `service`
- `login`

```bash
$ cat /home/user/level9/.pass
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```
