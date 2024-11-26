global ft_read

; ssize_t ft_read(int fd, void *buf, size_t count);
section .text
ft_read:
	mov rax, 0 ; sys_read
	syscall
	test rax, rax
	js ft_read_error
	ret

ft_read_error:
	mov rax, -1
	ret