set(component_srcs "hopper_ir_sensor.c")

idf_component_register(SRCS "${component_srcs}"
                       INCLUDE_DIRS "."
                       PRIV_INCLUDE_DIRS ""
                       PRIV_REQUIRES "util"
                       REQUIRES "")