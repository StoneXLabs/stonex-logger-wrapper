
cmake_minimum_required(VERSION 3.16)
project(stonex-logger-wrapper-app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sourceFiles ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headerFiles ${PROJECT_SOURCE_DIR}/include/*.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sourceFiles} ${headerFiles})

add_executable(stonex-logger-wrapper-app
	${sourceFiles} 
	${headerFiles}
	)

#target_include_directories(stonex-logger-wrapper-app
#	PUBLIC ${PROJECT_SOURCE_DIR}/../stonex-logger-lib/include
#	)

target_link_libraries(stonex-logger-wrapper-app
	CONAN_PKG::fmt
	stonex-logger-wrapper-lib
	)
	
configure_file(${PROJECT_SOURCE_DIR}/logger.xml ${CMAKE_CURRENT_BINARY_DIR}/../bin/logger.xml COPYONLY)    