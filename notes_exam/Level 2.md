## LEVEL 2
Can be any of the 20 Functions/Programs Below:

## alpha_mirror:

Examples:
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror  "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$

NOTA:
- str[i] = ('A' + 'Z' ) - str[i];

``` c
void	alpha_mirror(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ('A' + 'Z') - str[i];
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ('a' + 'z') - str[i];
		write(1, &str[i], 1);
		i ++;
	}
}
```
## camel_to_snake:

## do_op
## ft_atoi

NOTA:

``` c
while (str[i] >= '0' && str[i] <= 13)
{
	result = result * 10 + str[i] - '0';
	i ++;
}
```
## ft_strcmp

- NOTA:

``` c
int    ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}
```
## ft_strcspn

- NOTA:

``` c
	if (s[i] == reject[j])
		return (i);
```
## ft_strdup
## ft_strpbrk

- NOTA:
	- if s1 es igual que s2 -> retornar posicion de memoria de str[i]   

``` c
	if (s1[i] == s2[j])
		return ((char *)&s1[i]);

return (NULL);
```
## ft_strrev

- NOTA:
	-  La primera posicion del string ha de ser la ultima posicion del string

##  ft_strspn

- NOTA:
	- Si s[i] == accept[j]
		- break;
``` c
size_t	ft_strspn(const char *s, const char *accept)
{
	int i, j;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				break ;
			j ++;
		}
		if (accept[j] == '\0')
			break ;
		i ++;
	}
	return (i);
}
```
## inter
- NOTA:
	- crear una variable tipo char: ascii_table[256] = {0};
	- si s1[i] == s2[j]
	- if ( !ascci_table[(unsigned char)s1[i]])
	- hacemos un write(str[i]);
	- actualizamos ascii_table a valor 1 del caracter anterior
``` c
void	inter(char *s1, char *s2)
{
	int	i, j;
	char	ascii_table[256] = {0};
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				if (!ascii_table[(unsigned char)s1[i]])
				{
					write(1, &s1[i], 1);
					ascii_table[(unsigned char)s1[i]] = 1;
				}
				break ;
			}
			j ++;
		}
		i ++;
	}
}
```
## is_power_of_2
- NOTA:

``` C
int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return (n & (n - 1)) == 0;
}
```
## last_word

- NOTA:
- al tener la strlen des str | hacer un i-- para retroceder al ultimo espacio
``` C
void	last_word(char *str)
{
	int i, start, end;
	i = 0;
	while (str[i] != '\0')
		i ++;
	i --;// importante para retroceder el nulo
	while (i > 0 && (str[i] == ' ' || str[i] == '\t'))
		i --;
	end = i;
	while (i > 0 && (str[i] != ' ' && str[i] != '\t'))
		i --;
	start = i + 1;
	while (start <= end)
	{
		write(1, &str[start], 1);
		start ++;
	}
}
```
## max
- NOTA:
``` C
int		max(int* tab, unsigned int len)
{
	int				max;
	unsigned int	i;
	i = 0;
	if (len == 0)// importante if
		return (0);
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i ++;
	}
	return (max);
}
```
## print_bits

- NOTA:

``` C
void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
```
## reverse_bits

- NOTA:
	-  los 2 casos son validos.

``` c
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
	}
	return (res);
}
```

``` c
unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}
```
## snake_to_camel
## swap_bits
- NOTA:

``` c
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | ( octet << 4));
}
```

## union

- NOTA:
	- iterar por cada parametro;
	- actualizando ascii_table cada vez que se itera por string 
	
``` c
void	ft_union(char *s1, char *s2)
{
	int i, j;
	char	ascii_table[256] = {0};
	i = 0;
	while (s1[i] != '\0')
	{
		if (!ascii_table[(unsigned char)s1[i]])
		{
			write(1, &s1[i], 1);
			ascii_table[(unsigned char)s1[i]] = 1;
		}
		i ++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		if (!ascii_table[(unsigned char)s2[j]])
		{
			write(1, &s2[j], 1);
			ascii_table[(unsigned char)s2[j]] = 1;
		}
		j ++;
	}
}
```
## wdmatch

