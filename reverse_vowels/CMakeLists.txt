# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 11:39:23 by abelov            #+#    #+#              #
#    Updated: 2024/08/12 11:39:23 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


project(reverse_vowels C)

set(COMMON_LDFLAGS
        -fsanitize=address
        -fno-plt -fno-pie -no-pie -fno-pic
        -static -flto -Wl,-z,relro,-z,now)
set(COMMON_CFLAGS
        -Wall -Wextra -Werror
        -Wwrite-strings
        -Wimplicit
        -O0
        -g3 -gdwarf-3
        -nostdlib -lc
        -fno-builtin-strlen
        -foptimize-strlen
        -mstackrealign
        -static -flto -Wl,-z,relro,-z,now
        -masm=att
        -fno-exceptions
        -ffunction-sections
        -fdata-sections
        -fomit-frame-pointer
        -fdwarf2-cfi-asm
        -fasynchronous-unwind-tables
        -fsanitize=address
)

set(TARGET_EXE_NAME "${PROJECT_NAME}")

add_executable(${TARGET_EXE_NAME}
        src/main.c
        src/reverseVowels.c)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
