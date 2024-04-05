#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<libusb-1.0/libusb.h>

int main(int argc, char **argv) {
    int status;
    unsigned char value = 0;

    status = libusb_init(NULL);
    if (status !=0) {
        perror("Error init libusb");
        return -status;
    }

    libusb_device_handle *devh = NULL;

    devh = libusb_open_device_with_vid_pid(NULL, 0x0079, 0x1844);
    if (devh == NULL) {
        printf("Error! Could not find USB device!\n");
        libusb_exit(NULL);
        return -1;
    }

    int byte_count;

    status = libusb_interrupt_transfer(devh, 0x81, &value, 64, &byte_count, 100); 
    if (status != 0) {
        printf("This did not read\n");
        perror("Error this");
        libusb_close(devh);
        libusb_exit(NULL);
        return -status;
    }

    printf("The byte count is: %d\n", byte_count);
    printf("The data read is: %d\n", value);
    

   // int running = 1;
   // while (running) {
   //     value = 0;
   //     printf("Halfway!");
   //     status = libusb_control_transfer(dev, 0xC0, 0x2, 0, 0, (unsigned char *) &value, 1, 100);
   //     if (status > 0) {
   //         printf("ITS ALIVE!!!!");
   //     }
   // }


    libusb_close(devh);
    libusb_exit(NULL);
    return 0;
}
