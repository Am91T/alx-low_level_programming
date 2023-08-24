section .data
	hello db "Hello, Holberton", 0
	format db "%s", 10, 0  ; Add a newline character after the string

section .text
	global main

	extern printf

main:
	push    rbp
	mov     rdi, format
	mov     rsi, hello
	call    printf
	pop     rbp
	ret
