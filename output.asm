global _start

section .data
    floatVal0: dd 1.530000

section .text

_start:
    mov rax, 0
    push rax
    mov qword [rsp + 0], 2
    sub rsp, 16
    movss xmm0, dword [floatVal0]
    movss [rsp], xmm0
    sub rsp, 1
    mov byte [rsp], 77
    mov rax, 60
    mov rdi, 113
    syscall
