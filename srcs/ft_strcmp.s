bits 64

section .data

section .text
	global ft_strcmp

	ft_strcmp:
		mov		rcx, 0

	loop:
		mov		al, [rdi + rcx]
		mov		bl, [rsi + rcx]
		cmp		al, bl
		jne		end

		test	al, al
		je		end

		inc		rcx
		jmp		loop

	end:
		movzx	eax, al
		movzx	ebx, bl
		sub		eax, ebx
		ret