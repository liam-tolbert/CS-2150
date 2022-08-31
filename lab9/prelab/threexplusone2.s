	;; Liam Tolbert, lct4am, threexplusone.s
	;; 4/19/2021
	global threexplusone

	section .text

	;; Param 1: rdi (i)
threexplusone:
	xor rax, rax		; zero out return value
	xor r10, r10		; temp value

	cmp rdi, 1		;if temp == 1, goto done
	je done			
	mov r10, rdi		;check if temp is even by doing bitwise and
	and r10, 1		; with temp and 1
	jz even
	jmp odd
odd:
	lea rdi, [rdi+rdi+rdi+1] ;if odd, multiply by 3 and add one
	call threexplusone
	inc rax
	jmp done
even:
	shr rdi, 1		;if even, divide by two
	call threexplusone
	inc rax
	jmp done


	;; increment i and recurse
done:				
	ret			;return
