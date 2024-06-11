/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeParserHelper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:10:45 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/07 11:17:42 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
FUNCTION CreateNode(Command command) RETURNS Node
    ALLOCATE Node node
    SET node.command TO command
    SET node.left TO NULL
    SET node.right TO NULL
    RETURN node
END FUNCTION

FUNCTION CreateCommand(CommandType type, STRING cmd) RETURNS Command
    ALLOCATE Command command
    SET command.type TO type
    SET command.command TO cmd
    SET command.arguments TO EMPTY LIST
    SET command.input_redirection TO NULL
    SET command.output_redirection TO NULL
    RETURN command
END FUNCTION

FUNCTION PrintTree(Node root, INTEGER level)
    IF root IS NULL THEN RETURN

    PRINT SPACES(level * 2) + "Command: " + root.command.command
    IF root.command.arguments IS NOT EMPTY THEN
        PRINT SPACES(level * 2) + "Arguments: " + JOIN(root.command.arguments, " ")
    END IF
    IF root.command.input_redirection IS NOT NULL THEN
        PRINT SPACES(level * 2) + "Input Redirection: " + root.command.input_redirection
    END IF
    IF root.command.output_redirection IS NOT NULL THEN
        PRINT SPACES(level * 2) + "Output Redirection: " + root.command.output_redirection
    END IF

    CALL PrintTree(root.left, level + 1)
    CALL PrintTree(root.right, level)
END FUNCTION

FUNCTION FreeTree(Node root)
    IF root IS NULL THEN RETURN

    CALL FreeTree(root.left)
    CALL FreeTree(root.right)
    DEALLOCATE root.command.command
    DEALLOCATE root.command.arguments
    DEALLOCATE root.command.input_redirection
    DEALLOCATE root.command.output_redirection
    DEALLOCATE root.command
    DEALLOCATE root
END FUNCTION
*/