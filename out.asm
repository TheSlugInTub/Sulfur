section .data
    msg db 'Hello, world!', 0xA
    msg_len equ $ - msg

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msg_len
    syscall
    mov rax, 0
    push rax
    mov rax, 0
    push rax
    mov qword [rsp + 0], 5
    mov qword [rsp + 8], 13
    mov rax, 60
    mov rdi, 133
    syscall
