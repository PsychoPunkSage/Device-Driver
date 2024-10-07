def main():
    # Get `proc` file
    driver_handle = open("/proc/pps_driver")

    # Perform `READLINE` ops
    msg_from_kernel_space = driver_handle.readline()

    print(msg_from_kernel_space)
    driver_handle.close()
    return

main()