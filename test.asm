%include "io/asm_io.inc"
section .text
global main

main:
enter 12,0
push ebx
push ecx
mov [ebp-4],dword 2
label2:
cmp [ebp-4],dword 0
jg label0
jmp label1
label0:
xor ebx,ebx
mov ebx,dword[ebp-4]
sub ebx,dword 1
mov [ebp-4],ebx
jmp label2
label1:
mov eax,[ebp-4]
call print_int_i
pop ecx
pop ebx
leave
ret
