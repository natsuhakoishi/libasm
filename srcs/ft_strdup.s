section .note.GNU-stack				; versions binutils 2.39+ will raise a warning without this section

; char *ft_strdup(const char *s);
; rdi = s

section .text
	global ft_strdup
	extern __errno_location
	extern malloc

ft_strdup:
	mov rbx, rdi					; move the string from the argument(rdi) to temp callee-saved register which wont be overwrite after calling malloc
	xor rcx, rcx					; initialize the counter to 0 for strlen usage

.strlen_loop:
	mov al, [rsi + rcx]				; move current 1 byte data base on the counter index to the register
	test al, al						; check if the byte is '\0' by using test (AND compare but only affect FLAG)
	je .strlen_done					; if empty flag = 1, means is null then jump to .strlen_done part
	inc rcx							; increment the counter by 1
	jmp .strlen_loop				; continue loop

.strlen_done:
	; malloc(strlen(s) + 1);
	mov rdi, rcx					; move the final counter value of s to rdi as first argument for malloc (strlen(s))
	inc rdi							; (+ 1)
	call malloc wrt ..plt			; call void *malloc(size_t size), rdi as the argument = size, wrt ..plt refer ft_write.s / ft_read.s
	test rax, rax					; check the return value (which save in rax the accumulate register) by malloc
	jz .error						; if the return value by malloc is zero which means failure, jump to .error part
	mov rdi, rax					; move the destination buffer (memory address pointer) returned by malloc in rax to rdi
	xor rcx, rcx					; clear the counter for .dup_loop

.dup_loop:
	mov dl, [rbx + rcx]				; move 1 byte from rbx to dl as temp register according to the counter index
	mov [rdi + rcx], dl				; move the byte from the temp dl to rdi which allocated memory according to the counter index
	inc rcx							; increment the counter
	test dl, dl						; check the temp is it null ('\0')
	jne .dup_loop					; if it is not empty/null, continue loop
	mov rax, rdi					; move the string which done duplicated to accumulate register rax for return purpose
	ret								; return pointer in rax (malloc result)

.error:
	mov edi, 12						; if malloc failure the errno is 12, move in the edi as argument for calling errno
	call __errno_location wrt ..plt	; refer ft_read.s / ft_write.s
	mov [rax], edi					; set the errno to 12 as [rax] = *errno
	xor rax, rax					; set the accumulate register to 0 for return purpose
	ret								; return NULL

