#include <thread_syscalls.h>

/*
 * sys_exit() system call -> close the thread and the associated process cleaning the address space
 *
 */
int
sys_exit(int status)
{
	//get info on the current proc
	struct proc *proc = curproc;
	if(proc == NULL){
		kprintf("NO CURRENT PROCESS!!!");
		return 1;	
	}
	//set the exit code into the thread structure
	//WHO CAN SEE IT IF THE THREAD IS DESTROYED???
	struct thread *thread = curthread;
	thread->t_exit_code = status;	
	//destroy the thread
	thread_exit();	
	//destroy the process freeing its address space -> we can do this: 1 proc only 1 thread
	proc_destroy(proc);	
	
	return 0;	

}
