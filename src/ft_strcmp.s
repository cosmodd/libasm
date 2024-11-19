global ft_strcmp

; ft_strcmp(const char *s1, const char *s2);
section .text
ft_strcmp:
	mov rax, 0 ; reset register
_loop:
	mov al, byte [rdi] ; get the char for s1
	cmp al, 0
	je _end ; return if null char
	sub al, byte [rsi] ; substract *s1 and *s2
	cmp al, 0
	jne _end ; jump to _end if not equal
	inc rdi ; s1++
	inc rsi ; s2++
	jmp _loop
_end:
	mov al, byte [rdi] ; move char to rax lower byte
	mov cl, byte [rsi] ; move char to rxc lower byte
	sub rax, rcx ; 8 bytes substraction
	ret
