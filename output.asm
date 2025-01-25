global _start

section .data

section .text

_start:
    mov rax, 0
    push rax
    mov qword [rsp + 0], 2
    mov rax, 60
    mov rdi, 113
    syscall
