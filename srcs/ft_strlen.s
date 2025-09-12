bits 64

section .data

section .text
	global _ft_strlen

	_ft_strlen:
		mov rcx, 0	; init counter

	loop:
		cmp [rdi + rcx], 0 	; RDI point to beginning of the string, so we add the RCX to check the right character
		je end				; If cmp is equal, jump to end. Otherwise continue
		inc rcx
		jmp loop

	end:
		mov rax, rcx	; RET return RAX so we move the counter into it
		ret