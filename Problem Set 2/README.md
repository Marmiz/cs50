### Objectives:
+ Become better acquainted with functions and libraries.
+ Dabble in cryptography.

***
**Cesar.c**

A program that encrypts messages using Caesar’s cipher `ci = (pi + k) % 26`.
The program accept a single command-line argument: a non-negative integer.
If the program return a value of *1* means an error has occurred.
Otherwise, the program prompt the user for a string of plaintext and then output 
that text with each alphabetical character "rotated" by k positions; non-alphabetical characters are outputted unchanged.

**Vigenere.c**

Vigenere.c is a program that encrypts messages using Vigenère’s cipher: `ci = (pi + kj) % 26`.
This program accept a single command-line argument: a keyword, k, composed entirely of alphabetical characters.
If executed without any command-line arguments, with more than one command-line argument, or with one command-line argument that contains
any non-alphabetical character, the program exit immediately, with main returning *1*.
Otherwise, the program proceed to prompt the user for a string of plaintext, p, which it must then encrypt according to Vigenère’s cipher
with k, ultimately printing the result and exiting.
