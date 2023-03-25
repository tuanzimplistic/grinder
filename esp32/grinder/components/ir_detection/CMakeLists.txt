set(component_srcs "ir_detection.c")

idf_component_register(SRCS "${component_srcs}"
                       INCLUDE_DIRS "."
                       PRIV_INCLUDE_DIRS ""
                       PRIV_REQUIRES    "util" 
                                        "adc"
                       REQUIRES "")