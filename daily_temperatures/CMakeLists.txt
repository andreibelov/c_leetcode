# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 19:16:15 by abelov            #+#    #+#              #
#    Updated: 2025/01/06 19:16:15 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(daily_temperatures C)

set(TARGET_EXE_NAME "${PROJECT_NAME}")

add_executable(${TARGET_EXE_NAME}
        src/main.c
        src/dailyTemperatures.c)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
