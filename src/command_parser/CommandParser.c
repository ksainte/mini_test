/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandParser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:16:45 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/07 12:26:45 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parseinput(char *input)
{
	t_token	**tokens;

	tokens = tokenizer(input);
	if (!tokens)
	{
		printf("Error: failed to tokenize input\n");
		return ;
	}
	free_tokens(tokens);
}

/*
	testing
	int i = 0;
	printf("Tokenize %s:\n", input);
	while (tokens[i] != NULL)
	{
		printf("Token type: %d, value: %s\n", tokens[i]->type, tokens[i]->value);
		i++;
	}
*/