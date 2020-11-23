IDENTIFICATION DIVISION.                          
PROGRAM-ID.    DATETIME.                          
ENVIRONMENT DIVISION.                            
DATA DIVISION.                                    
WORKING-STORAGE SECTION.                          
                                                  

01  WS-CURRENT-DATE.
   05  WS-CURRENT-YEAR			PIC 9(04).
   05  WS-CURRENT-MONTH			PIC 9(02).
   05  WS-CURRENT-DAY			PIC 9(02).          

01 currentDate 			PIC 9(08).
01 dateInteger        	PIC 9(07).
01 FutureDate        	PIC 9(08). 
01 testDate 			PIC 9(08) VALUE 16010101.

PROCEDURE DIVISION.                              
                  		
    MOVE FUNCTION CURRENT-DATE to WS-CURRENT-DATE.  
	MOVE WS-CURRENT-DATE to currentDate.		
    DISPLAY 'THE DATE TODAY IS : ' WS-CURRENT-MONTH'/'WS-CURRENT-DAY'/'WS-CURRENT-YEAR.     
	
	COMPUTE dateInteger = FUNCTION INTEGER-OF-DATE (currentDate).
	ADD 90 TO dateInteger.
	COMPUTE FutureDate = FUNCTION DATE-OF-INTEGER (dateInteger).
	MOVE FutureDate to WS-CURRENT-DATE.  
	DISPLAY 'The date 90 Days from now is : ' WS-CURRENT-MONTH'/'WS-CURRENT-DAY'/'WS-CURRENT-YEAR.   
    STOP RUN. 
