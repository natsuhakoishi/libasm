section .note.GNU-stack	; versions binutils 2.39+ will raise a warning without this section

; size_t ft_strlen(const char *str)
; rdi = str (rdi will default as 1st arguments to place the value)
; return rax = strlen

section .text
	global ft_strlen

ft_strlen:
	xor rcx, rcx		; initialize counter to 0

.loop:
	mov al, [rdi + rcx] ; move 1 byte data base on the counter index to the register
	test al, al			; check if the byte is '\0' by using test (AND compare but only affect FLAG)
	je .return			; if empty flag = 1, means is null then jump to return part
	inc rcx				; increment the counter by 1
	jmp .loop			; continue loop

.return:
	mov rax, rcx		; store the counter value to accumulate register to return
	ret					; return the value
