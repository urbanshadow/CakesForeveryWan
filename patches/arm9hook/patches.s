.arm.little

.create "patch1.bin"
.arm
	.word 0x01FFB69C
.close

.create "patch2.bin"
.arm
	.word 0x080860A0
.close