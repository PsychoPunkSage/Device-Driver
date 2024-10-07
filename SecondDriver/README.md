## RUN Guide:

> Buidl C program

```sh
make clean
make
```

> inject module in kernel

```sh
sudo insmod pps.ko
```

> check the module list & proc folder

```sh
lsmod | grep pps
# Must get some output

ls /proc/ | grep pps_driver
# Must get some output
```

> Run the Linux driver
1. via app
```sh
python3 app.py
```

2. via command-line

```sh
cat /proc/pps_driver
```