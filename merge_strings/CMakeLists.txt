project(merge_strings C)

set(COMMON_LDFLAGS
        -fsanitize=address)
set(COMMON_CFLAGS
        -Wall -Wextra -Werror
        -O0
        -masm=att
        -fno-exceptions
        -ffunction-sections
        -fdata-sections
        -fomit-frame-pointer
        -fdwarf2-cfi-asm
        -fasynchronous-unwind-tables
        -fsanitize=address
        -g3 -gdwarf-3)

set(TARGET_EXEC_NAME "merge_strings")

add_executable(${TARGET_EXEC_NAME} src/main.c)
target_compile_options(${TARGET_EXEC_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXEC_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXEC_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")