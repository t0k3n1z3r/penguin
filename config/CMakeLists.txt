
#
# Configuration
#

#
# General notice will be added to all auto-generated files
#
SET(PF_AUTOGEN_NOTICE "This file was auto-generated during project configuration")

#
# Error code table
#
SET(PF_STATUS_OK_GENERATED                  0)
SET(PF_STATUS_FAIL_GENERATED                1)
SET(PF_STATUS_BADARG_GENERATED              2)
SET(PF_STATUS_NOT_IMPLEMENTED_GENERATED     3)


SET(PF_CALL_CONVENTION             "__attribute__((cdecl))")



CONFIGURE_FILE("${PF_PROJECT_DIR}/config/code/PfStatus.h.in"
               "${PF_PROJECT_DIR}/include/auto-generated/PfStatus.h")

CONFIGURE_FILE("${PF_PROJECT_DIR}/config/code/PfConfig.h.in"
               "${PF_PROJECT_DIR}/include/auto-generated/PfConfig.h")



MESSAGE(STATUS "Configuring the project")