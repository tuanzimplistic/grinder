# ------------------------------------------------------------
# register component
# ------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)

set(micropy_path ${CMAKE_CURRENT_SOURCE_DIR})
set(board "GENERIC")
set(micropython_board_build_dir ${micropy_path}/ports/esp32/build-${board})

idf_component_register(
                SRCS 
                  "${micropy_path}/py/argcheck.c"
                  "${micropy_path}/py/asmbase.c"
                  "${micropy_path}/py/bc.c"
                  "${micropy_path}/py/binary.c"
                  "${micropy_path}/py/builtinevex.c"
                  "${micropy_path}/py/builtinhelp.c"
                  "${micropy_path}/py/builtinimport.c"
                  "${micropy_path}/py/compile.c"
                  "${micropy_path}/py/emitbc.c"
                  "${micropy_path}/py/emitcommon.c"
                  "${micropy_path}/py/emitglue.c"
                  "${micropy_path}/py/formatfloat.c"
                  "${micropy_path}/py/frozenmod.c"
                  "${micropy_path}/py/gc.c"
                  "${micropy_path}/py/lexer.c"
                  "${micropy_path}/py/malloc.c"
                  "${micropy_path}/py/map.c"
                  "${micropy_path}/py/modbuiltins.c"
                  "${micropy_path}/py/modgc.c"
                  "${micropy_path}/py/modmicropython.c"
                  "${micropy_path}/py/modstruct.c"
                  "${micropy_path}/py/modthread.c"
                  "${micropy_path}/py/moduerrno.c"
                  "${micropy_path}/py/mpprint.c"
                  "${micropy_path}/py/mpstate.c"
                  "${micropy_path}/py/mpz.c"
                  "${micropy_path}/py/nativeglue.c"
                  "${micropy_path}/py/nlr.c"
                  "${micropy_path}/py/nlrsetjmp.c"
                  "${micropy_path}/py/obj.c"
                  "${micropy_path}/py/objarray.c"
                  "${micropy_path}/py/objbool.c"
                  "${micropy_path}/py/objboundmeth.c"
                  "${micropy_path}/py/objcell.c"
                  "${micropy_path}/py/objclosure.c"
                  "${micropy_path}/py/objcomplex.c"
                  "${micropy_path}/py/objdict.c"
                  "${micropy_path}/py/objenumerate.c"
                  "${micropy_path}/py/objexcept.c"
                  "${micropy_path}/py/objfilter.c"
                  "${micropy_path}/py/objfloat.c"
                  "${micropy_path}/py/objfun.c"
                  "${micropy_path}/py/objgenerator.c"
                  "${micropy_path}/py/objgetitemiter.c"
                  "${micropy_path}/py/objint.c"
                  "${micropy_path}/py/objint_mpz.c"
                  "${micropy_path}/py/objlist.c"
                  "${micropy_path}/py/objmap.c"
                  "${micropy_path}/py/objmodule.c"
                  "${micropy_path}/py/objnone.c"
                  "${micropy_path}/py/objobject.c"
                  "${micropy_path}/py/objpolyiter.c"
                  "${micropy_path}/py/objproperty.c"
                  "${micropy_path}/py/objrange.c"
                  "${micropy_path}/py/objreversed.c"
                  "${micropy_path}/py/objset.c"
                  "${micropy_path}/py/objsingleton.c"
                  "${micropy_path}/py/objslice.c"
                  "${micropy_path}/py/objstr.c"
                  "${micropy_path}/py/objstrunicode.c"
                  "${micropy_path}/py/objtuple.c"
                  "${micropy_path}/py/objtype.c"
                  "${micropy_path}/py/objzip.c"
                  "${micropy_path}/py/opmethods.c"
                  "${micropy_path}/py/parse.c"
                  "${micropy_path}/py/parsenum.c"
                  "${micropy_path}/py/parsenumbase.c"
                  "${micropy_path}/py/persistentcode.c"
                  "${micropy_path}/py/profile.c"
                  "${micropy_path}/py/qstr.c"
                  "${micropy_path}/py/reader.c"
                  "${micropy_path}/py/repl.c"
                  "${micropy_path}/py/runtime.c"
                  "${micropy_path}/py/runtime_utils.c"
                  "${micropy_path}/py/scope.c"
                  "${micropy_path}/py/scheduler.c"
                  "${micropy_path}/py/sequence.c"
                  "${micropy_path}/py/smallint.c"
                  "${micropy_path}/py/stream.c"
                  "${micropy_path}/py/stackctrl.c"
                  "${micropy_path}/py/unicode.c"
                  "${micropy_path}/py/vm.c"
                  "${micropy_path}/py/vstr.c"
                  "${micropy_path}/py/warning.c"
                  "${micropy_path}/shared/readline/readline.c"
                  "${micropy_path}/shared/timeutils/timeutils.c"
                  "${micropy_path}/shared/runtime/interrupt_char.c"
                  "${micropy_path}/extmod/utime_mphal.c"
                  "${micropy_path}/shared/runtime/pyexec.c"
                  "${micropy_path}/ports/esp32/gccollect.c"
                  "${micropy_path}/ports/esp32/help.c"
                  "${micropy_path}/ports/esp32/mphalport.c"
                  "${micropy_path}/ports/esp32/mpthreadport.c"
                  "${micropy_path}/ports/esp32/modutime.c"
                  "${micropython_board_build_dir}/frozen_content.c"
                INCLUDE_DIRS
                  ${micropy_path}
				  ${micropy_path}/ports/esp32
				  ${micropy_path}/ports/esp32/boards/${board}
                REQUIRES 
)

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DMICROPY_ESP_IDF_4 -Wno-override-init -Wno-implicit-fallthrough -I${micropython_board_build_dir}" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMICROPY_ESP_IDF_4 -I${micropython_board_build_dir}" )

add_custom_command(OUTPUT "${micropython_board_build_dir}/frozen_content.c"
    COMMAND echo "------------- Building Micropython externally ---------------"
    COMMAND cd ${micropy_path}/ports/esp32
    COMMAND make BOARD=${board}
    DEPENDS 
		${micropy_path}/ports/esp32/mpconfigport.h
)

add_custom_target(generate_frozen ALL
    DEPENDS "${micropython_board_build_dir}/frozen_content.c")