cmake_minimum_required(VERSION 3.16)

set(MO2_CMAKE_DEPRECATED_UIBASE_INCLUDE ON)

project(bsa_packer)

if(UNIX)
	include(FindOpenGL)
	find_package(OpenGL REQUIRED)
endif()

add_subdirectory(src)

set(BUILD_TESTING ${BUILD_TESTING} CACHE BOOL "build tests for bsapacker plugin")
if(BUILD_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()
