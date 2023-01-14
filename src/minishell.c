#include "minishell.h"

void	free_stable(char **table, size_t size)
{
	size_t i;

	i = 0;
	if (table == NULL)
		return ;
	while (i < size)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_table(char **table)
{
	size_t i;

	i = 0;
	if (envp == NULL)
		return ;
	while (envp[i] != NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

char **minishell_start(char **envp)
{
	char **envp_cpy;
	size_t i;
	size_t envp_size;

	i = 0;
	envp_size = 0;
	while (envp[envp_size] != NULL)
		envp_size++;
	if (!(envp_cpy = (char**)malloc(sizeof(char*) * (envp_size + 1))))
		return (NULL);
	while (i < envp_size)
	{
		if (!(envp_cpy[i] = 
			(char*)malloc(sizeof(char) * (strlen(envp[i]) + 1))))
		{
			free_stable(envp_cpy, i);
			return (NULL);
		}
		strcpy(envp_cpy[i], envp[i]);
		i++;
	}
	envp_cpy[i] = NULL;
	return (envp_cpy);
}

void minishell()
{
	char *command;
	char **command_table;

	while (1)
	{
		write(STDOUT_FILENO, "$>", 2);
		get_next_line(STDIN_FILENO, &command);
		printf("[%s]\n", command);
		command_table = ft_split(command);
		for (int i = 0; command_table[i] != NULL; i++)
			printf("%d: [%s]\n", i+1, command_table[i]);
		free(command);
		free_table(command_table);
	}
}

int main(int argc, char *argv[], char **envp)
{
	char **envp_cpy;

	if (!(argc == 1 || !strcmp(argv[0], "minishell")))
		return (EXIT_FAILURE);
	envp_cpy = minishell_start(envp);
	minishell(envp);
	free_envp(envp_cpy);
	return (EXIT_SUCCESS);
}
