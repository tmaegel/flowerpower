cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_COMPILER /opt/Xilinx/SDK/2014.3/gnu/arm/lin/bin/arm-xilinx-linux-gnueabi-gcc-4.8.3)
#set(CMAKE_C_COMPILER /opt/Xilinx/SDK/2014.3/gnu/arm/lin/bin/arm-xilinx-eabi-gcc-4.8.3)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tftpboot)
#set(CMAKE_C_COMPILER /usr/bin/gcc-4.8)
#set(CMAKE_CXX_COMPILER ${CMAKE_C_COMPILER})



project(zynq_theend)
#include(src/zeromq.cmake)
SET(COMMON_FLAGS "")
#set(COMMON_FLAGS"-Wall -O0 -g3 -c -fmessage-length=0 -I../../hello_dma_bsp/ps7_cortexa9_0/include")
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -std=c++11 -O2")
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,-T ${LINKER_SCRIPT} /home/mberghof/Desktop/720_bsp_full_snapshot_2014.2_3/720_bsp.sdk/hello_dma/src/lscript.ld")
#Set(CMAKE_CXX_LINK_EXECUTABLE "-Wl-T-Wl /home/mberghof/Desktop/720_bsp_full_snapshot_2014.2_3/720_bsp.sdk/hello_dma/src/lscript.ld")

#include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/mberghof/work/install_zmq_arm /usr/local/include/eigen3)
#link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/mberghof/work/install_zmq_arm)

#include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/mberghof/work/install_zmq)
#link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/mberghof/work/install_zmq)

include_directories(/home/mberghof/Desktop/720_bsp_full_snapshot_2014.2_3/720_bsp.sdk/hello_dma_bsp/ps7_cortexa9_0/include)
include_directories(/home/mberghof/Desktop/720_bsp_full_snapshot_2014.2_3/720_bsp.sdk/hello_dma/src)


#include_directories(/home/mberghof/work/install_zmq_arm/include)
#include_directories(/home/mberghof/work/install_zmq/include)

#add_executable(helloworld_s helloworld_s.cpp)
#target_link_libraries(helloworld_s zeromq pthread stdc++)
#add_executable(helloworld_c helloworld_c.cpp)
#target_link_libraries(helloworld_c zeromq pthread stdc++)
#add_executable(gpio_driver gpio_driver.cpp)
#target_link_libraries(gpio_driver zeromq pthread stdc++)
#add_executable(test_zyann test_zyann.cpp)
#target_link_libraries(test_zyann /opt/Xilinx/SDK/2014.3/gnu/arm/lin/arm-xilinx-linux-gnueabi/libc/lib/libm.so.6 zeromq pthread stdc++)
#add_executable(test_cpu test_cpu.cpp)
#target_link_libraries(test_cpu /opt/Xilinx/SDK/2014.3/gnu/arm/lin/arm-xilinx-linux-gnueabi/libc/lib/libm.so.6 zeromq pthread stdc++)
add_executable(poll poll.cpp)
target_link_libraries(poll /opt/Xilinx/SDK/2014.3/gnu/arm/lin/arm-xilinx-linux-gnueabi/libc/lib/libm.so.6 /home/mberghof/Desktop/720_bsp_full_snapshot_2014.2_3/720_bsp.sdk/hello_dma_bsp/ps7_cortexa9_0/lib/libxil.a pthread stdc++)



	


set(CMAKE_LD1_FLAGS "-lg -Wall")




