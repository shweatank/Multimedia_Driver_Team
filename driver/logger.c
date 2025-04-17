#include<linux/module.h>
#include<linux/fs.h>

static dev_t dev;

static int my_open(struct inode* inodep, struct file* filep){
  printk(KERN_INFO "device opened\n");
  return 0;
}

static int my_release(struct inode* inodep, struct file* filep){
  printk(KERN_INFO "device closed\n");
  return 0;
}

static ssize_t my_read(struct file* filep, char __user* user_buf, size_t size, loff_t* offsetp){
  printk(KERN_INFO "device read\n");
  return 0;
}

static ssize_t my_write(struct file* filep,const char __user* user_buf, size_t size, loff_t* offsetp){
  printk(KERN_INFO "written to the device\n");
  return 0;
}

struct file_operations f_ops = {
  .owner = THIS_MODULE,
  .open  = my_open,
  .release = my_release,
  .read = my_read,
  .write = my_write,
};

int my_init(void){
  printk(KERN_INFO "module attached\n");
  return 0;
}

void my_exit(void){
  printk(KERN_INFO "module detached\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
