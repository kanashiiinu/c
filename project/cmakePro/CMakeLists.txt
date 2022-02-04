cmake_minimum_required(VERSION 3.0.0)
project(project VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(project main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
AUX_SOURCE_DIRECTORY(. SRC_LIST)
#生成应用程序 hello
ADD_EXECUTABLE(proStruct ${SRC_LIST})