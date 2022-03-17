GDB=$(which arm-none-eabi-gdb)
INSTALL_DIR=$(pwd)/build/artifacts
BUILD_TYPE=Release
TARGET=$1

set -x

gdbfrontend --gdb-executable=${GDB} -G "${INSTALL_DIR}/${BUILD_TYPE}/bin/${TARGET}.elf"
