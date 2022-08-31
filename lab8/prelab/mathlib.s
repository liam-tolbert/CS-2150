; mathlib.s


	global product
	global power

	section .text

product:
	
	;Subroutine body
	xor 	rax, rax
	xor 	r10, r10	;zero out return register and i
start:
	cmp 	r10, rsi
	je	done
	add 	rax, rdi
	inc	r10
	jmp	start
done:
	ret
power:
	xor rax, rax
	mov rdx, rsi
	mov rsi, rdi
recurse:
	cmp rdx, 1
	je end
	call product
	mov rdi, rax
	dec rdx
	call recurse
end:
	mov rax, rdi
	ret
	

	
