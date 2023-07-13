cmake_minimum_required (VERSION 3.1)

project(GeometryTools)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(CMAKE_CXX_FLAGS_RELEASE "-Ox")
endif()


# Add dependencies
#find_package(OpenMP)
#if(OPENMP_FOUND)
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#endif()

# ------------------------------------------------------------------------------
set(DEMO GeometryTools)
set(SRC_DIR code)
include_directories(${SRC_DIR})
aux_source_directory(${SRC_DIR} SRC_FILES)
if (WIN32)
	add_library(${DEMO} STATIC
		${SRC_FILES}
		${SRC_DIR}/point.hpp
		${SRC_DIR}/point2.hpp
		${SRC_DIR}/triangle.hpp
		${SRC_DIR}/triangle2.hpp
		${SRC_DIR}/vector.hpp
	)
else()
	add_library(${DEMO} STATIC
		${SRC_FILES}
		${SRC_DIR}/point.hpp
		${SRC_DIR}/point2.hpp
		${SRC_DIR}/triangle.hpp
		${SRC_DIR}/triangle2.hpp
		${SRC_DIR}/vector.hpp
	)
endif()

if (!WIN32)
	target_link_libraries(${DEMO} "stdc++fs")
endif()
target_compile_definitions(
    ${DEMO} PUBLIC
    -DPATH_TO_SRC_DIRECTORY="${CMAKE_SOURCE_DIR}/code/"
)