``` c
void	wdmatch(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
		{
			i ++;
		}
		j ++;
	}
	if (s1[i] == '\0')
	{
		i = 0;
		while (s1[i] != '\0')
		{
			write(1, &s1[i], 1);
			i ++;
		}
	}
}
```


## LEVEL 3

## add_prime_sum
- NOTE:
	- necesitamos crear ft_atoi para  convertir av[1] -> a int numero

``` c
int ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i ++;
	}
	return (result * sign);
}

int is_prime(int num)
{
	int i = 2;
	if (num < 2)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

void	put_nbr(int num)
{
	char	digit;
	if (num > 9)
		put_nbr(num / 10);
	digit = num % 10 + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nbr = ft_atoi(av[1]);
		if (nbr > 0)
		{
			int sum = 0;
			while (nbr > 0)
			{
				if (is_prime(nbr))
					sum = sum + nbr;
				nbr --;
			}
			put_nbr(nbr);
		}
		else
			put_nbr(0);
	}
	else
		put_nbr(0);
	write(1, "\n", 1);
	return (0);
}
```

## epur_str

- NOTA:
``` c
void epur_str(char *str)
{
	int i = 0;

	// Ignorar espacios y tabs iniciales
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	int first_word;
	first_word = 1;
	// Iterar sobre el resto de la cadena
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (!first_word)
				write(1,  " ", 1);
			first_word = 0;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			{
				write(1, &str[i], 1);
				i ++;
			}
		}
		while (str[i] == '\t' || str[i] == ' ')
			i ++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return 0;
}
```
## expand_str

- NOTES:

``` c
void	expand_str(char *str)
{
	int i = 0;int flag;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		if (flag)
			write(1, "   ", 3);
		flag = 0;
		write(1, &str[i], 3);
		i ++;
	}
}
```
## ft_atoi_base

``` c
while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			value = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = str[i] - 'A' + 10;
		else
			break ;
		if (value >= str_base)
			break ;
		result = (result * str_base) + value;
		i ++;
	}
	return (result * sign);
```
## ft_list_size
## ft_range

- NOTA:
``` c
int *ft_range(int start, int end) {
	int i;
	int len;
	int *result;

	if (start < end)
		len = (end - start) + 1;
	else
		len = (start - end) + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (0);
	i = 0;
	if (start <= end) {
		while (start <= end) {
			result[i] = start;
			start++;
			i++;
		}
	} else {
		while (start >= end) {
			result[i] = start;
			start--;
			i++;
		}
	}
	return (result);
}
```
## ft_rrange
## hidenp
## lcm

``` c
unsigned int    gcd(unsigned int a, unsigned int b)  
{  
    while (b != 0)  
    {       int tmp = b;  
       b = a % b;       a = tmp;    }    return (a);  
}  
  
unsigned int    lcm(unsigned int a, unsigned int b)  
{  
    if (a == 0 || b == 0)  
       return (0);  
    return (a / gcd(a, b)) * b;  
}
```
## paramsum
## pgcd

``` c
int gcd(int a, int b)  
{  
    while (b != 0)  
    {       int tmp = b;  
       b = a % b;       a = tmp;    }    return (a);  
}  
  
int main(int ac, char **av)  
{  
    if (ac == 3)  
    {       int a = atoi(av[1]);  
       int b = atoi(av[2]);  
  
       if (a > 0 && b > 0)  
       {          printf("%d\n", gcd(a, b));  
       }    }    else  
       printf("\n");  
    return (0);  
}
```
## print_hex

``` c
#include <unistd.h>
#include <stdlib.h>

void	ft_puthex(unsigned int n)
{
	char *hex = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16);
	write(1, &hex[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_puthex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}

```
## rstr_capitalizer
## str_capitalizer
## tab_mult

``` c
void    putbnr(int n)  
{  
    char digit;  
  
    if (n > 9)  
       putbnr(n / 10);  
    digit = n % 10 + '0';  
    write(1, &digit, 1);  
}
void	ft_tab_mult(int n)
{
	int i = 1;
	int result;

	while (i <= 9)
	{
		putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		result = i * n;
		ft_putnbr(result);
		write(1, "\n", 1);
		i++;
	}
}
```
