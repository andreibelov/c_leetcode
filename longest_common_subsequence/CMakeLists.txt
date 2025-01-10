# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 10:40:20 by abelov            #+#    #+#              #
#    Updated: 2025/01/10 10:40:21 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(longest_common_subsequence C)

set(TARGET_EXE_NAME "${PROJECT_NAME}")

add_executable(${TARGET_EXE_NAME}
        src/main.c
        src/longestCommonSubsequence.c)

target_compile_definitions(${TARGET_EXE_NAME} PRIVATE USE_DYN_PROG)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
