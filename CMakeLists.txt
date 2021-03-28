# CMakeList.txt : CMake project for Decoder, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add preprocessor defines:
add_compile_definitions(ELEKTRA_SIM_20)
# add_compile_definitions(MATRIX_SIM_16x16)
# add_compile_definitions(MATRIX_SIM_10x10)
add_compile_definitions(GLOW_PROTOCOL_VERSION=1)
add_compile_definitions(LED_COUNT=20)
add_compile_definitions(SRAM_BUF_SZ=25600)

# Add source files:
file(GLOB projFiles
    "./*.h"
    "./*.c"
	"simulators/*.h"
	"simulators/*.c"
	"../GlowDecompiler/*.h"
	"../GlowDecompiler/*.c"
)
add_executable (simulator ${projFiles})
file(TO_NATIVE_PATH "${PROJECT_BINARY_DIR}" nativeBinaryDirPath) 
