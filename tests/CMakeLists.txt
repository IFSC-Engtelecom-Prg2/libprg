cmake_minimum_required(VERSION 3.21)

set(CMAKE_C_STANDARD 17)
if ("${MUNIT_GIT_TAG}" STREQUAL "")
  set(MUNIT_GIT_TAG master)
endif ()

# Aqui se inclui o projeto munit, que auxilia a criação de testes de unidade
include(FetchContent)
FetchContent_Declare(munit
        GIT_REPOSITORY https://github.com/nemequ/munit.git
        GIT_TAG "${MUNIT_GIT_TAG}"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
)
FetchContent_Populate(munit)

add_library(munit ${munit_SOURCE_DIR}/munit.c)
target_include_directories(munit SYSTEM PUBLIC ${munit_SOURCE_DIR})
# fim das coisas do munit

#add_subdirectory(libprg)
include_directories(libprg/src/include)

add_executable(teste demo_test.c)
target_link_libraries(teste munit libprg)

# https://cmake.org/cmake/help/book/mastering-cmake/chapter/Packaging%20With%20CPack.html
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
#
#if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
#  # For IDEs indexing
#  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#endif()

