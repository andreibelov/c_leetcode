# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 09:33:05 by abelov            #+#    #+#              #
#    Updated: 2024/08/07 09:33:05 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.27)
project(leetcode C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(merge_strings)
add_subdirectory(reformat_phone_number)
add_subdirectory(gcd_of_strings)
