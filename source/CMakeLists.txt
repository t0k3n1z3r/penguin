#
# Cmake file to build sources of the Penguin project
#

# Include compilation of the applications
ADD_SUBDIRECTORY(app)

# Include compilation of the libraries
ADD_SUBDIRECTORY(lib)

# Include compilation of the tests
ADD_SUBDIRECTORY(test)

# Include compilation of the examples
ADD_SUBDIRECTORY(examples)