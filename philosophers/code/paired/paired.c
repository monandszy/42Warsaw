/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paired.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:09:31 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 13:09:34 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paired_philo.h"

static void	instruct(void)
{
	printf("%s\n", "ARGS");
	printf("- %s\n", "number_of_philosophers ");
	printf("- %s\n", "time_to_die");
	printf("- %s\n", "time_to_eat ");
	printf("- %s\n", "time_to_sleep");
	printf("- %s\n", "[number_of_times_each_philosopher_must_eat]");
}

int	main(int argc, char **argv)
{
	static t_data	data;
	t_philo			*head;

	if (parse(&data, argc, argv))
		return (instruct(), 1);
	head = initialize(&data);
	if (!head)
		return (printf("%s\n", "Error"), end(&data, head), 1);
	start(&data, head);
	monitor(&data, head);
	waitforend(&data, head);
	end(&data, head);
	return (0);
}
