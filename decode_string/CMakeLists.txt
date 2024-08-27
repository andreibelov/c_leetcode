# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 13:31:56 by abelov            #+#    #+#              #
#    Updated: 2024/08/27 13:31:57 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(decode_string C)

set(TARGET_EXE_NAME "${PROJECT_NAME}")

set(COMMON_LDFLAGS
        -fsanitize=address
        -fsanitize=undefined
        -fno-sanitize-recover
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow)
set(COMMON_CFLAGS
        -Wall -Wextra -Werror
        -Wwrite-strings
        -Wimplicit
        -O0
        -masm=att
        -fno-exceptions
        -ffunction-sections
        -fdata-sections
        -fomit-frame-pointer
        -fdwarf2-cfi-asm
        -fasynchronous-unwind-tables
        -fsanitize=address
        -fsanitize=undefined
        -fno-sanitize-recover
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow
        -g3 -gdwarf-3)

add_executable(${TARGET_EXE_NAME}
        src/main.c
        src/decodeString.c)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE
        ${COMMON_LDFLAGS}
        -lbsd)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
