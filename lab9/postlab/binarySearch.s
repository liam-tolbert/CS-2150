	global binarySearch
	section .text
	
	;;Param 1: edi, int* arr
	;;Param 2: esi, int left
	;;Param 3: edx, int right
	;;Param 4: ecx, int target
binarySearch:
	xor eax, eax
	xor ebx, ebx		;int mid
	
	cmp esi, edx		; checking if array size is 0
	je done
loop:
	cmp esi, edx
	jg notFound
	
	mov ebx, esi
	add ebx, edx
	shr ebx, 1		;mid=(left+right)/2
	
	cmp [edi+ebx*4], ecx	;if(a[mid]<key)
	jl lesser
	
	cmp [edi+ebx*4], ecx	;if(a[mid]>key)
	jg greater
	
	mov eax, ebx
	jmp done
lesser:
	mov esi, ebx
	inc esi
	jmp loop
greater:	
	mov edx, ebx
	dec edx
	jmp loop
notFound:
	mov eax, -1
done: 
	ret
