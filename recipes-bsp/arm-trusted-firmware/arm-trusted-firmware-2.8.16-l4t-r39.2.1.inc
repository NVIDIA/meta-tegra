HOMEPAGE = "https://www.trustedfirmware.org/projects/tf-a/"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://docs/license.rst;md5=b2c740efedc159745b9b31f88ff03dde"

TARGET_SOC ??= "t264"
TEGRA_SRC_SUBARCHIVE = "Linux_for_Tegra/source/atf_${TARGET_SOC}_src.tbz2"
require recipes-bsp/tegra-sources/tegra-sources-39.2.1.inc

S = "${UNPACKDIR}/arm-trusted-firmware.${TARGET_SOC}"
B = "${WORKDIR}/build"

inherit l4t_cve

CVE_PRODUCT = "trustedfirmware:trusted_firmware-a \
               arm:trusted_firmware-a \
               arm:arm-trusted-firmware \
               arm:arm_trusted_firmware"

CVE_STATUS[CVE-2022-47630] = "not-applicable-config: TRUSTED_BOARD_BOOT is disabled, the vulnerable X.509 parser is not built"
CVE_STATUS[CVE-2023-31339] = "not-applicable-platform: applies to AMD Zynq UltraScale+ MPSoC/RFSoC platform code, not Tegra"

TOOLCHAIN = "gcc"
