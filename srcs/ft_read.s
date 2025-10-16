bits 64

section .data

section .text
	global ft_read
	extern __errno_location

	ft_read:
		mov		rax, 0	; we put sys_read in RAX
		syscall			; we do not need to touch RSI, RDI, ect... because we received the right parameter in the right register
		cmp		rax, 0
		jl		error
		ret

	error:
		mov		eax, rax				; save the ERRNO in a temp register
		call	__errno_location	; return a pointer to ERRNO
		mov		[rax], eax			; save the temp in the LOCATION of ERRNO
		mov		rax, -1				; save -1 as the return value
		ret