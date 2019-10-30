start:
    ; load to 0x7C00
    org 0x7C00
    mov ax, cs
    ; init data segment
    mov ds, ax
    ; show message
    call SHOW_MSG
    jmp $

SHOW_MSG:
    ; repeat counter
    mov dl, 10
    ; graphic mode
    mov ah, 0
    mov al, 0x13
    int 0x10

    ; init string
    mov si, MSG
    ; teletype output
    mov ah, 0xe
    ; color selector
    mov bx, 2
    .do1:
        ; load a char to al and si++
        lodsb
        ; whether string is end
        cmp al, 0
        je .done1
        ; change color
        add bx, 1
        ; color should now bigger than 0xf
        and bx, 0xf
        int 0x10
        jmp .do1
    .done1:
        ; repeat dl times
        cmp dl, 0
        je .ret1
        mov bx, 0
        add dl, -1
        mov si, MSG
        jmp .do1
    .ret1:
        mov bp, MSG_WHITE
        mov cx, 20
        mov ax, 0x1301
        mov bx, 0x0a
        mov dh, 12
        mov dl, 11
        int 0x10
        mov dh, 11
        int 0x10
        mov dh, 13
        int 0x10
        mov bp, MSG2
        mov cx, 18
        mov ax, 0x1301
        mov dh, 12
        mov dl, 12
        int 0x10
        ret
MSG:
    db  "O-oooooooooo AAAAE-A-A-I-A-U-", \
        " JO-oooooooooooo AAE-O-A-A-U-U-A-",\
        " E-eee-ee-eee AAAAE-A-E-I-E-A-",\
        " JO-ooo-oo-oo-oo EEEEO-A-AAA-AAAA", 0
MSG2:
    db  "This is sys's boot"
MSG_WHITE:
    db  "                    "
; boot sector has to be exactly 512 bytes in size
; and end with the numbers AAh and 55h
times 510-($-$$) db 0
dw 0xAA55

