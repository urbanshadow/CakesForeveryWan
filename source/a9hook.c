#include "a9hook.h"

#include "draw.h"
#include "fs.h"


int load_arm9_hook(unsigned int version){
	print("Copying hook to itcm...");
	if (read_file(((unsigned int*)A9H_ITCM_POS),"/cakes/arm9hook.bin", 0) != 0) {
        print("Failed to load arm9hook.bin file!");
        //draw_message("Failed to load arm9hook", "Please make sure arm9hook file\n  actually exists on the SD card.");
        return 1;
    }

	print("Hook copied succesfully!");
	
	return 0;
}