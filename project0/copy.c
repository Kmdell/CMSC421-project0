// Name: Kyle Dell
// Class: CMSC421 - Section 3
// Prof: Tompkins
// Email: kdell1@umbc.edu
// Date: 9/14/2022
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/errno.h>

SYSCALL_DEFINE3(memory_copy, unsigned char __user *, to, unsigned char __user *, from, int, size) {
  unsigned char value;
  int i = 0;

  // check the pointer to ensure that it is accessible, if 0 errors out with -EFAULT
  if(!access_ok(to, size)) {
    return -EFAULT;
  }

  if(!access_ok(from, size)) {
    return -EFAULT;
  }

  // goes through the pointers array getting the value and putting it into user space other pointer with errors when rc is 0
  for(i = 0; i < size; i++) { 
    if(get_user(value, from + i)) {
      return -EFAULT;
    }
  
    if(put_user(value, to + i)) {
      return -EFAULT;
    }
  }

  return 0;
}
