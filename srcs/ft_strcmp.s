bits 64

section .data

section .text
	global _ft_strcmp

	_ft_strcmp:
		mov rcx, 0

	loop:
		mov r8, [rdi + rcx]
		mov r9, [rsi + rcx]
		cmp r8, r9
		jne end
		inc rcx
		jmp loop

	end:
		sub r8, r9
		mov rax, r8
		ret