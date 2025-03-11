#include<linux/module.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/types.h>

#define NAME "char_driver"

static dev_t dev;
static struct cdev mycdev;
static char buf[1024];

static int my_open(struct inode* _inodep, struct file* _filep){
	printk(KERN_INFO "opened\n");
	return 0;
}

static int my_release(struct inode* _inodep, struct file* _filep){
	printk(KERN_INFO "closed\n");
	return 0;
}

static ssize_t my_read(struct file* _filep, char __user* _user_buffer, size_t size, loff_t* _offsetp){
	int len = strlen(buf);
	if(len>size)size=len;
	if(copy_to_user(_user,buf,size))return -EFAULT;
	buf[0]='\0';
	printk(KERN_INFO "read\n");
	return size;
}

static ssize_t my_write(struct file* _filep, char __user* _user_buffer, size_t size, loff_t* _offsetp){
	int len = sizeof(buff);
	if(size>len-1)size=len-1;
	if(copy_from_user(_user,buf,size))return -EFAULT;
	buf[size]='\0';
	printk(KERN_INFO "read\n");
	return size;
}

int module_init(void){
	int ret = alloc_chrdev_region(dev,0,1,NAME);
	if(ret<0){
		printk(KERN_ALERT "region allocation failed\n");
		return ret;
	}
	printk(KERN_INFO "allocated device numbr: %d %d\n",MAJOR(dev),MINOR(dev));
	return 0;
}
	
void module_exit(void){
	int ret = (dev,0,1,NAME);
	if(ret<0){
		printk(KERN_ALERT "region allocation failed\n");
		return ret;
	}
	printk(KERN_INFO "allocated device numbr: %d %d\n",MAJOR(dev),MINOR(dev));
	return 0;
}
