cmake_minimum_required(VERSION 3.16)
if (CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    message("Current platform: Linux")
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows") 
    message("Current platform: Windows")
else()
    message("Current platform: Unknown")
endif()

get_filename_component(ROOT_NAME ${CMAKE_SOURCE_DIR} NAME) #第一个是变量，第二个是路径，第三个代表是提取路径中的文件名部分
message("Configure project: ${ROOT_NAME}")
project(${ROOT_NAME} VERSION 0.1 LANGUAGES CXX)

#强制使用CPP 17 version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_INSTALL_PREFIX}/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_INSTALL_PREFIX}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_INSTALL_PREFIX}/RelWithDebInfo)  
set(CMAKE_DEBUG_POSTFIX "d")

#设置某个属性 GLOBAL:全局cmake工程有效 USE_FOLDERS：是否使用文件夹视图
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(Apps)
add_subdirectory(Modules)