# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 09:33:05 by abelov            #+#    #+#              #
#    Updated: 2024/08/27 01:55:42 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.27)

include_directories(include)

project(leetcode C)

set(CMAKE_C_STANDARD 11)

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
        -fcf-protection=none
        -mmanual-endbr
        -g3 -gdwarf-3
        -fasynchronous-unwind-tables
        -fsanitize=address
        -fsanitize=undefined
        -fno-sanitize-recover
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow
)

add_subdirectory(merge_strings)
add_subdirectory(reformat_phone_number)
add_subdirectory(gcd_of_strings)
add_subdirectory(num_to_words)
add_subdirectory(kids_with_candies)
add_subdirectory(can_place_flowers)
add_subdirectory(reverse_vowels)
add_subdirectory(reverse_strings)
add_subdirectory(product_except_self)
add_subdirectory(increasing_triplet_subsequence)
add_subdirectory(string_compression)
add_subdirectory(move_zeroes)
add_subdirectory(container_with_most_water)
add_subdirectory(max_number_of_k_sum_pairs)
add_subdirectory(maximum_average_subarray)
add_subdirectory(maximum_vowels)
add_subdirectory(max_consecutive_ones)
add_subdirectory(longest_subarray)
add_subdirectory(highest_altitude)
add_subdirectory(find_pivot_index)
add_subdirectory(find_the_difference)
add_subdirectory(unique_occurrences)
add_subdirectory(two_strings_are_close)
add_subdirectory(equal_row_col_pairs)
add_subdirectory(remove_stars)
add_subdirectory(asteroid_collision)
add_subdirectory(decode_string)
add_subdirectory(reverse_linked_list)
add_subdirectory(number_of_recent_calls)
add_subdirectory(dota2_senate)
add_subdirectory(delete_the_middle)
add_subdirectory(odd_even_linked_list)
add_subdirectory(maximum_twin_sum)
add_subdirectory(maxdepth_of_btree)
add_subdirectory(leaf_similar_trees)
add_subdirectory(good_nodes_in_btree)
add_subdirectory(path_sum_iii)
add_subdirectory(longest_zigzag_path)
add_subdirectory(lowest_common_ancestor)
