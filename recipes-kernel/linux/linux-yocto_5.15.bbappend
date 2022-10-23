#
# Copyright (C) 2020 Wind River Systems, Inc.
#

require linux-yocto-amd-x86.inc

KBRANCH:amd-x86  = "v5.15/standard/x86"

FILESEXTRAPATHS:prepend:amd-x86 := "${THISDIR}/files:"

SRC_URI:append:amd-x86 = " \
                          file://0001-amd-xgbe-Sometimes-driver-report-incorrect-link-stat.patch \
                          file://0002-amd-xgbe-KR-link-up-fix.patch \
                          file://0003-Fix-to-avoid-link-statys-update-in-KR-autneg-mode.patch \
                          file://0004-amd-xgbe-KR-link-up-fix-with-PHY-reset-if-AN-fails.patch \
                         "
