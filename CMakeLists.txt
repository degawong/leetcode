
project(leetcode)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)

set(
	CMAKE_CXX_FLAGS
	"${CMAKE_CXX_FLAGS} -g"
)

set(
	index
	0003
)

file(
	GLOB
	UI_SRCS
	*.cpp
	${index}/*.*
)

add_executable(
	${PROJECT_NAME}
	${UI_SRCS}
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${index}
)

set_directory_properties(
	PROPERTIES
	VS_STARTUP_PROJECT
	${PROJECT_NAME}
)
