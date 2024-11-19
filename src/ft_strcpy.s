global  ft_strcpy

; ft_strcpy(char *dest, const char *src);
section .text
ft_strcpy:
	push rdi
_loop:
	; copy char from src to dst
	mov al, byte [rsi] ; copy char at rsi into al
	mov byte [rdi], al
	cmp al, 0
	je _done ; return if we are at a null char
	inc rdi ; increment dest pointer
	inc rsi ; increment src pointer
	jmp _loop
_done:
	pop rdi
	mov rax, rdi
	ret