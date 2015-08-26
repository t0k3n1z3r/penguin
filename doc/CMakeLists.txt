#
# Build doxygen documentation
#
PROJECT(doc)

FIND_PACKAGE(Doxygen)

IF(DOXYGEN_FOUND)
#
# Set the C_API doxyfile as an input to the doxygen tool
#
SET(PF_DOXYGEN_SOURCE ${PF_PROJECT_DIR}/doc/penguin.doxygen)

ADD_CUSTOM_TARGET(${PROJECT_NAME} ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${PF_DOXYGEN_SOURCE} > /dev/null 2>&1
    WORKING_DIRECTORY ${PF_PROJECT_DIR/doc})

ENDIF(DOXYGEN_FOUND)