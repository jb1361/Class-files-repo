INCLUDE Irvine32.inc
.data
msg1 BYTE "Hello my name is: ", 0
msg2 BYTE "1,",0
msg3 BYTE "101,",0
msg4 BYTE "0",0
comma BYTE ",",0
int1 BYTE 0
int2 BYTE 100
.code
main PROC
mov edx, OFFSET msg1
call WriteString
Call ReadString
call Crlf
mov edx, OFFSET msg2
call WriteString 
mov edx, OFFSET msg3
call WriteString 
mov eax, 1
mov ebx, 101
mul ebx

mov edx, eax
call WriteInt
call Crlf
call Crlf

mov ecx, 10	
mov eax, 0
mov ebx, 0
mov al, int1
L1:
add al, 1
push ecx
mov ecx, 10
mov bl, int2
L2:
add bl,1
mov edx,0
mov dl,al
call WriteInt
mov edx, OFFSET comma
call writeString
mov edx, 0
push eax
mov al,bl
call WriteInt
pop eax
mov edx,0
mov edx, OFFSET comma
call writeString
mov edx, 0

push eax
push ebx


mul ebx
mov edx, eax
call WriteInt


pop ebx
pop eax
call Crlf
loop L2
pop ecx
loop L1


	exit
main ENDP
END main