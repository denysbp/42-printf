#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static void	free_all(char **array, int n)
{
	while (n >= 0)
	{
		free(array[n]);
		n--;
	}
	free(array);
}

static char	*get_word(const char *s, int start, int end)
{
	return (ft_substr(s, start, end - start));
}

static int	fill_array(char **array, const char *s, char c, int words)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	end = 0;
	while (s[i] && end < words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array[end] = get_word(s, start, i);
		if (!array[end])
			return (free_all(array, end - 1), 0);
		end++;
	}
	array[end] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	if (!fill_array(array, s, c, words))
		return (NULL);
	return (array);
}
