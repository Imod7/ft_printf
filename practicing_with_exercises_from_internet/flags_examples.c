#include <stdio.h>
#include "../ft_printf.h"

int			main(void)
{
	double	num;
	int		num1;
	int		a;
	int		b;
	int		c;
	int 	e;
	int		*d;
	int		f;

	num = 9546.3453453;
	num1 = 9;
	e = 10;
	d = &e;
	f = 29;

	printf(ANSI_COLOR_CYAN "FLAG +\n" ANSI_COLOR_RESET);
	printf("Checking the padding '%+5.2f'\n", num);
	printf("Value of num1 using %%d is = %d\n", num1);
	printf("Value of num1 using %%i is = %i\n", num1);
/*
** Demonstrate difference between %i and %d specifier
*/
	printf("Value in decimal formal eg.12\n");
	printf("Enter value of a in decimal format:");
	scanf("%d", &a);
	printf("Value in octal formal should be preceded by 0 eg.012\n");
	printf("Enter value of b in octal format:");
	scanf("%i", &b);
	printf("Value in hexadecimal formal should be preceded by 0x eg.0x12\n");
	printf("Enter value of c in hexadecimal format:");
	scanf("%i", &c);
	printf("a = %i, b = %i, c = %i\n", a, b, c);
/*
** Difference between %p and %x specifier
*/
	printf("%p\n", d);
	//printf("%X\n", d);
	printf("%x\n ", f);		/* just prints f */
	printf("Prints value of f ('0' on its own has no effect) -> %0x\n ", f);
	printf("%8x\n ", f);	/* print in 8 width and pad with blank spaces */
	printf("%08x\n ", f);   /* print in 8 width and pad with 0's */
	return (0);
}
