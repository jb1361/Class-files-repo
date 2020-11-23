IDENTIFICATION DIVISION.
PROGRAM-ID. Lab33.
ENVIRONMENT DIVISION.
CONFIGURATION SECTION.

DATA DIVISION.
WORKING-STORAGE SECTION.
01 WS-NUM PIC 9(2).
88 FAIL VALUES ARE 13 THRU 99.
88 FAILTwo VALUES ARE -9 THRU 00.
01 userInput PIC 9(3).
01 userInputTwo PIC A(9).


78 Month-TABLE-SIZE VALUE 12.

01 Month-Values.
02 FILLER PIC X(9) VALUE 'January '.
02 FILLER PIC X(9) VALUE 'February '.
02 FILLER PIC X(9) VALUE 'March '.
02 FILLER PIC X(9) VALUE 'April '.
02 FILLER PIC X(9) VALUE 'May '.
02 FILLER PIC X(9) VALUE 'June '.
02 FILLER PIC X(9) VALUE 'July '.
02 FILLER PIC X(9) VALUE 'August '.
02 FILLER PIC X(9) VALUE 'September'.
02 FILLER PIC X(9) VALUE 'October '.
02 FILLER PIC X(9) VALUE 'November '.
02 FILLER PIC X(9) VALUE 'December '.

01 Month-Table REDEFINES Month-Values.
02 Month PIC X(9) OCCURS Month-TABLE-SIZE TIMES.

01 ii pic 999 value 1.

PROCEDURE DIVISION.

DISPLAY "Enter month 1-12".
ACCEPT userInput FROM CONSOLE.
MOVE userInput TO WS-NUM.

IF FAIL
	DISPLAY WS-NUM' is an invalid month'
	STOP RUN
end-if.
IF FAILTwo
	DISPLAY WS-NUM' is an invalid month'
	STOP RUN
end-if.

perform
	varying ii from 1 by 1
	until ii > 12

	IF ii = WS-NUM
		display month(ii)
	END-IF
end-perform.

DISPLAY "Enter month name".
ACCEPT userInputTwo FROM CONSOLE.

perform
	varying ii from 1 by 1
	until ii > 12

	IF Function Upper-case(month(ii)) = Function Upper-case(userInputTwo)
		display ii
	END-IF
end-perform.

stop run.
