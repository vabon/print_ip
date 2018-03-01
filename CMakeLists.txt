cmake_minimum_required(VERSION 3.2)

project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(print_ip main.cpp)

add_library(print_ip_lib print_ip_lib.cpp)

add_executable(test_print_ip test_print_ip.cpp)

add_executable(test_print_ip_any test_print_ip_any.cpp)

set_target_properties(print_ip print_ip_lib test_print_ip test_print_ip_any PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_print_ip test_print_ip_any PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(print_ip
    print_ip_lib
)

target_link_libraries(test_print_ip
    ${Boost_LIBRARIES}
    print_ip_lib
)

target_link_libraries(test_print_ip_any
    ${Boost_LIBRARIES}
    print_ip_lib
)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@mail.com)

include(CPack)

enable_testing()

add_test(test_print_ip test_print_ip)

add_test(test_print_ip_any test_print_ip_any)
