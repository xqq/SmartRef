cmake_minimum_required(VERSION 3.2)
project(smartref-test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Atomic.hpp Atomic_GCC.hpp Atomic_Win32.hpp Noncopyable.hpp RefBase.hpp RefPtr.hpp SmartRef.hpp test.cpp)

add_executable(smartref-test ${SOURCE_FILES})