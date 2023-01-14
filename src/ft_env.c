#include "ft_env.h"

void ft_env(char **envp)
{
	size_t i;

	i = 0;
	if (envp == NULL)
		return ;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
