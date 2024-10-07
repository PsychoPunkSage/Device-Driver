#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abhinav Prakash - PsychoPunkSage");
MODULE_DESCRIPTION("Basic READ/WRITE loadable kernel module");

static struct proc_dir_entry *custom_proc_entry; // <https://github.com/torvalds/linux/blob/master/include/linux/proc_fs.h>

// ssize_t	(*proc_read)(struct file *, char __user *, size_t, loff_t *);
static ssize_t pps_read(struct file *file_pointer, char *user_space_buffer, size_t count, loff_t *offset)
{
    // Kernel will provide all the above params
    char msg[] = "Yoiii!!\n";
    size_t /* Standard size CPU can handle */ len = strlen(msg);
    int res;

    printk("[PPS] module Read\n");

    if (*offset >= len)
        return 0; // Keep track of location to read from in given buffer
    res = copy_to_user(/*dst*/ user_space_buffer, /*src*/ msg, /*no_of_bytes*/ len);
    *offset += len;
    return len; // need to return no. of bytes we are writing to `user space`
}

struct proc_ops pps_proc_ops = {
    .proc_read = pps_read};

static int pps_driver_init(void)
{
    printk("[PPS] module init:entry\n");

    // struct proc_dir_entry *proc_create(const char *name, umode_t mode, struct proc_dir_entry *parent, const struct proc_ops *proc_ops)
    custom_proc_entry = proc_create("pps_driver", 0, NULL, &pps_proc_ops);

    if (custom_proc_entry == NULL)
    {
        printk("[PPS] module init:dirty failure\n");
        return -1;
    }

    printk("[PPS] module init:exit\n");
    return 0;
}

static void pps_driver_exit(void)
{
    printk("[PPS] module exit:entry\n");
    // Delete entry
    // extern void proc_remove(struct proc_dir_entry *);
    proc_remove(custom_proc_entry);
    printk("[PPS] module exit:exit\n");
}

module_init(pps_driver_init);
module_exit(pps_driver_exit);