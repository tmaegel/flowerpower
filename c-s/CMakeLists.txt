cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabi-gcc) #arm
#set(CMAKE_C_COMPILER /usr/bin/gcc-4.8) #x86
set(CMAKE_CXX_COMPILER ${CMAKE_C_COMPILER})

project(FP)
include(src/zeromq.cmake)


include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/moe/workspace/install_zmq_arm) # arm dir install loc zmq
link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/moe/workspace/install_zmq_arm) #arm 
#include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/moe/workspace/install_zmq) # x86
#link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/moe/workspace/install_zmq) #x86
include_directories(/home/moe/workspace/install_zmq_arm/include) # arm
#include_directories(/home/moe/workspace/install_zmq/include) # x86
include_directories(/usr/include/mysql/)
add_executable(main_s /home/moe/workspace/fp_github/flowerpower/db/main_s.cpp) 
target_link_libraries(main_s /home/moe/workspace/petalinux-v2014.4-final/tools/linux-i386/arm-xilinx-linux-gnueabi/arm-xilinx-linux-gnueabi/libc/lib/libm.so.6
 /usr/lib/x86_64-linux-gnu/libmysqlclient.a -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # arm
#target_link_libraries(main_s /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.a -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # x86

add_executable(main_c /home/moe/workspace/fp_github/flowerpower/db/main_c.cpp)
target_link_libraries(main_c /home/moe/workspace/petalinux-v2014.4-final/tools/linux-i386/arm-xilinx-linux-gnueabi/arm-xilinx-linux-gnueabi/libc/lib/libm.so.6
 /usr/lib/x86_64-linux-gnu/libmysqlclient.a -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # arm
#target_link_libraries(main_c /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.a -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) #x86

add_executable(FP_2c FP_2c.cpp)
target_link_libraries(FP_2c zeromq pthread stdc++)

set(CMAKE_CXX_FLAGS " -O2")
set(CMAKE_LD1_FLAGS " -g -Wall")
