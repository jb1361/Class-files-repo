INCLUDE Irvine32.inc
.data
msg2 BYTE "Elapsed milliseconds: ",0
.code
main PROC
mov eax, 0 
mov ebx, 0
mov ecx, 0
mov edx, 0


call GetMSeconds
call dumpregs
mov edx, OFFSET msg2
call writestring
call writedec
call Crlf
call Crlf
exit

main ENDP
END main