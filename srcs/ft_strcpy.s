section .note.GNU-stack	; versions binutils 2.39+ will raise a warning without this section

; char *ft_strcpy(char *dst, const char *src);
; rdi = dst
; rsi = src
; return rax = dst

section .text
	global ft_strcpy

ft_strcpy:
	mov rax, rdi		; move the rdi(dst) address to accumulate register for further return action
	xor rcx, rcx		; initialize counter to 0

.loop:
	mov dl, [rsi + rcx]	; read src[rcx] and move 1 byte base on the counter index to the general-pupose register as temp storage
	mov [rdi + rcx], dl	; move the value in register last step to dst[rcx]
	test dl, dl			; check if the byte is '\0' by using test (AND compare but only affect FLAG)
	je .return			; if empty flag = 1, means is null then jump to return part
	inc rcx				; increment the counter by 1
	jmp .loop			; continue loop

.return:
	ret					; return the value in accumulate register
