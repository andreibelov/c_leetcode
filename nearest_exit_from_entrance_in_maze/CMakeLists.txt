# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 22:41:30 by abelov            #+#    #+#              #
#    Updated: 2025/01/05 22:41:30 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(nearest_exit_from_entrance_in_maze C)

set(TARGET_EXE_NAME "${PROJECT_NAME}")

add_executable(${TARGET_EXE_NAME}
        src/main.c
        src/nearestExit.c)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_compile_definitions(${TARGET_EXE_NAME} PRIVATE )
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
