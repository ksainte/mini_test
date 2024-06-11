/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:02:06 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/11 13:44:08 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <readline/readline.h>
#include <readline/history.h>
# include <errno.h>
# include <string.h>

//CommandLineInterface.c
int 			cli();
void 			pwd(void);
int 			cd(char *cmd);
void			exit_err(int errnum);

typedef struct s_node
{
	int type;
	char *value;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

//command_parser
typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

typedef struct s_tokenizer
{
	t_token	**tokens;
	char	*token_buffer;
	bool	single_quote;
	bool	double_quote;
	int		count_tokens;
	int		count_buffer;
}	t_tokenizer;

typedef enum e_token_type
{
	WORD = 1,
	REDIRECT_IN = 2,
	REDIRECT_OUT = 3,
	PIPE = 4,
	REDIRECT_HEREDOC = 5,
	REDIRECT_APPEND = 6
}	t_token_type;

typedef enum s_token_type
{
	WORD = 1,
	REDIRECT_IN = 2,
	REDIRECT_OUT = 3,
	PIPE = 4,
	REDIRECT_HEREDOC = 5,
	REDIRECT_APPEND = 6,
	SINGLE_QUOTE = 7,
	DOUBLE_QUOTE = 8
}	g_token_type;

typedef struct s_node
{
	struct s_command	*command;
	struct s_node		*left;
	struct s_node		*right;
}	t_node;

typedef struct s_command
{
	int		type;
	char	*command;
	char	**arguments;
	char	*input_redirection;
	char	*output_redirection;
}	t_command;

t_token			*create_token(int type, char *value);
bool			is_special_char(char c);
void			free_token(t_token *token);
void			free_tokens(t_token **tokens);

t_token			**tokenizer(char *input);
t_token_type	get_token_type(char *input);
g_token_type	get_type_token(char *rl);

void			parseinput(char *input);

#endif