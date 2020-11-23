IDENTIFICATION DIVISION.
PROGRAM-ID. LAB30.
ENVIRONMENT DIVISION.
INPUT-OUTPUT SECTION.                
FILE-CONTROL.
    SELECT inFile ASSIGN "lab30.in"   
        organization line sequential.

DATA DIVISION.

FILE SECTION.
    FD  inFile.
    01  loanDetails.      
		02 facultyNumber	PIC 9(3).
 		02 userName 		PIC A(17).
 		02 loanId 			PIC 9(3).
 		02 whitespaceOne 	PIC A(1).
 		02 loanDate.
			03 loanMonth	PIC 9(2).
			03 loanDay		PIC 9(2).
			03 loanYear		PIC 9(4).
		02 whitespaceTwo 	PIC A(1).
 		02 loanAmt 			PIC 9(4).99.
 		
		
WORKING-STORAGE SECTION.

01  WS-CURRENT-DATE.
   05  WS-CURRENT-YEAR			PIC 9(04).
   05  WS-CURRENT-MONTH			PIC 9(02).
   05  WS-CURRENT-DAY			PIC 9(02).    
   
01 loanDateInt 			PIC 9(7).
01 loanDateFormatted 	PIC 9(8).
01 currentDateInt 		PIC 9(7).
01 currentDate 			PIC 9(8).
01 totalLoans			PIC 9(2).
01 loansOneToThreeYears	PIC 9(2).
01 loansOlderThanThree	PIC 9(2).


PROCEDURE DIVISION.
POne.

MOVE FUNCTION CURRENT-DATE to WS-CURRENT-DATE.  
MOVE WS-CURRENT-DATE to currentDate.		
COMPUTE currentDateInt = FUNCTION INTEGER-OF-DATE (currentDate).


open input inFile
    PERFORM FOREVER
        READ inFile
             AT END
             EXIT PERFORM
             END-READ
		
		COMPUTE loanDateFormatted = (loanYear * 10000) + (loanMonth * 100) + loanDay
		COMPUTE loanDateInt = FUNCTION INTEGER-OF-DATE (loanDateFormatted)
		IF currentDateInt - loanDateInt > 1095
			DISPLAY 'Thank you for your buisness ' userName
			IF currentDateInt - loanDateInt > 1825
				DISPLAY 'moving ' userName ' to history file'
				ADD 1 to loansOlderThanThree
			END-IF
		END-IF
		IF currentDateInt - loanDateInt < 30
			DISPLAY 'Welcome to our bank ' userName
		END-IF
		IF currentDateInt - loanDateInt > 365
			ADD 1 to loansOneToThreeYears
		END-IF
		IF loanAmt < 0100.00
			DISPLAY 'Your load is coming to an end, we want your money again ' userName
		END-IF
		ADD 1 to totalLoans
		
	END-PERFORM
	CLOSE inFile
	
	DISPLAY 'Total loans: 'totalLoans.
	DISPLAY 'Loans one to three years: 'loansOneToThreeYears.
	DISPLAY 'Loans Older than three years 'loansOlderThanThree.
	
STOP RUN.
