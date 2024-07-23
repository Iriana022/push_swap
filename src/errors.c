#include "../include/push_swap.h"

void	check_error(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			show_error_mess();
	}
}

void	show_error_mess(void)
{
	ft_printf("Error\n");
	exit(1);
}

size_t	count_size(int ac, char **av)
{
	int 	i;
	int	j;
	int	counter;
	char	**arg;


	counter = 0;
	i = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (NULL == arg)
			exit(1);
		j = -1;
		while (arg[++j] != NULL)
			++counter;
	}
	return (counter);
}

void	check_double(int ac, char **av)
{
	int	*tab;
	int	size;

	size = count_size(ac, av);
}

/*
 * Return error if 
 *  - some parameters are not number
 *  - not contained in a int
 *  - has a double
 */
void	handle_errors(int ac, char **av)
{
	int 	i;
	int	j;
	int	n;
	char	**arg;

	i = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (NULL == arg)
			exit(1);
		j = -1;
		while (arg[++j] != NULL)
		{
			check_error(arg[j]);
			n = ft_atol(arg[j]);
			printf("%d\n", n);
			if (!(n >= INT_MIN && n <= INT_MAX))
				show_error_mess();
		}
	}
	check_double(ac, av);
}
