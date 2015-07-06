cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_COMPILER /usr/bin/gcc) 
set(CMAKE_CXX_COMPILER ${CMAKE_C_COMPILER})

project(FP)
include(src/zeromq.cmake)

# include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/moe/workspace/install_zmq_arm) # moe arm dir install loc zmq
# link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/moe/workspace/install_zmq_arm) #arm moe
# include_directories(/home/moe/workspace/install_zmq_arm/include) # arm moe

 include_directories(/home/pi/zeromq) # arm pi
 link_directories(/home/pi/zeromq) #arm pi
 include_directories(/home/pi/zeromq/include) # arm pi

# include_directories(${ZYNQ_THEEND_SOURCE_DIR}/home/moe/workspace/install_zmq) # x86 moe
# link_directories(${ZYNQ_THEEND_BINARY_DIR}/home/moe/workspace/install_zmq) # x86 moe
# include_directories(/home/moe/workspace/install_zmq/include) # x86 moe

#include_directories(/home/user/zeromq) # vserver
#link_directories(/home/user/zeromq) # vserver
#include_directories(/home/user/zeromq/include) # verserver

# include_directories(/home/toni/Downloads/zeromq) # x86 toni
# link_directories(/home/toni/Downloads/zeromq) #x86 toni
# include_directories(/home/toni/Downloads/zeromq/include) # x86 toni

include_directories(/usr/include/mysql/)
add_executable(main_s ../db/main_s.cpp)

 target_link_libraries(main_s /lib/arm-linux-gnueabihf/libm.so.6 /usr/lib/arm-linux-gnueabihf/libmysqlclient.a -lwiringPi -lrt -ldl -lz -lm zeromq pthread stdc++  ) # arm

# target_link_libraries(main_s /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # vserver

# target_link_libraries(main_s /usr/lib/libm.so.6 /usr/lib/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # x86 toni

#target_link_libraries(main_s /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # x86 moe

add_executable(main_c ../db/main_c.cpp)

target_link_libraries(main_c /lib/arm-linux-gnueabihf/libm.so.6 /usr/lib/arm-linux-gnueabihf/libmysqlclient.a -lwiringPi -lrt -ldl -lz -lm zeromq pthread stdc++  ) # arm

# target_link_libraries(main_c /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) # versver

# target_link_libraries(main_c /usr/lib/libm.so.6 /usr/lib/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) #x86 toni

#target_link_libraries(main_c /lib/x86_64-linux-gnu/libm.so.6 /usr/lib/x86_64-linux-gnu/libmysqlclient.so -lwiringPi -ldl -lz -lm zeromq pthread stdc++  ) #x86 moe

##add_executable(FP_2c FP_2c.cpp)
##target_link_libraries(FP_2c zeromq pthread stdc++)

set(CMAKE_CXX_FLAGS " -O2")
set(CMAKE_LD1_FLAGS " -g -Wall")
