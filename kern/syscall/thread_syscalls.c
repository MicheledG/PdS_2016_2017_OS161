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
	//we have to detach the diying thread from its process to let the thread to its destiny	
	struct thread *thread = curthread;
	proc_remthread(thread);
	//set the exit code into the proc structure	
	lock_acquire(proc->p_sleeplock);	
	proc->p_exit_code = status;
	proc->p_is_to_destroy = true;		
	cv_signal(proc->p_cv, proc->p_sleeplock);
	lock_release(proc->p_sleeplock);
	//exit from the thread -> it will be destroyed soon by exorcise()
	thread_exit();					
	
	return 0;
}
