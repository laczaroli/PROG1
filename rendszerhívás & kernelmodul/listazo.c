#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/fdtable.h>

MODULE_DESCRIPTION ("Ez a PARP konyv bevezetesenek pelda modulja");
MODULE_AUTHOR ("Bátfai Norbert (nbatfai@gmail.com)");
MODULE_LICENSE ("GPL");

asmlinkage long
sys_listazo (void) {

	struct task_struct *task;
	struct list_head *p;

	printk (KERN_NOTICE "elindul\n");
	list_for_each (p, current->tasks.next){
		task = list_entry (p, struct task_struct, tasks);
		printk (KERN_NOTICE "%s %i %i\n", task->comm, task->pid, task->files->next_fd);
	}
	return 0;
}

