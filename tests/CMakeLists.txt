cmake_minimum_required(VERSION 3.22)

find_package(Qt6 CONFIG REQUIRED COMPONENTS Core)
find_package(mo2-uibase CONFIG REQUIRED)

add_executable(bsa_packer_tests)
mo2_configure_tests(bsa_packer_tests
	WARNINGS OFF DEPENDS bsa_packer)
target_include_directories(bsa_packer_tests PRIVATE ../src)
target_link_libraries(bsa_packer_tests PRIVATE bsa_packer Qt6::Core mo2::uibase)