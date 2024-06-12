/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandLineInterface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:48 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/12 17:38:12 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_sim_double_quote(char *s, char doubles)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == doubles)
            return(1);
        i++;
    }
    return(0);
}

int ft_sim_single_quote(char *s, char single)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == single)
            return(1);
        i++;
    }
    return(0);
}

type    get_type_token(char *rl)
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
    else if (*rl == '\'')
        {
            if(!ft_sim_single_quote(rl + 1, '\''))
                exit(0);
            return(SINGLE_QUOTE);
        }
    else if (*rl == '\"')
        {
            if(!ft_sim_double_quote(rl + 1, '\"'))
                exit(0);
            return(DOUBLE_QUOTE);   
        }
	else
        return (WORD);
}
t_node	*ft_lastnode(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_add_back(t_node **list, t_node *new)
{
	if (!list)
		return ;
	if (!*list)
		*list = new;
	else
		(ft_lastnode(*list))->next = new;
}

t_node	*ft_stack_new(char *str, int return_value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(0);
    new->value = str;
	new->type = return_value;
	new->next = NULL;
	return (new);
}

int ft_token_len(const char *s, int c)
{
	char	ch;
    int     i;

	ch = (char) c;
    i = 0;
	while (s[i])
	{
		if(s[i] == ch)
            return(i);
		i++;
	}
	return(0);
}
int ft_word_len(const char *s)
{
    int     i;

    i = 0;
	while (s[i])
	{
        if((s[i] <= 12 && s[i] >= 9) || s[i] == 32 || s[i] == '<' || s[i] == '>' || s[i] == '|')
            return(i); 
        i++;
	}
	return(i);
}


char *ft_fill_token(char *rl, int value, int *len)
{
    char *str;

    if(value == SINGLE_QUOTE)
    {
        *len = ft_token_len(rl + 1, '\'');
        str = ft_substr(rl + 1, 0, *len);
        *len += 2;
    }
    else if(value == DOUBLE_QUOTE)
    {
        *len = ft_token_len(rl + 1, '\"');
        str = ft_substr(rl + 1, 0, *len);
        *len += 2;
    }
    else if(value == REDIRECT_IN || value == REDIRECT_OUT)
    {
        str = ft_substr(rl, 0, 1);
        *len = 1;
    }
    else if(value == REDIRECT_APPEND || value == REDIRECT_HEREDOC)
    {
        str = ft_substr(rl, 0, 2);
        *len = 2;
    }
    else if(value == PIPE)
    {
        str = ft_substr(rl, 0, 1);
        *len = 1;
    }
    else
    {
        *len = ft_word_len(rl);
        str = ft_substr(rl, 0, *len);
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
    // node = malloc(sizeof(t_node));
    node = NULL;
    while(rl[i])
    {
        if((rl[i] <= 12 && rl[i] >= 9) || rl[i] == 32) 
            i++;
        else if(rl[i])
        {
            return_value = get_type_token(rl + i);
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
    t_node *node_list;
    t_node *current;
    
        // rl = readline(">$ ");
        // printf("Tokenize %s:\n", rl);
        // rl = "heyou<my|friend";
        // node_list = ft_tokenize(rl);
    while(1)
    {
        rl = readline(">$ ");
        test = ft_strtrim(rl, " ");
        printf("Tokenize %s:\n", rl);
        node_list = ft_tokenize(rl);
        current = node_list;
        while(current)
        {
            printf("node has value:%s type:%d\n", current->value, current->type);
            current = current->next;
        }
        current = node_list;
        if (!(ft_strncmp(test, "exit", 5)))
        {
            free(test);
            clear_history();
            break;
        }
        if(*rl != '\0')
            add_history(rl);
    }
    // current = node_list;
    // while(current)
    // {
    //     printf("node has value:%s type:%d\n", current->value, current->type);
    //     current = current->next;
    // }
    // current = node_list;
    return (0);
}