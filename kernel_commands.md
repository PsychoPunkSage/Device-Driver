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