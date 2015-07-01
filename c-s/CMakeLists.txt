cmake_minimum_required(VERSION 2.6)
# set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabi-gcc) #arm
set(CMAKE_C_COMPILER /usr/bin/gcc) #x86 moe
#set(CMAKE_C_COMPILER /usr/bin/x86_64-unknown-linux-gnu-gcc-5.1.0) #x86 toni
set(CMAKE_CXX_COMPILER ${CMAKE_C_COMPILER})

project(FP)
include(src/zeromq.cmake)

# include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/moe/workspace/install_zmq_arm) # moe arm dir install loc zmq
# link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/moe/workspace/install_zmq_arm) #arm moe
# include_directories(/home/moe/workspace/install_zmq_arm/include) # arm moe

 include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/moe/workspace/install_zmq) # x86 moe
 link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/moe/workspace/install_zmq) # x86 moe
 include_directories(/home/moe/workspace/install_zmq/include) # x86 moe


#include_directories(/home/toni/Downloads/zeromq) # x86 toni
#link_directories(/home/toni/Downloads/zeromq) #x86 toni
#include_directories(/home/toni/Downloads/zeromq/include) # x86 toni

# include_directories(/home/toni/Downloads/zeromq) # x86
# link_directories(/home/toni/Downloads/zeromq) #x86
# include_directories(/usr/include) # x86





include_directories(/usr/include/mysql/)
add_executable(main_s ../db/main_s.cpp)

# target_link_libraries(main_s /home/moe/workspace/petalinux-v2014.4-final/tools/linux-i386/arm-xilinx-linux-gnueabi/arm-xilinx-linux-gnueabi/libc/lib/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.a -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # arm

#target_link_libraries(main_s usr/lib/libm.so.6 /usr/lib/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # x86 toni

target_link_libraries(main_s /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # x86 moe

add_executable(main_c ../db/main_c.cpp)

# target_link_libraries(main_c /home/moe/workspace/petalinux-v2014.4-final/tools/linux-i386/arm-xilinx-linux-gnueabi/arm-xilinx-linux-gnueabi/libc/lib/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.a -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # arm

#target_link_libraries(main_c usr/lib/libm.so.6 /usr/lib/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) #x86 toni

target_link_libraries(main_c /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) #x86 moe

add_executable(FP_2c FP_2c.cpp)
target_link_libraries(FP_2c zeromq pthread stdc++)

set(CMAKE_CXX_FLAGS " -O2")
set(CMAKE_LD1_FLAGS " -g -Wall")
