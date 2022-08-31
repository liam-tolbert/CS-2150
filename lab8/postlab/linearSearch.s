; linearSearch.s


	global linearSearch
	
	
	section .text
	
linearSearch:
	xor	eax, eax
	xor	ebx, ebx

loop:
	cmp	eax, esi	; if i == size
	je	unFound
	
	mov 	ebx, [edi+eax*4]
	cmp	edx, ebx	; if array[i] == target
	je	xit
	
	inc	eax
	
	jmp	loop
unFound:
	mov	eax, -1
xit:
	ret
	
