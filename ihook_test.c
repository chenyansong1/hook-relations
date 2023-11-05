
#include <linux/kernel.h>
#include <linux/module.h>

#include "includes/syscalls.h"




static int ihook_init(void)
{
	int ret;

    ret = SYSCALLS_set_hooks();
    if (ret){
        printk(" SYSCALLS_set_hooks fail! ret = %d.\n ", ret);
        return ret;
    }

    printk(" SYSCALLS_set_hooks succeed!\n ");

	return 0;
}

static void ihook_exit(void)
{
    int ret;

    
    ret = SYSCALLS_remove_hooks();
    if (ret){
        printk(" SYSCALLS_remove_hooks fail! ret = %d.\n ", ret);
    }

    printk(" SYSCALLS_remove_hooks succeed!\n ");
}



module_init(ihook_init);
module_exit(ihook_exit);

MODULE_LICENSE("GPL");

