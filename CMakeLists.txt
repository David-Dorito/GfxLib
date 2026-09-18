cmake_minimum_required(VERSION 4.3.0)

project(gfxlib LANGUAGES C)

option(GFXLIB_CXX_ENABLED "Enable the C++ wrapper for GfxLib" "OFF")

add_library(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME}
PRIVATE
	c_std_99
)

target_sources(${PROJECT_NAME}
PRIVATE
	GfxLib.c

PUBLIC
	FILE_SET HEADERS
	FILES
		GfxLib.h
)

if(GFXLIB_CXX_ENABLED)
	enable_language(CXX)

	target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_17
	)

	target_sources(${PROJECT_NAME}
	PRIVATE
		GfxLib.cpp

	PUBLIC
		FILE_SET HEADERS
		FILES
			GfxLib.hpp
	)
endif()
