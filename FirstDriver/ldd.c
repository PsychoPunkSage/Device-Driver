#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");                                         //* Mandatory
MODULE_AUTHOR("PPS - PsychoPunkSage");                         //! Optional
MODULE_DESCRIPTION("First dynamically lodable kernel module"); //! Optional

static int pps_init(void)
{
    printk("Hello PsychoPunkSage!!\n");
    return 0;
}

static void pps_exit(void)
{
    printk("Good Bye!! (from PPS)\n");
}

// C Macros : can be called from outside of fn.
module_init(pps_init); // Constructor: Ops to perform at time of Module loading
module_exit(pps_exit); // Destructor: Ops to perform at time of Module deletion