DEFAULTTUNE ?= "dbfp5"

require conf/machine/include/x86/arch-x86.inc
require conf/machine/include/x86/x86-base.inc

# AMD DB-FP5 64bit (Snowy Owl)
TUNEVALID[dbfp5] = "Enable AMD DB-FP5 (64 bit) specific processor optimizations"
TUNECONFLICTS[dbfp5] = "m32 mx32"
TUNE_ARCH .= "${@bb.utils.contains("TUNE_FEATURES", "dbfp5", "${X86ARCH64}", "" ,d)}"
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "dbfp5", " -march=znver1 ${DBFP5_TUNE}", "", d)}"

# Extra tune selections
AVAILTUNES += "dbfp5"
TUNE_FEATURES:tune-dbfp5 = "dbfp5"
BASE_LIB:tune-dbfp5 = "lib64"
TUNE_PKGARCH:tune-dbfp5 = "dbfp5"
PACKAGE_EXTRA_ARCHS:tune-dbfp5 = "${TUNE_PKGARCH:tune-dbfp5}"
QEMU_EXTRAOPTIONS_dbfp5 = " -cpu EPYC-v3,check=false"

# If qemu-usermode is enabled, we have to disable avx2 ISA extensions, but we can keep mtune as znver1 as generic
# Reference: https://git.yoctoproject.org/meta-intel/commit/?id=0bc64c2ad39fbf2bcd4673c817f5f52a5b9be4be
DBFP5_TUNE .= "${@bb.utils.contains('MACHINE_FEATURES', 'qemu-usermode', ' -mtune=znver1 ${QEMU_UNAVAILABLE_ISA}', '', d)}"

QEMU_UNAVAILABLE_ISA = " \
-mno-bmi \
-mno-avx \
-mno-avx2 \
-mno-avx512f \
-mno-avx512er \
-mno-avx512cd \
-mno-avx512pf \
-mno-avx512dq \
-mno-avx512bw \
-mno-avx512vl \
-mno-avx512ifma \
-mno-avx512vbmi \
-mno-avx512vbmi2 \
-mno-avx512vnni \
-mno-avx512bitalg \
"
