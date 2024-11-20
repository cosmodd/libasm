global ft_strdup
extern malloc ; use malloc(size_t size);
extern ft_strlen ; use ft_strlen

; char *ft_strdup(const char *str);
; rdi -> str
section .text
ft_strdup:
	cmp rdi, 0	; compare *str (rdi) to 0 (NULL)
	je _null	; if the address is null, return null

	; get the length to malloc
	push rdi		; save rdi (modified by ft_strlen)
	call ft_strlen	; call ft_strlen function
	inc rax			; add 1 to length to account for the null char
	mov rcx, rax	; move length to rcx
	pop rdi			; restore string address

	; malloc a new string
	push rdi				; save string address
	mov rdi, rcx			; move length (rcx) to first arg (rdi)
	call malloc wrt ..plt	; call malloc with `wrt ..plt` to get the address of malloc in the PLT
	pop rdi					; restore string address
	cmp rax, 0				; compare returned address to NULL
	je _null				; return null if malloc failed
	mov rsi, rax			; copy returned address for string copy

_copy:
	mov dl, byte [rdi]	; copy char from *src to `dl`
	mov byte [rsi], dl	; copy char from `dl` to *dest
	cmp dl, 0			; check if char `dl` is null char
	je _return			; if yes, then return
	inc rdi
	inc rsi
	jmp _copy

_null:
	mov rax, 0
_return:
	ret
