
SET(PF_TEST1_SRC PfCoreTestLog.c)
INCLUDE_DIRECTORIES(${PF_PROJECT_DIR}/include)

# Compiler options
ADD_DEFINITIONS(-Wall)
ADD_DEFINITIONS(-DPF_DEBUG_CLASS_DEFAULT=PF_DEBUG_CLASS_PENGUIN)

ADD_EXECUTABLE(PfCoreTestLog ${PF_TEST1_SRC})
TARGET_LINK_LIBRARIES(PfCoreTestLog core)

ADD_TEST(PfCoreLibraryTest
			${PF_PROJECT_DIR}/source/test/PfLibraryTestGeneral
			${PF_PROJECT_DIR}/source/lib/core/libcore.so)
SET_TESTS_PROPERTIES(PfCoreLibraryTest
						PROPERTIES
						PASS_REGULAR_EXPRESSION
						"//^//[.*")

#
# Add Penguin Framework Core Library test
#
ADD_TEST(PfLibcoreTest1 PfCoreTestLog)
SET_TESTS_PROPERTIES(PfLibcoreTest1 PROPERTIES DEPENDS PfCoreLibraryTest)
SET_TESTS_PROPERTIES(PfLibcoreTest1
						PROPERTIES
						PASS_REGULAR_EXPRESSION
						".*[/d/d:/d/d:/d/d:/d/d/d][^PENG$][^I$].*")

ADD_TEST(PfLibcoreTest2 PfCoreTestLog 0 "I'm error")
SET_TESTS_PROPERTIES(PfLibcoreTest2 PROPERTIES DEPENDS PfCoreLibraryTest)
SET_TESTS_PROPERTIES(PfLibcoreTest2
						PROPERTIES
						PASS_REGULAR_EXPRESSION
						".*[/d/d:/d/d:/d/d:/d/d/d][^PENG$][^I$].*")

ADD_TEST(PfLibcoreTest3 PfCoreTestLog 1 "I'm warning")
SET_TESTS_PROPERTIES(PfLibcoreTest3 PROPERTIES DEPENDS PfCoreLibraryTest)
SET_TESTS_PROPERTIES(PfLibcoreTest3
						PROPERTIES
						PASS_REGULAR_EXPRESSION
						".*[/d/d:/d/d:/d/d:/d/d/d][^PENG$][^I$].*")

ADD_TEST(PfLibcoreTest4 PfCoreTestLog 2 "I'm info")
SET_TESTS_PROPERTIES(PfLibcoreTest4 PROPERTIES DEPENDS PfCoreLibraryTest)
SET_TESTS_PROPERTIES(PfLibcoreTest4
						PROPERTIES
						PASS_REGULAR_EXPRESSION
						".*[/d/d:/d/d:/d/d:/d/d/d][^PENG$][^I$].*")
