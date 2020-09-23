; int ft_strcmp(const char *s1, const char *s2);
; rdi == s1, rsi == s2

global _ft_strcmp

section .text
_ft_strcmp:
push    rcx
push    rdx
xor     rcx, rcx
xor     rdx, rdx
xor     rax, rax
jmp     _ft_strcmp_loop

_ft_strcmp_loop:
mov     al, byte[rdi+rcx]               ; 0 byte of rax
mov     dl, byte[rsi+rcx]               ; 0 byte of rdx
cmp     rax, rdx                        ; is equal?
jne     _end_cmp                        ; no, stop loop

cmp     byte[rsi+rcx], byte 0           ; is null byte?
je      _end_cmp                        ; yes, stop loop

inc     rcx                             ; increase counter
jmp     _ft_strcmp_loop                 ; new cycle

_end_cmp:        
sub     rax, rdx
pop     rdx                             ; restore rdx
pop     rcx                             ; restore rcx
ret                                     ; return rax value
