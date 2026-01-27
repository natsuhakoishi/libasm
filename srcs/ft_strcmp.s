section .note.GNU-stack	; versions binutils 2.39+ will raise a warning without this section

; int ft_strcmp(const char *s1, const char *s2);
; rdi = s1
; rsi = s2
; return rax = diff

section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax		; initialize accumulate register to 0 for return usage

.loop:
	mov al, [rdi]		; move the current s1 character (*s1) to accumulate register (1 byte per move as al is 8-bit)
	mov dl, [rsi]		; move the current s2 character (*s2) to general-purpose register (1 byte per move as dl is 8-bit)
	cmp al, dl			; compare *s1 *s2
	jne .diff			; jump to diff section if there are not equal
	test al, al			; check if the byte is '\0' by using test (AND compare but only affect FLAG)
	je .equal			; if until end still no difference then jump to equal part
	inc rdi				; *s1++
	inc rsi				; *s2++
	jmp .loop			; continue loop

.diff:
	movzx eax, al		; move *s1 which in al (8-bit) register to bigger eax (32-bit) register as return type is int (32-bit)
	movzx edx, dl		; move *s2 which in dl (8-bit) register to bigger edx (32-bit) register as return type is int (32-bit)
	sub eax, edx		; calculate the subtraction between *s1 and *s2
	ret					; return the result in eax

.equal:
	xor eax, eax		; clear the accumulate register to return 0, xor eax instead of al because the return type int is 32-bit
	ret					; return 0
