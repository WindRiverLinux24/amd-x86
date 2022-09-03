IMAGE_INSTALL += "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', '', 'grub-efi', d)}"
IMAGE_INSTALL += "lmsensors"
IMAGE_INSTALL += "i2c-tools"
