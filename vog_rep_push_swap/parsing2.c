
#include "push_swap.h"

int is_within_int_range(char *str, int overflow)
{
    if (valid_num_check(str))
	{   
        long long num = ft_atoll2(str, &overflow);
	    return (num <= INT_MAX && num >= INT_MIN);
    }
    else
        return (0);
}

long long	ft_atoll(const char *str, long *j)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		(*j)++;
	}
	return (result * sign);
}

int	ft_atoll2_skip_whitespace_and_sign(const char *str, int *i)
{
	int sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long long	ft_atoll2(const char *str, int *overflow)
{
	int			i;
	int			sign;
	int			digit;
	long long	res;

	i = 0;
	*overflow = 0;
	res = 0;
	sign = ft_atoll2_skip_whitespace_and_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (res > (9223372036854775807LL - digit) / 10)
		{
			*overflow = 1;
			if (sign == 1)
				return (9223372036854775807LL);
			return (-9223372036854775807LL - 1);
		}
		res = res * 10 + digit;
		i++;
	}
	return (sign * res);
}
