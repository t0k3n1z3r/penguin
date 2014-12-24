#
# Unit tests for Penguin Framework
#

#
# Build general test for the libraries
#
SET(PF_GENERAL_LIBRARY_TEST PfLibraryTestGeneral.c)
INCLUDE_DIRECTORIES(${PF_PROJECT_DIR}/include)

ADD_EXECUTABLE(PfLibraryTestGeneral ${PF_GENERAL_LIBRARY_TEST})
ADD_DEFINITIONS(-Wall)
TARGET_LINK_LIBRARIES(PfLibraryTestGeneral dl)

#
# Add test suite for Core Library of the Penguin Framework
#
ADD_SUBDIRECTORY(core)
ADD_SUBDIRECTORY(transport)