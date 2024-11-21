DEFAULTTUNE ?= "dbfp5-64"

require conf/machine/include/x86/arch-x86.inc
require conf/machine/include/x86/x86-base.inc

X86ARCH32 = "i686"

TUNEVALID[dbfp5] = "Enable AMD DB-FP5 (64 bit) specific processor optimizations"

TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "dbfp5", " -march=znver1 -mfpmath=sse", "", d)}"

AVAILTUNES += "dbfp5-32 dbfp5-64"
TUNE_FEATURES:tune-dbfp5-32 = "${TUNE_FEATURES:tune-x86} dbfp5"
TUNE_FEATURES:tune-dbfp5-64 = "${TUNE_FEATURES:tune-x86-64} dbfp5"

BASE_LIB:tune-dbfp5-32 = "lib"
BASE_LIB:tune-dbfp5-64 = "lib64"

TUNE_PKGARCH:tune-dbfp5-32 = "dbfp5-32"
TUNE_PKGARCH:tune-dbfp5-64 = "dbfp5-64"

PACKAGE_EXTRA_ARCHS:tune-dbfp5-32 = "${PACKAGE_EXTRA_ARCHS:tune-x86} dbfp5-32 "
PACKAGE_EXTRA_ARCHS:tune-dbfp5-64 = "${PACKAGE_EXTRA_ARCHS:tune-x86-64} dbfp5-64"

QEMU_EXTRAOPTIONS_dbfp5-32 = " -cpu EPYC-v3,check=false"
QEMU_EXTRAOPTIONS_dbfp5-64 = " -cpu EPYC-v3,check=false"

# When using AMD Snowy Owl specific tune flags, some packages are
# not compatible with some instruction sets in 32-bit multilib build.
TUNE_CCARGS:append:pn-lib32-rocksdb = "${@bb.utils.contains('TUNE_FEATURES', 'dbfp5', ' -mno-avx -mno-avx2 -mno-bmi -mno-bmi2 -mno-pclmul', '', d)}"
TUNE_CCARGS:append:pn-lib32-grpc = "${@bb.utils.contains('TUNE_FEATURES', 'dbfp5', ' -mno-bmi -mno-bmi2', '', d)}"
TUNE_CCARGS:append:pn-lib32-python3-grpcio = "${@bb.utils.contains('TUNE_FEATURES', 'dbfp5', ' -mno-bmi -mno-bmi2', '', d)}"
TUNE_CCARGS:append:pn-lib32-python3-mldtypes = "${@bb.utils.contains('TUNE_FEATURES', 'dbfp5', ' -mno-avx -mno-avx2', '', d)}"
TUNE_CCARGS:append:pn-lib32-gtk4 = "${@bb.utils.contains('TUNE_FEATURES', 'dbfp5', ' -mno-sse', '', d)}"

# Testcase of cve-2015-3290 in ltp doesn't work with AVX, so disable avx when using dbfp5 tune feature.
TUNE_CCARGS:append:pn-ltp = "${@bb.utils.contains('TUNE_FEATURES', 'dbfp5', ' -mno-avx', '', d)}"

# kexec-tools don't work with AVX, so disable it when using dbfp5 tune feature.
TUNE_CCARGS:append:pn-kexec-tools = "${@bb.utils.contains('TUNE_FEATURES', 'dbfp5', ' -mno-avx -mno-avx2', '', d)}"
