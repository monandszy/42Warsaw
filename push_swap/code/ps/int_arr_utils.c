/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:10:24 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 13:11:13 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int indexify(int ***args, int argc)
{
    int i;
    int j;
    int min_i;
    int min;
    int **indexes;
    int *tmp;

    indexes = (int **)malloc(sizeof(int *) * (argc + 1));
    if (!indexes)
        return (1);
    indexes[argc] = NULL;
    i = 0;
    while (i < argc)
    {
        min = 2147483647;
        j = 0;
        while (j < argc)
        {
            if (min >= (args)[0][j][0])
            {
                min = (args)[0][j][0];
                min_i = j;
            }
            j++;
        }
        fflush(stdout);
        tmp = (int *)malloc(sizeof(int));
        *tmp = i;
        indexes[min_i] = tmp;
        (args)[0][min_i][0] = 2147483647;
        i++;
    }
    free_int_matrix(*args, argc);
    *args = indexes;
    return (0);
}

int to_int_arr(char **args, int ***int_args, int argc)
{
    int res;
    int *tmp;

    int_args[0] = (int **)malloc(sizeof(int *) * (argc + 1));
    if (!*int_args)
        return (1);
    int_args[0][argc] = NULL;
    argc--;
    while (argc >= 0)
    {
        tmp = (int *)malloc(sizeof(int));
        res = ft_atoi(args[argc]);
        *tmp = res;
        int_args[0][argc] = tmp;
        argc--;
    }
    return (0);
}
