;char *ft_strcpy(char *dst, const char *src);
;rdi == dst, rsi == src

global _ft_strcpy

section .text
_ft_strcpy:
push    rcx
push    rdx
xor     rcx, rcx
xor     rdx, rdx
jmp     _ft_strcpy_loop

_ft_strcpy_loop:
cmp     byte[rsi+rcx], byte 0   ; is null byte?
jz      _is_null_elem           ; yes, stop loop

mov     dl, byte [rsi+rcx]      ; dl is a 8bit char rdx register part
mov     byte [rdi+rcx], dl
inc     rcx                     ; increase counter
jmp     _ft_strcpy_loop         ; new cycle

_is_null_elem:
mov     byte [rdi+rcx], 0       ; null-terminating
mov     rax, rcx                ; store len in rax
pop     rdx                     ; restore rdx
pop     rcx                     ; restore rcx
ret                             ; return rax value