
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

#
# Log level table
#
SET(PF_DEBUG_LEVEL_ERROR_GENERATED          0)
SET(PF_DEBUG_LEVEL_WARNING_GENERATED        1)
SET(PF_DEBUG_LEVEL_INFO_GENERATED           2)
SET(PF_DEBUG_LEVEL_MAX_GENERATED            3)

SET(PF_DEBUG_CLASS_UNDEFINED_GENERATED      0)
SET(PF_DEBUG_CLASS_CORE_GENERATED           1)
SET(PF_DEBUG_CLASS_PROTOCOL_GENERATED       2)
SET(PF_DEBUG_CLASS_TRANSPORT_GENERATED      3)
SET(PF_DEBUG_CLASS_PENGUIN_GENERATED        4)
SET(PF_DEBUG_CLASS_MAX_GENERATED            5)


#SET(PF_CALL_CONVENTION             "__attribute__((cdecl))")
SET(PF_CALL_CONVENTION             "")



CONFIGURE_FILE("${PF_PROJECT_DIR}/config/code/PfStatus.h.in"
               "${PF_PROJECT_DIR}/include/auto-generated/PfStatus.h")

CONFIGURE_FILE("${PF_PROJECT_DIR}/config/code/PfConfig.h.in"
               "${PF_PROJECT_DIR}/include/auto-generated/PfConfig.h")

CONFIGURE_FILE("${PF_PROJECT_DIR}/config/code/PfTypes.h.in"
               "${PF_PROJECT_DIR}/include/auto-generated/PfTypes.h")

CONFIGURE_FILE("${PF_PROJECT_DIR}/config/code/PfLog.h.in"
               "${PF_PROJECT_DIR}/include/auto-generated/PfLog.h")



MESSAGE(STATUS "Configuring the project")