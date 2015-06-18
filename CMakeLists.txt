#
# Root Cmake file of the Penguin Project.
#
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#
# Define Global project name
#
PROJECT(Penguin)

#
# Set project root directory
#
SET(PF_PROJECT_DIR ${CMAKE_SOURCE_DIR})

#
# Compilation mode
#
IF(NOT CMAKE_SOURCE_DIR STREQUAL "Release")
	MESSAGE(STATUS "Project will be compiled in Debug mode")

	ENABLE_TESTING()
	ADD_DEFINITIONS(-DPF_BUILD_TYPE_DEBUG)
	ADD_DEFINITIONS(-g -O0 -Wall)
ELSE()
	MESSAGE(STATUS "Project will be compiled in Release mode")

	ADD_DEFINITIONS(-DPF_BUILD_TYPE_RELEASE)
	ADD_DEFINITIONS(-O3 -Wall -Werror)
ENDIF()

#
# Add compilation targets
#
ADD_SUBDIRECTORY(config)
ADD_SUBDIRECTORY(source)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(doc)
ADD_SUBDIRECTORY(examples)