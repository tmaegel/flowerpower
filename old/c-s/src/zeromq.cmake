#set(SRC /home/pi/zeromq/src)
#set(SRC /home/moe/workspace/zeromq-4.0.5/src)
set(SRC /home/toni/Downloads/zeromq/src)
#set(SRC /home/user/zeromq/src)

add_library(zeromq STATIC
    ${SRC}/address.cpp
    ${SRC}/clock.cpp
    ${SRC}/ctx.cpp
    ${SRC}/dealer.cpp
    ${SRC}/devpoll.cpp
    ${SRC}/dist.cpp
    ${SRC}/epoll.cpp
    ${SRC}/err.cpp
    ${SRC}/fq.cpp
    ${SRC}/io_object.cpp
    ${SRC}/io_thread.cpp
    ${SRC}/ip.cpp
    ${SRC}/ipc_address.cpp
    ${SRC}/ipc_connecter.cpp
    ${SRC}/ipc_listener.cpp
    ${SRC}/kqueue.cpp
    ${SRC}/lb.cpp
    ${SRC}/mailbox.cpp
    ${SRC}/mechanism.cpp
    ${SRC}/msg.cpp
    ${SRC}/mtrie.cpp
    ${SRC}/null_mechanism.cpp
    ${SRC}/object.cpp
    ${SRC}/options.cpp
    ${SRC}/own.cpp
    ${SRC}/pair.cpp
    ${SRC}/pgm_receiver.cpp
    ${SRC}/pgm_sender.cpp
    ${SRC}/pgm_socket.cpp
    ${SRC}/pipe.cpp
    ${SRC}/plain_mechanism.cpp
    ${SRC}/poll.cpp
    ${SRC}/poller_base.cpp
    ${SRC}/proxy.cpp
    ${SRC}/pub.cpp
    ${SRC}/pull.cpp
    ${SRC}/push.cpp
    ${SRC}/random.cpp
    ${SRC}/raw_decoder.cpp
    ${SRC}/raw_encoder.cpp
    ${SRC}/reaper.cpp
    ${SRC}/rep.cpp
    ${SRC}/req.cpp
    ${SRC}/router.cpp
    ${SRC}/select.cpp
    ${SRC}/session_base.cpp
    ${SRC}/signaler.cpp
    ${SRC}/socket_base.cpp
    ${SRC}/stream.cpp
    ${SRC}/stream_engine.cpp
    ${SRC}/sub.cpp
    ${SRC}/tcp.cpp
    ${SRC}/tcp_address.cpp
    ${SRC}/tcp_connecter.cpp
    ${SRC}/tcp_listener.cpp
    ${SRC}/thread.cpp
    ${SRC}/trie.cpp
    ${SRC}/v1_decoder.cpp
    ${SRC}/v1_encoder.cpp
    ${SRC}/v2_decoder.cpp
    ${SRC}/v2_encoder.cpp
    ${SRC}/xpub.cpp
    ${SRC}/xsub.cpp
    ${SRC}/zmq.cpp
    ${SRC}/zmq_utils.cpp)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(ZMQ_HAVE_WINDOWS 1)
    target_link_libraries(zeromq
        ws2_32)
