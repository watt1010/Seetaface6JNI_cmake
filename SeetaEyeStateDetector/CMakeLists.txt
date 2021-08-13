cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("SeetaEyeStateDetector_java")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/etc/jdk1.8.0_301/include)
include_directories(/usr/etc/jdk1.8.0_301/include/linux)
include_directories(../include)
# 搜索代码源文件存放在 project_src 变量中
AUX_SOURCE_DIRECTORY(../Landmarker project_src)
add_library( # Sets the name of the library.
        ${PROJECT_NAME}

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${project_src})

add_library(TenniS SHARED IMPORTED)
set_target_properties(TenniS PROPERTIES IMPORTED_LOCATION  ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/centos/libtennis.so)

add_library(SeetaAuthorize SHARED IMPORTED)
set_target_properties(SeetaAuthorize PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/centos/libSeetaAuthorize.so)

add_library(SeetaEyeStateDetector SHARED IMPORTED)
set_target_properties(SeetaEyeStateDetector PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/centos/libSeetaEyeStateDetector200.so)


target_link_libraries( # Specifies the target library.
        ${PROJECT_NAME}
        TenniS
        SeetaAuthorize
        SeetaEyeStateDetector
        )