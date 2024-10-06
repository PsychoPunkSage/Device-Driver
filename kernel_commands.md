## Commands

### Kernel Log buffer

```sh
sudo dmesg
```

### Inject `kernel module` inside Kernel

```sh
sudo insmod <name>.ko
echo $? # Check the status
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