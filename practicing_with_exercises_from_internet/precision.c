/*
** integer value or * that specifies minimum field width. The result is padded with space characters (by default), 
** if required, on the left when right-justified, or on the right if left-justified. In the case when * is used, 
** the width is specified by an additional argument of type int. 
** If the value of the argument is negative, it results with the - flag specified and positive field width. 
** (Note: This is the minimum width: The value is never truncated.)

** . followed by integer number or *, or neither that specifies precision of the conversion. In the case when * is used,
** the precision is specified by an additional argument of type int. If the value of this argument is negative, it is ignored.
** If neither a number nor * is used, the precision is taken as zero. See the table below for exact effects of precision.
*/

/*
You can use an asterisk (*) to pass the width specifier/precision to printf(), rather than hard coding it into the format string
*/

/*
** %010d says to zero-pad to a minimum width of 10 digits. No problem there.
** %.10d", because you're using %d, says the minimum number of digits to appear is 10.
** So the same thing as zero padding. %.10f would behave more like you expected.
** I would recommend you use %010d to zero pad. The %.10d form is a surprising feature that
** might confuse readers. I didn't know about it and I'm surprised it isn't simply ignored.
*/

#include <stdio.h>

int             main() 
{
    int         precision;
    int         biggerPrecision;
    const char  *greetings = "Hello world";

    precision = 8;
    biggerPrecision = 16;
    printf("Initial string : 'Hello world'\n");
    printf("==============================\n\n");
    printf("|%.8s|\n", greetings);
    printf("|%.*s|\n", precision , greetings);
    printf("|%16s|\n", greetings);
    printf("|%*s|\n", biggerPrecision , greetings);
	printf("Test : %010d\n", 10);
	printf("Test : %.10d\n", 10);
    return (0);
}
