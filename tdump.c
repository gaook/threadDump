#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
// this version is for kernel 2.6.35.11
static int hello_init(void)
{
    printk(KERN_ERR"Thread back trace dump!!!\n");
    {
        struct task_struct *g, *p;
        //print unsleeping thread first
        printk(KERN_ERR"Threads unsleeping...\n");
        do_each_thread(g, p) {
            if(p->state == TASK_INTERRUPTIBLE)
            	continue;
            printk(KERN_ERR"< pid = %d , tgid = %d \n",p->pid,p->tgid);
            sched_show_task(p);
            printk(KERN_ERR"> \n");
        } while_each_thread(g, p);
        
        printk(KERN_ERR"\n\nThreads ALL...\n");
        do_each_thread(g, p) {
            printk(KERN_ERR"< pid = %d , tgid = %d \n",p->pid,p->tgid);
            sched_show_task(p);
            printk(KERN_ERR"> \n");
        } while_each_thread(g, p);
    }
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ERR"Out out \n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Austin");
MODULE_DESCRIPTION("A dumpping module");

