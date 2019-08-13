#### Run as it is right now
1. make
2. ./ft_printf
3. give 0 to run all the tests or
4. give a number from 1 to 6 to run the corresponding test

#### Modifiers are saved in the enum modifier (emiflake's suggestion)
- the first character is N for Null
- the next four characters are for the corresponding modifiers
H 	=> short
HH 	=> signed char
L 	=> long
LL 	=> long long

#### Flags, conversion type, minimum field width etc are saved in the struct 's_flagstruct' with the following fields :
	int			flags;          => an int where we save all the flags by setting the corresponding bits
	int			minfw;          => minimum field width
	int			precision;      => saving the number after the dot
	char		argtype;        => conversion type
	int			chars_printed;	=> to keep track how many chars where printed

#### The following flags are saved bitwise in an int named 'flags' :
- FLAG_MINUS (1 << 0)				=> 0000 0000 0001
- FLAG_PLUS (1 << 1)				=> 0000 0000 0010
- FLAG_SPACE (1 << 2)				=> 0000 0000 0100
- FLAG_ZERO (1 << 3)				=> 0000 0000 1000
- FLAG_HT (1 << 4)				=> 0000 0001 0000
- FLAG_APOSTR (1 << 5)			=> 0000 0010 0000
- FLAG_PRECIS (1 << 6)			=> 0000 0100 0000