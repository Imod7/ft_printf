#include <stdio.h>
#include <stdarg.h>

int				sumnum(int num, ...)
{
	int			sum;
	va_list		argptr;
	int			count;

	sum = 0;
	count = 0;
	va_start(argptr, num);
	while (count < num)
	{
		sum += va_arg(argptr, int);
		count++;
	}
	va_end(argptr);
	return (sum);
}

void			printstr(int num, ...)
{
	int			count;
	char		*ptr;
	va_list		argptr;

	count = 0;
	va_start(argptr, num);
	while (count < num)
	{
		ptr = va_arg(argptr, char *);
		printf("ptr = %s\n", ptr);
		count++;
	}
	va_end(argptr);
}

void			print_ints(int num, ...)
{
	va_list		args;
	int			count;
	int			value;

	count = 0;
	va_start(args, num);
	while (count < num)
	{
		value = va_arg(args, int);
		printf("%d: %d\n", count, value);
		count++;
	}
	va_end(args);
}

int				main(int argc, char *argv[])
{
	int			total;
	char		c;
	short		b;

	b = 12;
	c = '1';
	total = sumnum(6, 3, 5, 7, 6, 4, 66);
	printf("total = %d\n", total);
	printf("hhd = %hhd\n", c);
	printf("short = %hd\n", b);
	printstr(3, "one", "two", "three");
	print_ints(3, 24, 26, 312);
	return (0);
}
