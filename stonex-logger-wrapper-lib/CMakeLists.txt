
cmake_minimum_required(VERSION 3.16)
project(stonex-logger-wrapper-lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sourceFiles 
	${PROJECT_SOURCE_DIR}/src/logger/*.cpp
	${PROJECT_SOURCE_DIR}/src/Log4CxxLogger/*.cpp
	${PROJECT_SOURCE_DIR}/src/SpdLogLogger/*.cpp
	${PROJECT_SOURCE_DIR}/src/StdOutLogger/*.cpp
	)
	
file(GLOB headerFiles 
	${PROJECT_SOURCE_DIR}/include/logger/*.h
	${PROJECT_SOURCE_DIR}/include/Log4CxxLogger/*.h
	${PROJECT_SOURCE_DIR}/include/SpdLogLogger/*.h
	${PROJECT_SOURCE_DIR}/include/StdOutLogger/*.h
	)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sourceFiles} ${headerFiles})

add_library(stonex-logger-wrapper-lib STATIC
	${sourceFiles} 
	${headerFiles}
	)

target_include_directories(stonex-logger-wrapper-lib
	PUBLIC ${PROJECT_SOURCE_DIR}/include
	)

target_link_libraries(stonex-logger-wrapper-lib
	CONAN_PKG::fmt
	CONAN_PKG::spdlog
	CONAN_PKG::log4cxx
	)
