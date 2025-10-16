bits 64

section .data

section .text
	global ft_strcmp

	ft_strcmp:
		mov		rcx, 0

	loop:
		mov		r8b, [rdi + rcx]
		mov		r9b, [rsi + rcx]
		cmp		r8b, r9b
		jne		end
		inc		rcx
		jmp		loop

	end:
		sub		r8b, r9b
		movzx	rax, r8b
		ret