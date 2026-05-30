section .text
	global ft_strcmp

ft_strcmp:
	xor	rcx, rcx

.loop:
	movzx	eax, BYTE [rdi + rcx]
	movzx	edx, BYTE [rsi + rcx]

	cmp	al, 0
	je	.done
	cmp	al, dl
	jne	.done
	inc	rcx
	jmp	.loop

.done:
	sub	eax, edx
	ret
