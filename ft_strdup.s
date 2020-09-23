; char	*strdup(const char *s1);
; rdi == s1

extern _ft_strlen
extern _ft_strcpy
extern _ft_strcmp
extern _malloc

global _ft_strdup

_ft_strdup:
cmp		rdi, 0			; check s1 value
push	rdi				; save s1
je		_err
call	_ft_strlen
inc		rax				; add one for 0
mov		rdi, rax		; malloc size == rdi
call	_malloc			; rax == void *malloc()
cmp		rax, 0			; check malloc return value
je		_err
mov		rdi, rax		; char *ft_strcpy(char *dst, const char *src);
pop		rsi				; store s1 in rsi. rsi == src
call	_ft_strcpy
mov		rax, rdi		; return char *
ret

_err:
mov		rax, 0
pop		rcx
ret