format ELF64 executable
_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, hello
	mov rdx, 15
	syscall

	mov rax, 60
	mov rdi, 1
	syscall

hello:
	db "Hello, World!"