endif ()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(HAVE_ALLOCA_H 1)
    set(HAVE_ARPA_INET_H 1)
    set(HAVE_DLFCN_H 1)
    set(HAVE_ERRNO_H 1)
    set(HAVE_FORK 1)
    set(HAVE_FREEIFADDRS 1)
    set(HAVE_GETIFADDRS 1)
    set(HAVE_GETTIMEOFDAY 1)
    set(HAVE_IFADDRS_H 1)
    set(HAVE_INTTYPES_H 1)
    set(HAVE_LIBPTHREAD 1)
    set(HAVE_LIMITS_H 1)
    set(HAVE_MEMORY_H 1)
    set(HAVE_MEMSET 1)
    set(HAVE_NETINET_IN_H 1)
    set(HAVE_NETINET_TCP_H 1)
    set(HAVE_PERROR 1)
    set(HAVE_SOCKET 1)
    set(HAVE_STDBOOL_H 1)
    set(HAVE_STDDEF_H 1)
    set(HAVE_STDINT_H 1)
    set(HAVE_STDLIB_H 1)
    set(HAVE_STRINGS_H 1)
    set(HAVE_STRING_H 1)
    set(HAVE_SYS_SOCKET_H 1)
    set(HAVE_SYS_STAT_H 1)
    set(HAVE_SYS_TIME_H 1)
    set(HAVE_SYS_TYPES_H 1)
    set(HAVE_SYS_UIO_H 1)
    set(HAVE_TIME_H 1)
    set(HAVE_UNISTD_H 1)
    set(LT_OBJDIR \".libs/\")
    set(PACKAGE \"zeromq\")
    set(PACKAGE_BUGREPORT \"zeromq-dev@lists.zeromq.org\")
    set(PACKAGE_NAME \"zeromq\")
    set(PACKAGE_STRING \"zeromq 4.0.4\")
    set(PACKAGE_TARNAME \"zeromq\")
    set(PACKAGE_URL \"\")
    set(PACKAGE_VERSION \"4.0.4\")
    set(RETSIGTYPE void)
    set(STDC_HEADERS 1)
    set(TIME_WITH_SYS_TIME 1)
    set(VERSION \"4.0.4\")
    set(ZMQ_HAVE_IFADDRS 1)
    set(ZMQ_HAVE_OSX 1)
    set(ZMQ_HAVE_SO_KEEPALIVE 1)
    set(ZMQ_HAVE_TCP_KEEPALIVE 1)
    set(ZMQ_HAVE_TCP_KEEPCNT 1)
    set(ZMQ_HAVE_TCP_KEEPINTVL 1)
    set(ZMQ_HAVE_UIO 1)
    add_definitions(-D_DARWIN_C_SOURCE)
endif ()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_definitions(-D_GNU_SOURCE)
    set(HAVE_ALLOCA_H 1)
    set(HAVE_ARPA_INET_H 1)
    set(HAVE_CLOCK_GETTIME 1)
    set(HAVE_DLFCN_H 1)
    set(HAVE_ERRNO_H 1)
    set(HAVE_FORK 1)
    set(HAVE_FREEIFADDRS 1)
    set(HAVE_GETIFADDRS 1)
    set(HAVE_GETTIMEOFDAY 1)
    set(HAVE_IFADDRS_H 1)
    set(HAVE_INTTYPES_H 1)
    set(HAVE_LIBPTHREAD 1)
    set(HAVE_LIBRT 1)
    set(HAVE_LIMITS_H 1)
    set(HAVE_MEMORY_H 1)
    set(HAVE_MEMSET 1)
    set(HAVE_NETINET_IN_H 1)
    set(HAVE_NETINET_TCP_H 1)
    set(HAVE_PERROR 1)
    set(HAVE_SOCKET 1)
    set(HAVE_STDBOOL_H 1)
    set(HAVE_STDDEF_H 1)
    set(HAVE_STDINT_H 1)
    set(HAVE_STDLIB_H 1)
    set(HAVE_STRINGS_H 1)
    set(HAVE_STRING_H 1)
    set(HAVE_SYS_EVENTFD_H 1)
    set(HAVE_SYS_SOCKET_H 1)
    set(HAVE_SYS_STAT_H 1)
    set(HAVE_SYS_TIME_H 1)
    set(HAVE_SYS_TYPES_H 1)
    set(HAVE_SYS_UIO_H 1)
    set(HAVE_TIME_H 1)
    set(HAVE_UNISTD_H 1)
    set(LT_OBJDIR \".libs/\")
    set(PACKAGE \"zeromq\")
    set(PACKAGE_BUGREPORT \"zeromq-dev@lists.zeromq.org\")
    set(PACKAGE_NAME \"zeromq\")
    set(PACKAGE_STRING \"zeromq 4.0.4\")
    set(PACKAGE_TARNAME \"zeromq\")
    set(PACKAGE_URL \"\")
    set(PACKAGE_VERSION \"4.0.4\")
    set(RETSIGTYPE void)
    set(STDC_HEADERS 1)
    set(TIME_WITH_SYS_TIME 1)
    set(VERSION \"4.0.4\")
    set(ZMQ_HAVE_EVENTFD 1)
    set(ZMQ_HAVE_IFADDRS 1)
    set(ZMQ_HAVE_LINUX 1)
    set(ZMQ_HAVE_SOCK_CLOEXEC 1)
    set(ZMQ_HAVE_SO_KEEPALIVE 1)
    set(ZMQ_HAVE_TCP_KEEPCNT 1)
    set(ZMQ_HAVE_TCP_KEEPIDLE 1)
    set(ZMQ_HAVE_TCP_KEEPINTVL 1)
    set(ZMQ_HAVE_UIO 1)
endif ()

configure_file(${CMAKE_CURRENT_LIST_DIR}/zeromq.platform.hpp.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/zeromq_generated/platform.hpp)

#target_include_directories(zeromq
#    INTERFACE
 #       ${CMAKE_CURRENT_LIST_DIR}/home/pi/zeromq/include
  #      ${CMAKE_CURRENT_LIST_DIR}
   # PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/zeromq_generated)

#target_compile_definitions(zeromq
 #   PUBLIC ZMQ_STATIC)
