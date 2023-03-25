set(component_srcs "ls_detection.c")

idf_component_register(SRCS "${component_srcs}"
                       INCLUDE_DIRS "."
                       PRIV_INCLUDE_DIRS ""
                       PRIV_REQUIRES "util"
                                     "gpio"
                       REQUIRES "")