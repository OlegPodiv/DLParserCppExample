cmake_minimum_required(VERSION 3.16)
project(DLParserCppExample)

set(CMAKE_CXX_STANDARD 14)

add_executable(DLParserCppExample main.cpp)
add_library(libidscan_parser SHARED IMPORTED)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

        if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86")
            set(SOURCE_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/libs/linux/x86)
        else(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x64")
            set(SOURCE_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/libs/linux/x86_64)
        endif()

set_property(TARGET libidscan_parser PROPERTY  IMPORTED_LOCATION ${SOURCE_LIBS}/libidscan_parser.so)
target_link_libraries(DLParserCppExample libidscan_parser)

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

        if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86")
            set(SOURCE_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/libs/windows/win_x86)
         else(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x64")
            set(SOURCE_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/libs/windows/win_x86_64)
        endif()

set_property(TARGET libidscan_parser PROPERTY  IMPORTED_LOCATION ${SOURCE_LIBS}/libidscan_parser.dll)
target_link_libraries(DLParserCppExample libidscan_parser)

else()

endif()
