/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandLineInterface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:48 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/11 19:32:09 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_sim_double_quote(char *s, char doubles, char single)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == doubles)
            return(1);
        if(s[i] == single)
            return(0);
        i++;
    }
    return(0);
}

int ft_sim_single_quote(char *s, char single, char doubles)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == single)
            return(1);
        if(s[i] == doubles)
            return(0);
        i++;
    }
    return(0);
}

g_token_type	get_type_token(char *rl)
{
	if (*rl == '>')
	{
		if (*(rl + 1) == '>')
			return (REDIRECT_APPEND);
		return (REDIRECT_OUT);
	}
	else if (*rl == '<')
	{
		if (*(rl + 1) == '<')
			return (REDIRECT_HEREDOC);
		return (REDIRECT_IN);
	}
	else if (*rl == '|')
		return (PIPE);
    else if (*rl == '\'' && ft_sim_single_quote(rl + 1, '\'', '\"'))
            return(SINGLE_QUOTE);
    else if (*rl == '\"' && ft_sim_double_quote(rl + 1, '\"', '\''))
        return(DOUBLE_QUOTE);
	return (WORD);
}
// int ft_check_quotes(char *rl)
// {
//     int i;

//     i = 0;
//     while(rl[i])
//     {
//         if()
//     }
// }

void	ft_add_back(t_node **list, t_node *new)
{
	if (!list)
		return ;
	if (!*list)
		*list = new;
	else
		(ft_lastnode(*list))->next = new;
}

t_node	*ft_lastnode(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_stack_new(char *str, int return_value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_error();
    new->value = str;
	new->type = return_value;
	new->next = NULL;
	return (new);
}

// int ft_token_len(const char *s, int c)
// {
// 	char	ch;
//     int     i;

// 	ch = (char) c;
//     i = 0;
// 	while (s[i])
// 	{
// 		if(s[i] == ch)
//             return(i);
// 		i++;
// 	}
// 	return(0);
// }
int ft_token_len(const char *s, char *c)
{
	char	ch;
    int     i;
    int     j;

    i = 0;
	while (s[i])
	{
        j = 0;
        while(c[j])
        {
		    if(s[i] == c[j])
                return(i);
		    j++;
        }
        i++;
	}
	return(0);
}
char *ft_break_word(void)
{
    char *str;

    str = (char*)malloc(11);
    str[0] = 9;
    str[1] = 10;
    str[2] = 11;
    str[3] = 12;
    str[4] = 32;
    str[5] = '<';
    str[6] = '>';
    str[7] = '|';
    str[8] = '\0';
    return(str);
}

char *ft_fill_token(char *rl, int value, int *len)
{
    char *str;

    if(value == SINGLE_QUOTE)
    {
        *len = ft_token_len(rl + 1, "\'");
        str = ft_substr(rl + 1, 0, len);
        *len += 2;
    }
    else if(value == DOUBLE_QUOTE)
    {
        *len = ft_token_len(rl + 1, "\"");
        str = ft_substr(rl + 1, 0, len);
        *len += 2;
    }
    else if(value == REDIRECT_IN || value == REDIRECT_OUT)//'>'
    {
        str = ft_substr(rl, 0, 1);
        *len = 1;
    }
    else if(value == REDIRECT_APPEND || value == REDIRECT_HEREDOC)//'>'
    {
        str = ft_substr(rl, 0, 2);
        *len = 2;
    }
    else if(value == PIPE)//'>'
    {
        str = ft_substr(rl, 0, 1);
        *len = 1;
    }
    else if(value == WORD)
    {
        *len = ft_token_len(rl, ft_break_word());
        str = ft_substr(rl, 0, len);
    }
    return(str);
}

t_node *ft_tokenize(char *rl)
{
    t_node *node;
    int i;
    int return_value;
    char *tmp;
    int len;

    // ft_check_quotes(rl);
    i = 0;
    len = 0;
    node = 0;
    while(rl[i])
    {
        if(rl[i] <= 12 && rl[i] >= 9 || rl[i] == 32) 
            i++;
        else if(rl[i])
        {
            return_value = get_token_type(rl + i);
            tmp = ft_fill_token(rl + i, return_value, &len);
            ft_add_back(&node, ft_stack_new(tmp, return_value));
        }
        i = i + len;
        len = 0;
    }
    return(node);
}

int cli()
{
    char *rl;
    char *test = 0;
    // t_token **tokki;
    t_node *node_list;
    
    while(1)
    {
        rl = readline(">$ ");
        test = ft_strtrim(rl, " ");
        printf("Tokenize %s:\n", rl);
        node_list = ft_tokenize(rl);
        // tokki = tokenizer(test);
        // int i = 0;
	    // printf("Tokenize %s:\n", rl);
	    // while (tokki[i] != NULL)
	    // {
		// printf("Token type: %d, value: %s\n", tokki[i]->type, tokki[i]->value);
		// i++;
	    // }
        if (!(ft_strncmp(test, "exit", 5)))
        {
            free(test);
            clear_history();
            break;
        }
        if(*rl != '\0')
            add_history(rl);
    }
    return (0);
}