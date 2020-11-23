IDENTIFICATION DIVISION.
PROGRAM-ID. HELLO1.
ENVIRONMENT DIVISION.
CONFIGURATION SECTION.

DATA DIVISION.
WORKING-STORAGE SECTION.
01 RVar PIC 9(10).
01 SVar PIC 9(10).
01 IVar PIC 9(10).
01 resultValue PIC 99999v99.

PROCEDURE DIVISION.
FIRST-PARA.
DISPLAY "Enter the total yearly production requirement".
ACCEPT RVar FROM CONSOLE.
DISPLAY "Enter setup cost per order".
ACCEPT SVar FROM CONSOLE.
DISPLAY "Enter inventory carrying cost per unit".
ACCEPT IVar FROM CONSOLE.

COMPUTE resultValue = ((2 * RVar * SVar) / IVar)**.5
DISPLAY 'Economic order quantity: ' resultValue
STOP RUN.
