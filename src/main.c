/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:12:32 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/07 13:46:14 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv)
{
	
	
	int exittt;

	// testing parseinput("ls -l | cat -e");
	exittt = cli(argc, argv);
	return (exittt);
}
