//make
//sudo insmod file.ko
//dmesg

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/fdtable.h>

MODULE_DESCRIPTION ("Ez a PARP konyv bevezetesenek pelda modulja");
MODULE_AUTHOR ("Bátfai Norbert (nbatfai@gmail.com)");
MODULE_LICENSE ("GPL");

static int fleiro_init (void) {

	struct task_struct *task;
	struct list_head *p;

	int i = 0;

	printk (KERN_NOTICE "elindul\n");
	list_for_each (p, current->tasks.next){
		task = list_entry (p, struct task_struct, tasks);
		i = task->files->next_fd;
		printk (KERN_NOTICE "%s %i %i\n", task->comm, task->pid, i);
	}
	return 0;
}
static void fleiro_exit (void) {
	printk (KERN_NOTICE "fleiro modul kilep\n");
}


module_init (fleiro_init);
module_exit (fleiro_exit);
