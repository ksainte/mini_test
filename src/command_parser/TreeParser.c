/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeParser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:10:41 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/07 11:17:18 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
FUNCTION ParseTokensToTree(LIST OF Token tokens) RETURNS Node
    SET root TO NULL
    SET current TO NULL

    FOR EACH Token token IN tokens DO
        IF token.type IS TOKEN_WORD THEN
            IF current IS NULL THEN
                SET Command cmd TO CreateCommand(COMMAND_SIMPLE, token.value)
                SET root TO CreateNode(cmd)
                SET current TO root
            ELSE
                ADD token.value TO current.command.arguments
            END IF
        ELSE IF token.type IS TOKEN_PIPE THEN
            SET Command cmd TO CreateCommand(COMMAND_PIPE, NULL)
            SET Node pipe_node TO CreateNode(cmd)
            SET current.right TO pipe_node
            SET current TO pipe_node
        ELSE IF token.type IS TOKEN_REDIR_IN THEN
            SET current.command.input_redirection TO token.value
        ELSE IF token.type IS TOKEN_REDIR_OUT THEN
            SET current.command.output_redirection TO token.value
        END IF
    END FOR

    RETURN root
END FUNCTION
*/