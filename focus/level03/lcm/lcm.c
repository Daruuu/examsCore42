
unsigned int gcd(unsigned int a, unsigned int b)
{
	unsigned int	tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}
unsigned int lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return (a / gcd(a, b)) * b;
}