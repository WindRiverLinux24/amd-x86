COMPATIBLE_MACHINE:amd-x86 = "${MACHINE}"

#add the depends of cdrtools-native to make sure it is
#always built to support the usb-image & iso-image UEFI
#booting by default  without explicitly add the configure
#option of "--enable-bootimage=iso"

DEPENDS:append:amd-x86 = " cdrtools-native"

# A method to install/update for bzImage on a deployed target
KERNELLOADEREXTENSION:append:amd-x86 = " kernel-grub"

TARGET_SUPPORTED_KTYPES:amd-x86 = "standard preempt-rt"

KMACHINE:amd-snowyowl-64 = "amd-x86-64"
