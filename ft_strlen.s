global _ft_strlen

section .text
_ft_strlen:
push    rcx
xor     rcx, rcx
jmp     _ft_strlen_loop

_ft_strlen_loop:
cmp     [rdi], byte 0       ; is null byte?
jz      _is_null_elem       ; yes, stop loop

inc     rcx                 ; increase counter
inc     rdi                 ; shift pointer
jmp     _ft_strlen_loop     ; new cycle

_is_null_elem:
mov     rax, rcx            ; store len in rax
pop     rcx                 ; restore rcx
ret                         ; return rax value