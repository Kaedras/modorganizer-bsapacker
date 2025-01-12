cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0111 NEW)

set(MO2_CMAKE_DEPRECATED_UIBASE_INCLUDE ON)

project(bsa_packer)

if (UNIX)
	find_package(OpenGL REQUIRED)
endif()

add_subdirectory(src)

set(BSAPACKER_TESTING ${BSAPACKER_TESTING} CACHE BOOL "build tests for bsapacker plugin")
if(BSAPACKER_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()
