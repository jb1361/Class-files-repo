IDENTIFICATION DIVISION.
PROGRAM-ID.    L_10.
ENVIRONMENT DIVISION.
INPUT-OUTPUT SECTION.                
FILE-CONTROL.
    SELECT in-FILE ASSIGN "L10.in"   
        organization line sequential.

    SELECT out-FILE ASSIGN "L10.out"   
        organization line sequential.

DATA DIVISION.

FILE SECTION.
    FD  in-file.
    01  in-line.      
	02 line-number	PIC 9(3).
 	02 line-name PIC A(15).

    FD  out-file.
    01  out-line.
	02 line-name	PIC A(15).
	02 line-number	PIC 9(3).


PROCEDURE DIVISION.
    open input in-file
    open output out-file
    PERFORM FOREVER
        READ in-file
             AT END
             EXIT PERFORM
             END-READ
	display line-name in in-line "is at " line-number in in-line
	MOVE CORRESPONDING in-line to out-line
        WRITE out-line
        END-PERFORM
     CLOSE in-file, out-file

    stop run
    .
