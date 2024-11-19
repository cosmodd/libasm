global ft_read

; ssize_t ft_read(int fd, void *buf, size_t count);
section .text
ft_read:
	mov rax, 0 ; set rax to sys_read
	syscall
	ret