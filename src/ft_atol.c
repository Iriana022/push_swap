#include "../include/push_swap.h"

static long long	pow_ten(int c)
{
	if (c == 0)
		return (1);
	else
		return (10 * pow_ten(c - 1));
}

static char	*validate_str(const char *str, int *isnegative)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*isnegative = -1;
		str++;
	}
	return ((char *)str);
}

static long long	len_digit(char *s)
{
	int	i;

	i = 0;
	while (ft_isdigit(*s))
	{
		i++;
		s++;
	}
	return (i);
}

long long	ft_atol(const char *nptr)
{
	long long	len_nptr;
	long long	val_ret;
	char		*ch_nptr;
	int		signe;

	val_ret = 0;
	signe = 1;
	ch_nptr = (char *)nptr;
	ch_nptr = validate_str(nptr, &signe);
	if (*nptr == '\0')
		return (0);
	len_nptr = len_digit(ch_nptr);
	while (len_nptr && ft_isdigit(*ch_nptr))
	{
		val_ret += ((*ch_nptr) - 48) * pow_ten(len_nptr - 1);
		len_nptr--;
		ch_nptr++;
	}
	return (val_ret * signe);
}
