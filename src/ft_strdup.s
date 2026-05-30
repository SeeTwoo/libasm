%define NULL 0
%define EINVAL 22

section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	extern __errno_location

ft_strdup:
	cmp	rdi, NULL
	je	.set_einval

	push	rbp
	mov	rbp, rsp
	push	rdi

	call ft_strlen

	mov	rdi, rax
	inc	rdi
	call malloc wrt ..plt

	cmp	rax, NULL
	je	.malloc_error

	mov	rdi, rax
	pop	rsi
	call ft_strcpy
	
	leave
	ret

.set_einval:
	call	__errno_location wrt ..plt
	mov	dword [rax], EINVAL

.malloc_error:
	mov	rsp, rbp
	pop	rbp
	xor	rax, rax
	ret
