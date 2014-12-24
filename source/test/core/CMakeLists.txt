

SET(PF_TEST1_SRC PfLibcoreTestset.c)

ADD_DEFINITIONS(-DPF_DEBUG_CLASS_DEFAULT=PF_DEBUG_CLASS_CORE)

# Compiler options
ADD_DEFINITIONS(-Wall -fPIC)

ADD_EXECUTABLE(PfCoreTestSet ${PF_TEST1_SRC})

#
# Add Penguin Framework Core Library test
#
ADD_TEST(PfLibcoreTest PfCoreTestSet 1)

