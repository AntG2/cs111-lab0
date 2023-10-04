#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry;

static int proc_count(struct seq_file *m, void *v){
	struct task_struct *p;
	int count = 0;
       	char num[20];
	int i = 0;
	int digit, cp, len;
	
	for_each_process(p) {
	  count++;
	}

	cp = count;
	len = 0;
	while (cp != 0)
	{
	  len++;
	  cp = cp / 10;
	}

	
        while (i < len)
	{
	  digit = count % 10;
	  count = count / 10;
	  num[len - (i + 1)] = digit + '0';
	  i++;
	}
	num[len] = '\n';
	num[len + 1] = '\0';
	seq_printf(m, num);
	return 0;
}

static int __init proc_count_init(void)
{
	entry = proc_create_single("count", 0, NULL, proc_count);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("CS111 lab0 count proc number");
MODULE_LICENSE("GPL");
