###Objectives
+ Acquaint you with file I/O.
+ Get you more comfortable with data structures, hexadecimal, and pointers.
+ Introduce you to computer scientists across campus.
+ Help Mr. Boddy.

***
**whodunit.c**

The idea of this program is to reval Mr.Boddy’s drawing in order to find a clue to solve a mistery.
Stored in verdict.bmp should be a BMP in which Mr. Boddy’s drawing is no longer covered with noise.
You can execute the file with the command below
`./whodunit clue.bmp verdict.bmp`


**resize.c**

resize.c is a program that resizes 24-bit uncompressed BMPs by a factor of n.
The program accept exactly three command-line arguments, per the below usage, whereby the first (n) must be a positive integer less than or equal to 100, the second the name of the file to be resized, and the third the name of the resized version to be written.

`Usage: ./resize n infile outfile`

**recover.c**

A program that recover deleted .jpg photos.
