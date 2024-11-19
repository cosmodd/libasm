global ft_write

; ft_write(int fd, const void *buffer, size_t count);
section .text
ft_write:
	mov rax, 1 ; set rax (system call) to 1 (sys_write)
	syscall ; call write
	ret ; return syscall return value (set in rax)
