INCLUDE Irvine32.inc

.data
msg1 BYTE "Enter String: ", 0
aName BYTE 50 DUP(?),0
;nameSize = ($ - aName) - 1
nameSize DWORD ?
.code
main PROC
mov edx, OFFSET msg1
call WriteString
mov edx, OFFSET aName
mov ecx, SIZEOF aName
Call ReadString
mov nameSize, eax
call Crlf




; Push the name on the stack.
	mov esi,0	mov ecx, nameSize

	;for future reference we are pushing this string in reverse order onto the stack (eg 'John')
	;n would be the zero index hence why we moved zero into esi
L1:	movzx eax,aName[esi]	
	push eax	
	inc esi
	Loop L1

; Pop the name from the stack, in reverse,
; and store in the aName array.
	mov ecx, nameSize
	mov esi,0

L2:	pop eax	; get character
	mov aName[esi],al	; store in string
	inc esi
	Loop L2

; Display the name.
	mov edx,OFFSET aName
	call Writestring
	call Crlf

	exit
main ENDP
END main