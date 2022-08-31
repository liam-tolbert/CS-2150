	global threexplusone
	section .text

	;; Param: rdi = x
	
threexplusone:
	xor rax, rax
	xor rbx, rbx
	
	cmp rdi, 1		
	je exit			
	mov rbx, rdi
	and rbx, 1
	jz isEven
	jmp isOdd
isOdd:
	xor r10, r10
	mov r10, rdi
	shl rdi, 1	; multiplying x by 2
	add rdi, r10	; adding x
	add rdi, 1	; adding 1, now it's 3x+1
	call threexplusone
	inc rax
	jmp exit
isEven:
	shr rdi, 1	; dividing by 2
	call threexplusone
	inc rax
	jmp exit	; incrementing i and recurse for both
exit:
	ret

