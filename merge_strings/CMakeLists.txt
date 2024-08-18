# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 21:51:54 by abelov            #+#    #+#              #
#    Updated: 2024/08/17 21:51:55 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(merge_strings C)

set(COMMON_LDFLAGS
        -fsanitize=address)
set(COMMON_CFLAGS
        -Wall -Wextra -Werror
        -Wwrite-strings
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

set(TARGET_EXE_NAME "merge_strings")

add_executable(${TARGET_EXE_NAME} src/main.c)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
