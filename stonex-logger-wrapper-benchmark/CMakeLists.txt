
cmake_minimum_required(VERSION 3.16)
project(stonex-logger-wrapper-benchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sourceFiles ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headerFiles ${PROJECT_SOURCE_DIR}/include/*.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sourceFiles} ${headerFiles})

add_executable(stonex-logger-wrapper-benchmark
	${sourceFiles} 
	${headerFiles}
	)

#target_include_directories(stonex-logger-wrapper-benchmark
#	PUBLIC ${PROJECT_SOURCE_DIR}/../stonex-logger-lib/include
#	)

target_link_libraries(stonex-logger-wrapper-benchmark
	CONAN_PKG::fmt
	CONAN_PKG::benchmark
	stonex-logger-wrapper-lib
	)
