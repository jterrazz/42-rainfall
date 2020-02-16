# Level 8
```bash
su level8 #5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```

## Progress
We see that the binary analyses commands received in the `gets()`. Compared strings in the code are: `login`, `auth `, `service`, `reset`.

If we do `auth `, it will copy the str in a new memory and set the next  bytes to `0`. 

To get the call to `cat /home/uesr/level9/.pass`, we want to set the buffer `auth` + `0x20` to something different than 0. For than we can use the command `service` which will do another malloc with its `strdup`.

So we do:
`auth `
`servic`
`servic`
`login`

```bash
$ cat /home/user/level9/.pass
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```
