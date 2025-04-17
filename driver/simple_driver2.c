#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/mutex.h>

#define NAME "char_driver"

static dev_t dev;
static struct cdev mycdev;
static struct class *myclass;
static char buf[1024];
static DEFINE_MUTEX(my_mutex);

static int my_open(struct inode* _inodep, struct file* _filep) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int my_release(struct inode* _inodep, struct file* _filep) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t my_read(struct file* _filep, char __user* _user_buffer, size_t size, loff_t* _offsetp) {
    int len;

    mutex_lock(&my_mutex);

    len = strnlen(buf, sizeof(buf));

    if (size > len) size = len;

    if (copy_to_user(_user_buffer, buf, size)) {
        mutex_unlock(&my_mutex); 
        return -EFAULT;
    }

    buf[0] = '\0'; 

    mutex_unlock(&my_mutex);

    printk(KERN_INFO "Data read: %s\n", buf);
    
    return size; 
}

static ssize_t my_write(struct file* _filep, const char __user* _user_buffer, size_t size, loff_t* _offsetp) {
    int len = sizeof(buf) - 1;

    mutex_lock(&my_mutex);

    if (size > len) size = len;

    if (copy_from_user(buf, _user_buffer, size)) {
        mutex_unlock(&my_mutex);
        return -EFAULT;
    }

    buf[size] = '\0';

    mutex_unlock(&my_mutex);

    printk(KERN_INFO "Data written: %s\n", buf);
    
    return size; 
}

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .read = my_read,
    .write = my_write,
};

int my_init(void) {
    int ret = alloc_chrdev_region(&dev, 0, 1, NAME);
    if (ret < 0) {
        printk(KERN_ALERT "Region allocation failed\n");
        return ret;
    }

    cdev_init(&mycdev, &fops);
    
    ret = cdev_add(&mycdev, dev, 1);
    
    myclass = class_create(THIS_MODULE, "mychardev");
    
    if (IS_ERR(myclass)) {
        cdev_del(&mycdev);
        unregister_chrdev_region(dev, 1);
        printk(KERN_ALERT "Failed to create class\n");
        return PTR_ERR(myclass);
    }

    if (IS_ERR(device_create(myclass, NULL, dev, NULL, NAME))) {
        class_destroy(myclass);
        cdev_del(&mycdev);
        unregister_chrdev_region(dev, 1);
        printk(KERN_ALERT "Failed to create device\n");
        return PTR_ERR(myclass);
    }

    printk(KERN_INFO "Allocated device number: %d %d\n", MAJOR(dev), MINOR(dev));
    
    return 0;
}

void my_exit(void) {
    device_destroy(myclass, dev);
    class_destroy(myclass);
    cdev_del(&mycdev);
    unregister_chrdev_region(dev, 1);
    
    printk(KERN_INFO "Module exited\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("me");
MODULE_DESCRIPTION("A simple character driver");

module_init(my_init);
module_exit(my_exit);
