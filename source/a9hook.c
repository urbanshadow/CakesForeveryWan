#include "a9hook.h"

#include "draw.h"
#include "menu.h"
#include "fs.h"

struct firm_hook firm_hooks[] = {
	{
		.version = 0x1B,
		.p9return = 0x080860A0
	},
	{
		.version = 0xFF,
		.p9return = 0
	}
};

int load_arm9_hook(unsigned int version){
	print("Copying hook to itcm...");
	if (read_file(((unsigned int*)A9H_ITCM_POS),"/cakes/arm9hook.bin", 0) != 0) {
        print("Failed to load arm9hook");
        draw_message("Failed to load arm9hook", "Please make sure arm9hook file\n  actually exists on the SD card.");
        return 1;
    }
	
	unsigned int i;
	
	for(i=0;firm_hooks[i].version != 0xFF;i++){
		if(version == firm_hooks[i].version) {
			*((unsigned int*)A9H_JUMPBACK) = firm_hooks[i].p9return;
			break;
		}
	}
	print("Hook copied succesfully!");
	
	return 0;
}