#include <push_swap.h>

void	show_error_mess(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	check_double(t_data *data)
{
	t_data	*curr;
	t_data	*tmp;

	curr = data;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (curr->content == tmp->content)
				show_error_mess();
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

void	check_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+'))
			++i;
		else if (!ft_isdigit(s[i]))
		{
			show_error_mess();
			++i;
		}
		else
			++i;
	}
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

/*
 * Return error if 
 *  - some parameters are not number
 *  - not contained in a int
 *  - has a double
 */
void	handle_errors(int ac, char **av)
{
	int 		i;
	int		j;
	long long int	n;
	char		**arg;

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
			if (!(n >= INT_MIN && n <= INT_MAX))
				show_error_mess();
		}
	}
	//free(arg);
}
