/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:41:54 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 18:41:27 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	free_strings(t_file *file)
{
	if (file->textures.north != NULL)
		free(file->textures.north);
	if (file->textures.south != NULL)
		free(file->textures.south);
	if (file->textures.east != NULL)
		free(file->textures.east);
	if (file->textures.west != NULL)
		free(file->textures.west);
	file->textures.north = NULL;
	file->textures.south = NULL;
	file->textures.east = NULL;
	file->textures.west = NULL;
	return ;
}

void	free_all(t_data *data)
{
	data->file.free = 11;
	free_strings(&data->file);
	if (data->file.map != NULL)
		free_tab(data->file.map, data->file.y);
	data->file.map = NULL;
	if (data->file.tab != NULL)
		free_tab(data->file.tab, data->file.y);
	data->file.tab = NULL;
	if (data->file.taby != NULL)
		free_tab(data->file.taby, data->file.y);
	data->file.taby = NULL;
	if (data->file.mapy != NULL)
		free_mapy(data);
	data->file.mapy = NULL;
	return ;
}

void	free_all_nxt(t_data *data)
{
	free_strings(&data->file);
	if (data->file.mapy != NULL)
		free_mapy(data);
	data->file.mapy = NULL;
}

void	free_alll(t_file *file)
{
	free_strings(file);
	free_tab(file->map, file->y);
	free_tab(file->tab, file->y);
	return ;
}

void	free_tabs(t_data *data)
{
	if (data->file.map != NULL)
		free_tab(data->file.map, data->file.y);
	data->file.map = NULL;
	if (data->file.tab != NULL)
		free_tab(data->file.tab, data->file.y);
	data->file.tab = NULL;
	if (data->file.taby != NULL)
		free_tab(data->file.taby, data->file.y);
}
