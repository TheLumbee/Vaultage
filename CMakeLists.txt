cmake_minimum_required(VERSION 3.20)
project(vaultage VERSION 0.1)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++23 -stdlib=libc++ -Wall -Werror -Wextra -Wpedantic -Wno-keyword-macro")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++23 -Wall -Werror -Wextra -Wpedantic -Wno-keyword-macro")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY ${PROJECT_SOURCE_DIR}/third_party/googletest
    GIT_TAG origin/main
)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY ${PROJECT_SOURCE_DIR}/third_party/spdlog
    GIT_TAG origin/v1.x
)

FetchContent_MakeAvailable(
    googletest
    spdlog
)

enable_testing()

add_subdirectory(app/desktop)