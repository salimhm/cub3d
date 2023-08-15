/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:20:18 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/15 20:34:02 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_parse_map
{
    char **map;
    char **dummy_map;
    char **duplicates;
}   t_parse_map;

// Free N destroy
void	free2d(char **arg);

//Utils
int ft_strlen_2d(char **str2d);

//Print map
void print_map(char **map);

//Check map
int check_map(int fd, char *map);
void check_map3(t_parse_map essentials);
void check_valid_path(t_parse_map essentials);
int check_valid_path1(t_parse_map *essentials, int i, int *count);
void check_valid_path2(int i, int j, int count, t_parse_map essentials);
void check_valid_path3(t_parse_map essentials, int count);
void check_empty_lines(t_parse_map essentials, char *file);

//Check map elements
int check_elements(t_parse_map essentials);
int is_coord(char *coord);
int is_rgb(char *rgb);
void rgb_check(char *rgbs, char **element, t_parse_map essentials);
void rgb_check2(char **rgb, char **element, t_parse_map essentials);
void check_duplicates(t_parse_map *essentials);
int check_elements_existance(char *element);
void check_player_duplicates(t_parse_map essentials);
void check_weird_chars(t_parse_map essentials);

#endif