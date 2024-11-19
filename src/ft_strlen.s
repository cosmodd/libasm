global ft_strlen

; size_t ft_strlen(const char *str);
section .text
ft_strlen:
	mov rax, 0
_count:
	cmp byte [rdi], 0
	je _done
	inc rdi
	inc rax
	jmp _count
_done:
	ret

