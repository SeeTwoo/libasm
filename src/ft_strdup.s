%define NULL 0
%define EINVAL 22

section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	extern __errno_location

ft_strdup:
	push	rbp
	mov	rbp, rsp

	cmp	rdi, NULL
	je	.set_einval

	push	rdi
	push	0

	call ft_strlen

	mov	rdi, rax
	inc	rdi
	call malloc wrt ..plt

	add	rsp, 8
	pop	rsi

	cmp	rax, NULL
	je	.done

	mov	rdi, rax
	call ft_strcpy
	
.done:
	leave
	ret

.set_einval:
	call	__errno_location wrt ..plt
	mov	dword [rax], EINVAL
	xor	rax, rax
	leave
	ret
