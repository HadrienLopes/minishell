#include "ft_pwd.h"

void	ft_pwd()
{
	size_t i;
	char errsv;
	char *cwd;

	i = 1;
	errsv = errno;
	errno = 0;
	while (i < 1024)
	{
		if (!(cwd = (char*)malloc(sizeof(char) * (PWD_SIZE * i))))
			return ;
		cwd = getcwd(cwd, (PWD_SIZE * i));
		if (errno != ERANGE)
			break ;
		errno = 0;
		free(cwd);
		i++;
	}
	if (errno == 0)
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	else
		fprintf(stderr, "%s\n", strerror(errno));
	errno = errsv;
}


