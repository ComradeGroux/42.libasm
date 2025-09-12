bits 64

section .data

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

	_ft_strdup:
		call	_ft_strlen	; return the length in RAX
		inc		rax
		push	rdi			; save the parameter in the stack to use it later

		; Call MALLOC with the return value of ft_strlen (incremented by 1)
		mov		rdi, rax	
		call	_malloc

		; Move the new string in the right register, retrieve the parameter in the stack and then call
		mov		rdi, rax
		pop		rsi
		call	_ft_strcpy
		ret