section .data
hello: db "Hello, Holberton", 10, 0

section .text
global main

extern printf

main:
push rbp
mov rbp, rsp

lea rdi, [hello]
xor eax eax
call printf

; Exit program
mov eax, 60 ; syscall number for exit
xor edi, edi ; exit code 0
syscall

section .bss
format resb 256
