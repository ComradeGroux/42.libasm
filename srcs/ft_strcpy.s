bits 64

section .data

section .text
	global ft_strcpy
	
	ft_strcpy: ; RDI = dst ; RSI = src
		mov		rcx, 0

	loop:
		mov		al, [rsi + rcx]
		mov		[rdi + rcx], al
		inc		rcx
		cmp		al, 0
		jne		loop

	end:
		mov		rax, rdi
		ret