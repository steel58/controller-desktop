#include<libusb-1.0/libusb.h>
#include <stdio.h>

int main(void) {
    libusb_context *ctx;
    int init = libusb_init_context(&ctx, NULL, 0);
    printf("%d", LIBUSB_ERROR_IO);

    //if (init != 0) {
    //    printf("Error initializing libusb");
    //    return 1;
    //}

    //libusb_device **list;
    //libusb_device *found = NULL;
    //ssize_t cnt = libusb_get_device_list(NULL, &list);
    //ssize_t i = 0;
    //int err = 0;

    //if (cnt < 0) {
    //    return 0;
    //}

    //for (i = 0; i < cnt; i++) {
    //    libusb_device *device = list[i];
    //    libusb_device_handle *handle;

    //    

    //}

    //libusb_free_device_list(list, 1);
    libusb_exit(ctx);
    return 0;
}
