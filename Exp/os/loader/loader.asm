org	0100h

	mov	ax, 0B800h
	mov	gs, ax
	mov	ah, 0Fh				; 0000: 黑底    1111: 白字
	mov	al, 'T'
	mov	[gs:((80 * 0 + 39) * 2)], ax
	mov	al, 'h'
	mov	[gs:((80 * 0 + 40) * 2)], ax
	mov	al, 'i'
	mov	[gs:((80 * 0 + 41) * 2)], ax
	mov	al, 's'
	mov	[gs:((80 * 0 + 42) * 2)], ax
	mov	al, ' '
	mov	[gs:((80 * 0 + 43) * 2)], ax
	mov	al, 'i'
	mov	[gs:((80 * 0 + 44) * 2)], ax
	mov	al, 's'
	mov	[gs:((80 * 0 + 45) * 2)], ax
	mov	al, ' '
	mov	[gs:((80 * 0 + 46) * 2)], ax
	mov	al, 's'
	mov	[gs:((80 * 0 + 47) * 2)], ax
	mov	al, 'y'
	mov	[gs:((80 * 0 + 48) * 2)], ax
	mov	al, 's'
	mov	[gs:((80 * 0 + 49) * 2)], ax
	mov	al, "'"
	mov	[gs:((80 * 0 + 50) * 2)], ax
	mov	al, 's'
	mov	[gs:((80 * 0 + 51) * 2)], ax
	mov	al, ' '
	mov	[gs:((80 * 0 + 52) * 2)], ax
	mov	al, 'l'
	mov	[gs:((80 * 0 + 53) * 2)], ax
	mov	al, 'o'
	mov	[gs:((80 * 0 + 54) * 2)], ax
	mov	al, 'a'
	mov	[gs:((80 * 0 + 55) * 2)], ax
	mov	al, 'd'
	mov	[gs:((80 * 0 + 56) * 2)], ax
	mov	al, 'e'
	mov	[gs:((80 * 0 + 57) * 2)], ax
	mov	al, 'r'
	mov	[gs:((80 * 0 + 58) * 2)], ax

    jmp	$				; 到此停住
