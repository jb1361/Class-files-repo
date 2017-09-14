INCLUDE Irvine32.inc

.data 
Rval SDWORD ? 
Xval SDWORD 26
Yval SDWORD 30 
Zval SDWORD 40
.const


.code
main proc
mov ebx,Yval
neg ebx
add ebx,Zval
mov eax,Xval
sub eax,ebx
mov Rval,eax
call dumpregs
mov eax,0
mov ebx,0
mov ecx,0
mov edx,0

mov ax,00FFh 
add ax,1
call dumpregs
sub ax,1
call dumpregs
add al,1
call dumpregs
mov bh,6Ch 
add bh,95h
call dumpregs
mov al,2 
sub al,3
call dumpregs

	exit
main ENDP
END main