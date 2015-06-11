#include <stdint.h>
#include "fatfs/ff.h"
#include "../draw.h"
#include "menu.h"
#include "firm.h"

static FATFS fs;

// TODO: Put this in a nice place
void mount_sd()
{
    print("Mounting SD card");
    if (f_mount(&fs, "0:", 0) == FR_OK) {
        print("Mounted SD card");
    } else {
        print("Failed to mount SD card!");
    }
}

void unmount_sd()
{
    print("Unmounting SD card");
    f_mount((void *)0, "0:", 0);
    print("Unmounted SD card");
}

void menu_main()
{
    while (1) {
        char *options[] = {"Mount SD card", "Unmount SD card", "Read FIRM",
                           "Boot FIRM"};
        int result = draw_menu("Main menu", 0, sizeof(options) / sizeof(char *), options);

        switch (result) {
            case 0:
                mount_sd();
                break;
            case 1:
                unmount_sd();
                break;
            case 2:
                read_firm();
                break;
            case 3:
                boot_firm();
                break;
            default:
                print(options[result]);
        }
    }
}

void main()
{
    draw_init((uint32_t *)0x23FFFE00);
    print("Hello arm9!");
    menu_main();
}
