# Commands

### Kernel Log buffer

```sh
sudo dmesg
```

### Inject `kernel module` inside Kernel

```sh
sudo insmod <name>.ko
echo $? # Check the status
```

### Get `kernel module` info

```sh
modinfo <name>.ko
```

### Delete/Remove the module

```sh
sudo rmmod <name>
```

### List all the modules

```sh
lsmod
lsmod | wc -l # No. of modules
lsmod | grep <module name> # Check: whether module is accepted or not.
```

## insmod module

1. calls `init_module` to tell kernel that module insertion is attempted
2. Transfer control to kernel
3. Kernel execute `sys_init_module`
4. Permission verification of requestor
5. `load_module` function is called
   1. Checks sanity of `.ko`
   2. Creates memory
   3. Copies from user -> kernel space
   4. Resolves symbols
   5. Returns a reference to kernel
6. Add reference to **LINKED LIST** of all the loaded modules
7. `module_init` is called
   1. if this `fails`: Everything will work backwards & return error @step1

## rmmod module

1. calls `delete_module()` to tell kernel that module deletion is attempted
2. Transfer control to kernel
3. Kernel execute `sys_delete_module`
   1. Permission checks of requestor
   2. Check for **dependent modules** for current module
   3. Check for presence of module
   4. Call `module_exit` function
   5. `free_module()`
      1. removes references and kernel object references
      2. perform remaining cleanup
      3. unloads modules
      4. changes the state in list
      5. removes it from the list and frees the memory