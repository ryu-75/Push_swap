#include "push_swap.h"

char    exit_fail()
{
    ft_putstr_fd("Error\n", 1);
    return (1);
}

int ft_isnum(char *str)
{
    if (*str >= 0 && *str <= 9)
        return (1);
    return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i] && s1[i] != '\0')
    {
        j = 0;
        while (s2[j] && s2[j] != '\0')
        {
            if (s1[i] == s2[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
/*
int found_space(int ac, char **av, int c)
{
    int i;

    i = 1;
    while (av[ac][i] != '\0' && ac > 0)
    {
        i = 0;
        while (av[ac][i])
        {
            if (av[ac][i] == c)
                return (1);
            i++;
        }
        ac--;
    }
    return (0);
}
*/

char *check_argument(int ac, char **av)
{
    int i;
    char    *tmp;

    i = 0;
    if (!tmp)
        return (NULL);
    if (ac > 0)
    {
        tmp = ft_strjoin(&av[ac][i], &av[ac][i + 1]);
        while (tmp[i + 1])
            i++;
        ac--;
    }
    return (tmp);
}

int get_my_nb(char *str)
{
    int i;
    int neg;
    int value;

    value = 0;
    i = 0;
    neg = 1;
    while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        value = value * 10 + str[i] - '0';
        i++;
    }
    return (value * neg);
}

int	ft_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_sjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*tab;

	newstr = NULL;
	newstr = malloc(ft_len(s1) + ft_len(s2) + sizeof(char));
	if (!newstr)
		return (NULL);
	tab = newstr;
	while (*s1 != '\0')
		*newstr++ = *s1++;
	while (*s2 != '\0')
		*newstr++ = *s2++;
	*newstr = '\0';
	free(newstr);
	return (tab);
}

int main(int argc, char *argv[])
{
    int i;
    char    *str;

    str = check_argument(argc, argv);
    i = 0;
    if (argc == 2)
    {
        while (i < argc)
        {
            printf("%c\n", str[i]);
            i++;
        }
    }
    return (0);
}
