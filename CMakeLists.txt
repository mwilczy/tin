cmake_minimum_required(VERSION 3.10)
project(tin)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
#set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
#set(OPENSSL_LIBRARIES /usr/local/opt/openssl/lib)


add_executable(tin Broadcast.cpp main.cpp Server.cpp Server.h Client.cpp Client.h BinaryProtocol.cpp BinaryProtocol.h CliInterface.cpp CliInterface.h MerkleDag.cpp MerkleDag.h)

target_link_libraries(tin ${OPENSSL_LIBRARIES} pthread)