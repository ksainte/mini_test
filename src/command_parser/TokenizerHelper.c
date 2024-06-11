/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenizerHelper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:10:42 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/07 09:04:06 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*create_token(int type, char *s)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	if (s)
	{
		token->value = ft_strdup(s);
		if (get_token_type(s) != WORD)
			free(s);
		if (!token->value)
		{
			free_token(token);
			return (NULL);
		}
	}
	else
		token->value = NULL;
	return (token);
}

bool	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	free_token(t_token *token)
{
	t_token	tok;

	tok = *token;
	free(tok.value);
	free(token);
}

void	free_tokens(t_token **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		free_token(tokens[count++]);
	free(tokens);
}
