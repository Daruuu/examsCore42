
#include "atoi.c"
#include "strcmp.c"
#include "strcspn.c"

#include <stdio.h> 
#include <string.h> 
/*
int	main()
{
	//int	res;
	//res = ft_atoi("  -1231231233");
	//printf("%d", res);

	char	s1[20] = "hello world";
	char	s2[20] = "d";

	//res = ft_strcmp(s1, s2);
	//printf("%d\n", res);
	//printf("%d\n", strcmp(s1, s2));

	size_t	res;

	res = ft_strcspn(s1, s2);
	printf("%zu\n", res);
	printf("%zu\n", strcspn(s1, s2));
	return (0);
}
*/

#include "strdup.c"
/*
int	main()
{
	int	i;
	char	src[20] = "hello_ world";

	ft_strdup(src);
	i = 0;
	while (src[i] != '\0')
		i++;
	printf("%d\n", i);

	strdup(src);
	i = 0;
	while (src[i] != '\0')
		i++;
	printf("%d\n", i);

	return (0);
}
*/
/*
#include "strpbrk.c"
int	main()
{
	const char	src[20] = "hello_ world";
	const char	charset[2] = "_";

	ft_strpbrk(src, charset);
	printf("%s\n", ft_strpbrk(src, charset));

	strpbrk(src, charset);
	printf("%s\n", strpbrk(src, charset));

	return (0);
}
*/
#include "strrev.c"
/*
int	main()
{
	char	str[10] = "daruny";
	char	*res;
	res = ft_strrev(str);
	printf("%s\n", res);

	return (0);
}
*/

#include "max.c"
int	main()
{
	int	tab[5] = {11, 4, 78, 77, 90};
	int	res;
	//int	len = sizeof(tab);

	res = ft_max(tab, 5);
	printf("%d\n", res);

	return (0);
}
