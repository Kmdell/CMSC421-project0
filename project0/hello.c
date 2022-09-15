// Name: Kyle Dell
// Class: CMSC421 - Section 3
// Prof: Tompkins
// Email: kdell1@umbc.edu
// Date: 9/14/2022
#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(hello) {
  printk("Hello World!\n");
  return 0;
}
