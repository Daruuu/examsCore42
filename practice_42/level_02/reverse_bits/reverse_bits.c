unsigned char	reverse_bits_0(unsigned char octet)
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


// VERSION CHATGPT
unsigned char reverse_bits_1(unsigned char octet)
{
    int i = 8;
    unsigned char res = 0;

    while (i > 0)
    {
		// Mueve los bits de 'res' y añade el bit menos significativo de 'octet'
		res = (res << 1) | (octet & 1); 
		// Desplaza 'octet' hacia la derecha para procesar el siguiente bit
        octet >>= 1; 
        i--;
    }
    return res;
}

#include <stdio.h>


