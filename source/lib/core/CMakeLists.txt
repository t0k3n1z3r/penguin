#
# Cmake file to build CORE library of the Penguin Framework
#

PROJECT(core C)

SET(PF_CORE_SRC PfDebug.c PfTime.c PfCore.c)
ADD_DEFINITIONS(-DPF_DEBUG_CLASS_DEFAULT=PF_DEBUG_CLASS_CORE)

# Compiler options
ADD_DEFINITIONS(-Wall -fPIC)

INCLUDE_DIRECTORIES(${PF_PROJECT_DIR}/include)

ADD_LIBRARY(core SHARED ${PF_CORE_SRC})