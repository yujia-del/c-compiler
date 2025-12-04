%include "io/asm_io.inc"
section .text
global main

main:
enter 8,0
push ebx
push ecx
mov [ebp-4],dword 0
label2:
cmp [ebp-4],dword 10
jl label0
jmp label1
label0:
xor ebx,ebx
mov ebx,dword[ebp-4]
add ebx,dword 1
mov [ebp-4],ebx
xor ebx,ebx
mov ebx,dword[ebp-4]
add ebx,dword 1
mov [ebp-4],ebx
jmp label2
label1:
pop ecx
pop ebx
leave
ret
pop ecx
pop ebx
leave
ret
