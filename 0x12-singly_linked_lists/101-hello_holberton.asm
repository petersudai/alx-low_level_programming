section .data
format db 'Hello, Holberton',10,0
fmt db "%s", 10, 0

section .text
global main
extern printf

main:
move rdi, fmt
mov rdi, format
xor rax, rax
call printf

; Exit program
mov eax, 60 ; syscall number for exit
xor edi, edi ; exit code 0
syscall

section .bss
format resb 256
