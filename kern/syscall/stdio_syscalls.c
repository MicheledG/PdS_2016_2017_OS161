#include <stdio_syscalls.h>

/*
 * sys_write() system call -> redirected to the console
 *
 */
int
sys_write(char* buf, size_t buf_len)
{
	
	
	//insert "end of string" in the char vector
	buf[buf_len] = '\0';
	kprintf(buf);
	return 0;	

}

/*
 * sys_write() system call -> take from the console
 *
 */
int
sys_read(char* buf, size_t buf_len)
{
	
	
	//insert "end of string" in the char vector
	buf[buf_len] = '\0';
	kgets(buf, buf_len);
	return 0;	

}
