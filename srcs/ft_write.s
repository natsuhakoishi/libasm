section .note.GNU-stack		; versions binutils 2.39+ will raise a warning without this section

; ssize_t ft_write(int fd, const char *buf, size_t count);
; rdi = fd
; rsi = buf
; rdx = count (size_t is unsigned)
; if success return writen byte count, else -1

section .text
	global ft_write
	extern __errno_location			; tell linker the function in libc not current file

ft_write:
	mov rax, 1						; set syscall number to 1 (write), as 0 read 1 write 2 open 3 close etc.
	syscall							; CPU will switch to kernel mode, check syscall table according to syscall number and operate also return result

	; if success kernel will return byte count that written successfully, else return rax = -errno which is signed number
	test rax, rax					; check the return value
	jns .success					; if the value is not signed (-), then jump to .sucess section to return byte count

	; Error handling while result is signed number (-)
	neg rax							; change the number to positive number as libc only accept positive number as errno
	mov rdi, rax					; move the number to caller-saved register as temp storage as rdi already used while syscall, also next call function will overwrite rax

	; get errno address (rax will default hold the return value as Application Binary Interface rule) and rax = &errno \
	; here using With Respect To Procedure Linkage Table (wrt ..plt) flag as middle-man of function call to let dynamic linker to calculate the correct address
	call __errno_location wrt ..plt	; as two comment above, will error if not using these flag when making a Position Independent Executable (PIE) object
	mov [rax], edi					; move 32-bit of rdi (int) to [rax] (*errno)
	mov rax, -1						; move -1 to accumulate register for return purpose
	ret								; return the value

.success:
	ret								; return the byte count in accumulate register

