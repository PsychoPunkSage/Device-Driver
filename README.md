# Linux Driver Demonstration

`Kernel` helps in management of `Processes and Hardware`<br>
`Kernel Drivers` are used to `manage hardwares`

**`loc`**: Stored as `collection of files` in SSD/HDD. <br>
**`exec`**: Must be loaded on `DRAM`(turned ON by ROM at later stages of booting - `Bootloader`) from where CPU will execute it.<br>
**`dtb`**: (Device Tree Blob) used to tell kernel about system hardware. It contains information about all the hardware and their memory location. (reside in `SSD/HDD` and its address in present in `CPU Registry`)

## Instruments:
| Tools      | Reason                                                                             |
| ---------- | ---------------------------------------------------------------------------------- |
| ssh        | connect coding env with our Machine.                                               |
| Multipass  | cmd-line tool to create environment ([Installation + Setup Guide](./Mutlipass.md)) |
| proc files | to implement `read()` and `write()` functions                                      |


## Utilities:
> `C` code => `Kernel` Module<br>
>   * We require Build Tools
>   * `Header Files` related to current version of Linux Kernel we have.
>   * `kmod` deals with building Kernel modules etc.

```sh
sudo apt update
sudo apt upgrade
sudo apt install -y build-essential linux-headers-$(uname -r) kmod
```