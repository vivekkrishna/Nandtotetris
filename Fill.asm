// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.
@status
M=0

@var3
M=0

@value
M=0

@arr
M=0

(LOOP)
@status
D=M

@statusdiff
M=D

@KBD
D=M

@status
M=D

@statusdiff
D=M-D

@LOOP
D;JEQ

//iF STATUS CHANGES set status value to be changed to

@KBD
D=M

@SETWHITE
D;JEQ

@SETBLACK
0;JEQ

(SETWHITE)
@value
M=0

@goto
0;JEQ

(SETBLACK)
@value
M=-1

//color screen
(goto)
@SCREEN
D=A

@arr
M=D

@i
M=0

(color)

//conditional
@8192
D=A

@i
D=D-M

@LOOP
D;JEQ

//screen(aar+i)=-1
@arr
D=M

@i
A=D+M
D=A

@var3
M=D

@value
D=M

@var3
A=M
M=D

@i
M=M+1

@color
0;JEQ




