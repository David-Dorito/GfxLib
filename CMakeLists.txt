cmake_minimum_required(VERSION 3.15)

project(GfxLib C CXX)

add_library(${PROJECT_NAME}
	GfxLib.c
	GfxLib.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/
)
