/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:07:11 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/07 17:28:09 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_err(int errnum)
{
	perror(strerror(errnum));
	exit(EXIT_FAILURE);
}

int cd(char *cmd)
{
    int return_value;
    
    return_value = chdir(cmd);
    if(return_value == -1)
        exit_err(errno);
    return (return_value);
}

void pwd(void)
{
    char *pwd;
    
    pwd = getcwd(NULL, 0);
    if(pwd == NULL)
         exit_err(errno);
    printf("%s\n", pwd);
}

void ft_echo_no(char **list, int len)
{
    int i;

    i = 0;
    write(1, "\n", 1);
    while(list[i])
    {
        if(i == len - 1)
        {
            printf("%s", list[i]);
            break;
        }
        printf("%s ",list[i]);
        i++;
    }
}
int  ft_echo(char **list)
{
    int i;
    int len;
        
    len = 0;
    while(list[len])
        len++;
    i = 0;
    if(list[0][0] == '-' && list[0][1] == 'n')
    {
        while(list[i])
        {
            if(i == len - 1)
            {
                printf("%s", list[i]);
                return(0);
            }
             printf("%s ",list[i]);
             i++;
        }
    }
    ft_echo_no(list, len);
    return(0);
}