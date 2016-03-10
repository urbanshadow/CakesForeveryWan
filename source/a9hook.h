#define A9H_JUMPBACK 0x01FFB63C
#define A9H_ITCM_POS 0x01FFB638

struct firm_hook {
    unsigned int version;
    unsigned int p9return;
};

int load_arm9_hook(unsigned int);