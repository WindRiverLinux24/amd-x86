PACKAGECONFIG:append:amd-x86 = " gallium-llvm"
GALLIUMDRIVERS_LLVM:append:amd-x86 = ",radeonsi"

do_generate_llvmlib_link:class-target:amd-x86 () {
    cd ${RECIPE_SYSROOT}${nonarch_libdir}
    ln -s ../${baselib}/libLLVM* ./
}

do_generate_llvmlib_link:virtclass-multilib-lib32 () {
    :
}

do_generate_llvmlib_link () {
    :
}

addtask do_generate_llvmlib_link before do_configure after do_prepare_recipe_sysroot
