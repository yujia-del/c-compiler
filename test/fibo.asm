%include "io/asm_io.inc"
section .text
global main

fibo_i:
enter 12,0
push ebx
push ecx
cmp [ebp+8],dword 1
je label0
jmp label1
label0:
mov eax,1
leave
ret
jmp label2
label1:
cmp [ebp+8],dword 2
je label3
jmp label2
label3:
mov eax,2
leave
ret
label2:
xor ebx,ebx
mov ebx,dword[ebp+8]
sub ebx,dword 1
push ebx
call fibo_i
mov ebx,eax
add esp,4
mov [ebp-4],ebx
xor ebx,ebx
mov ebx,dword[ebp+8]
sub ebx,dword 2
push ebx
call fibo_i
mov ebx,eax
add esp,4
mov [ebp-8],ebx
mov ebx,[ebp-4]
add ebx,[ebp-8]
mov eax,ebx
leave
ret
pop ecx
pop ebx
leave
ret
main:
enter 8,0
push ebx
push ecx
push dword 5
call fibo_i
mov ebx,eax
add esp,4
mov [ebp-4],ebx
mov eax,[ebp-4]
call print_int_i
pop ecx
pop ebx
leave
ret
