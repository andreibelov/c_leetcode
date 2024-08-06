# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 11:48:55 by abelov            #+#    #+#              #
#    Updated: 2024/08/06 11:48:55 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(reformat_phone_number C)

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

set(TARGET_EXEC_NAME "reformat_phone_number")

add_executable(${TARGET_EXEC_NAME}
        src/main.c
        src/ft_strnlcat.c
        src/ft_strnpcat.c
        src/reformatNumber.c
        src/reformatNumber1.c
        src/reformatNumber2.c)
target_compile_options(${TARGET_EXEC_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXEC_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXEC_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")