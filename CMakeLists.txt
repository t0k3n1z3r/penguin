#
# Root Cmake file of the Penguin Framework. It contains 2 major targets: build sources and doc.
#

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Penguin)

# Set project root directory
SET(PF_PROJECT_DIR ${CMAKE_SOURCE_DIR})

# Add source compilation target
ADD_SUBDIRECTORY(source)