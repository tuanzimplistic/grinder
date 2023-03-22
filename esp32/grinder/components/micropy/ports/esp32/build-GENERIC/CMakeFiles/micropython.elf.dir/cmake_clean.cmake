file(REMOVE_RECURSE
  "bootloader/bootloader.bin"
  "bootloader/bootloader.elf"
  "bootloader/bootloader.map"
  "config/sdkconfig.cmake"
  "config/sdkconfig.h"
  "flash_project_args"
  "micropython.bin"
  "micropython.map"
  "project_elf_src_esp32.c"
  "CMakeFiles/micropython.elf.dir/project_elf_src_esp32.c.obj"
  "CMakeFiles/micropython.elf.dir/project_elf_src_esp32.c.obj.d"
  "micropython.elf"
  "micropython.elf.pdb"
  "project_elf_src_esp32.c"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/micropython.elf.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
