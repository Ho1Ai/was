.section .data
byteval .byte 0

.section .text
test_mark:
	movl $0, %eax # asdf
	movb $0, %bh ; asdf
.test_label:
	movb $0, %ah
