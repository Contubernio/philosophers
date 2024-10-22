/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:53:11 by albealva          #+#    #+#             */
/*   Updated: 2024/10/22 16:42:36 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/philosophers.h"

int	main(int argc, char *argv[])
{
	t_args	args;

	args.max_ate = 0;
	args.stop_condition = 0;
	if (argc < 5 || argc > 6)
		return (ft_return_error(ERR_USAGE));
	if (!ft_check_params(&args, argc, argv))
		return (ft_return_error("Incorrect parameters.\n"));
	if (!ft_initialize(&args))
		return (ft_return_error("init error.\n"));
	if (!start_threads(&args))
		return (ft_return_error("threads error.\n"));
	return (0);
}
