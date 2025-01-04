#include "../include/push_swap.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*(char *)s++ = '\0';
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == 0x20 || (c >= 0x09 && c <= 0x0d))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	nbr;

	i = 0;
	signal = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			signal = -1;
		}
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * signal);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s)
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == ch)
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (start + len > s_len)
	{
		len = s_len - start;
	}
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (0);
	while (s[start + i] != '\0' && i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static int	countword(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	free_all(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

static int	num(char const *s, char c, int word_len)
{
	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		word_len;
	int		i;

	lst = (char **)malloc((countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			lst[i] = ft_substr(s, 0, word_len = num(s, c, word_len));
			if (!(lst[i++]))
			{
				free_all(lst);
				return (NULL);
			}
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

