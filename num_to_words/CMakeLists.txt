# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 09:33:37 by abelov            #+#    #+#              #
#    Updated: 2024/08/07 09:33:38 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(num_to_words C)

set(COMMON_LDFLAGS
        -fsanitize=address)
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
        -g3 -gdwarf-3)

set(TARGET_EXE_NAME "${PROJECT_NAME}")

add_executable(${TARGET_EXE_NAME}
        src/main.c
        src/numberToWords.c)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
