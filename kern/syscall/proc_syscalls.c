#include <proc_syscalls.h>

/*
 * wait_proc(struct proc *p) -> demo version of sys_waitpid(int pid)
 *
 */
int
wait_proc(struct proc *proc)
{
	KASSERT(proc != NULL);
	//wait the proc exit	
	lock_acquire(proc->p_sleeplock);	
	while(!proc->p_is_to_destroy){
		cv_wait(proc->p_cv, proc->p_sleeplock);	
	}
	//get the exit status	
	int exit_status = proc->p_exit_code;
	lock_release(proc->p_sleeplock);
	proc_destroy(proc);	
	kprintf("====================\n");
	kprintf("Child process exited with status: %d\n", exit_status);	
	kprintf("====================\n");
	
	return exit_status;
}
