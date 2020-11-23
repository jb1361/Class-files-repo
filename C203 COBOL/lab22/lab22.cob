IDENTIFICATION DIVISION.
PROGRAM-ID. LAB22.
ENVIRONMENT DIVISION.
INPUT-OUTPUT SECTION.                
FILE-CONTROL.
    SELECT inFile ASSIGN "lab22.in"   
        organization line sequential.

DATA DIVISION.

FILE SECTION.
    FD  inFile.
    01  vinNumber.      
		02 countryCode		PIC X(1).
 		02 mfg 				PIC A(1).
 		02 typeOrDivision 	PIC X(1).
 		02 vehicleStyle 	PIC X(4).
 		02 checkDigit 		PIC 9(1).
 		02 yearCode 		PIC X(1).
 		02 asmbPlant 		PIC X(1).
 		02 prodNumber 		PIC 9(5).
		
WORKING-STORAGE SECTION.
01 userInput PIC X(1).

PROCEDURE DIVISION.
POne.

DISPLAY "Enter the country or manufacturer code".
ACCEPT userInput FROM CONSOLE.

open input inFile
    PERFORM FOREVER
        READ inFile
             AT END
             EXIT PERFORM
             END-READ
		
		IF countryCode = userInput OR mfg = userInput
			DISPLAY vinNumber
		END-IF
	END-PERFORM
	CLOSE inFile

STOP RUN.
