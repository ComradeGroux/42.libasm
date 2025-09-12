bits 64

section .data

section .text
	global _ft_write
	extern __errno_location

	_ft_write:
		mov		rax, 1	; we put sys_write in RAX
		syscall			; we do not need to touch RSI, RDI, ect... because we received the right parameter in the right register
		cmp		rax, 0
		jl		error
		ret

	error:
		mov		r8, rax				; save the ERRNO in a temp register
		call	__errno_location	; return a pointer to ERRNO
		mov		[rax], r8			; save the temp in the LOCATION of ERRNO
		mov		rax, -1				; save -1 as the return value
		ret