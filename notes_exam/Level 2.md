Can be any of the 20 Functions/Programs Below:

## alpha_mirror:

Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.
Case is not changed.
If the number of arguments is not 1, display only a newline.
Examples:
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror  "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$

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

int main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
	return (0);
}
```
## camel_to_snake:

## do_op
## ft_atoi
## ft_strcmp
## ft_strcspn
## ft_strdup
## ft_strpbrk
## ft_strrev
## f## t_strspn
## inter
## is_power_of_2
## last_word
## max
## print_bits
## reverse_bits
## snake_to_camel
## swap_bits
## union
## wdmatch
