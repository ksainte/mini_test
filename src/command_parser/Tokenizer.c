/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:17:25 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/07 19:04:08 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*this function will take the input string and return an array of tokens
each token will have a type and a value
the type will be one of the enum values in minishell.h
the value will be the string that the token represents
   - Initialize variables:
     - String for the current token.
     - Boolean flags for single and double quotes.
     - Index and length variables.
   - Loop through each character in the input string.
     - If the character is a space and not inside quotes:
       - End the current token and add it to the list of tokens.
     - If the character is a single quote:
       - Toggle the single quote flag.
     - If the character is a double quote:
       - Toggle the double quote flag.
     - If the character is an escape character:
       - Skip the next character (handle escaping).
     - If the character is a special operator (pipe, redirection):
       - End the current token, add it to the list of tokens.
       - Add the special operator as a separate token.
     - Otherwise, add the character to the current token.
   - After the loop, add any remaining token to the list.
   - Return the list of tokens.
*/

void	tokenizer_init(t_tokenizer *t, char *s)
{
	//fct qui avec delimiter sait savoir le nb de token
	t->tokens = (t_token **)malloc(sizeof(t_token *) * ft_strlen(s));
	// printf("%zu\n", ft_strlen(s));
	t->token_buffer = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	t->single_quote = false;
	t->double_quote = false;
	t->count_tokens = 0;
	t->count_buffer = 0;
}

char	*tokenizer_handle_special_char(t_tokenizer *t, char *input)
{
	char	*tmp;

	if (t->token_buffer[0] != '\0')
		t->tokens[t->count_tokens++] = create_token(WORD, t->token_buffer);
	ft_memset(t->token_buffer, 0, ft_strlen(t->token_buffer));
	t->count_buffer = 0;
	if (get_token_type(input) > 4)
	{
		tmp = ft_substr(input, 0, 2);
		t->tokens[t->count_tokens++] = create_token(get_token_type(input), tmp);
		input++;
	}
	else
	{
		tmp = ft_substr(input, 0, 1);
		t->tokens[t->count_tokens++] = create_token(get_token_type(input), tmp);
	}
	return (input);
}

char	*tokenizer_handle_quotes(t_tokenizer *t, char *input)
{
	if (*input == '\'')
		t->single_quote = !t->single_quote;
	if (*input == '\"')
		t->double_quote = !t->double_quote;
	if (*input == '\\')
	{
		if (*(input + 1) == '\'' || *(input + 1) == '\"'
			|| *(input + 1) == '\\')
			input++;
	}
	else if (is_special_char(*input) && !t->single_quote && !t->double_quote)
		input = tokenizer_handle_special_char(t, input);
	else
		t->token_buffer[t->count_buffer++] = *input;
	return (input);
}

t_token	**tokenizer(char *s)
{
	t_tokenizer	t;

	tokenizer_init(&t, s);
	if (!t.tokens || !t.token_buffer)
		return (NULL);
	while (*s)
	{
		if (*s == ' ' && !t.single_quote && !t.double_quote)
		{
			if (t.token_buffer[0] != '\0')
			{
				t.tokens[t.count_tokens++] = create_token(WORD, t.token_buffer);
				ft_memset(t.token_buffer, 0, ft_strlen(t.token_buffer));
				t.count_buffer = 0;
			}
		}
		s = tokenizer_handle_quotes(&t, s);
		s++;
	}
	if (t.token_buffer[0] != '\0')
		t.tokens[t.count_tokens++] = create_token(WORD, t.token_buffer);
	free(t.token_buffer);
	return (t.tokens);
}

t_token_type	get_token_type(char *input)
{
	if (*input == '>')
	{
		if (*(input + 1) == '>')
			return (REDIRECT_APPEND);
		return (REDIRECT_OUT);
	}
	if (*input == '<')
	{
		if (*(input + 1) == '<')
			return (REDIRECT_HEREDOC);
		return (REDIRECT_IN);
	}
	if (*input == '|')
		return (PIPE);
	return (WORD);
}
