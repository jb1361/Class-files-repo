IDENTIFICATION DIVISION.
PROGRAM-ID. LAB36.
ENVIRONMENT DIVISION.
INPUT-OUTPUT SECTION.                
FILE-CONTROL.
    SELECT inFile ASSIGN "lab36.in"   
        organization line sequential.
	SELECT outFile ASSIGN "lab36.out"   
        organization line sequential.
	SELECT workFile ASSIGN "lab36.work"   
        organization line sequential.

DATA DIVISION.

FILE SECTION.
    FD  inFile.
    01  studentInfoInput.      
		02 studentNameI		PIC A(20).
 		02 studentCreditsI 	PIC A(2).
		
	FD  outFile.
    01  studentInfo.      
		02 studentNameO		PIC A(20).
 		02 studentCreditsO 	PIC A(2).
		
	SD  workFile.
    01  studentInfoW.      
		02 studentNameW		PIC A(20).
 		02 studentCreditsW 	PIC A(2).
 
	
WORKING-STORAGE SECTION.
01 firstName PIC A(19).
01 lastName PIC A(19).


PROCEDURE DIVISION.
POne.

	SORT workFile ON DESCENDING KEY studentCreditsO
	USING inFile GIVING outFile.


	open input outFile
		PERFORM FOREVER
			READ outFile
				 AT END
				 EXIT PERFORM
				 END-READ
			
			DISPLAY studentInfo	
		END-PERFORM
	CLOSE outFile

STOP RUN.
