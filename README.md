#### Run as it is right now
1. make
2. ./ft_printf
3. give 0 to run all the tests or
4. give a number from 1 to 38 to run the corresponding test

#### Modifiers are saved in the enum modifier (emiflake's suggestion)
- the first character is N for Null
- the next four characters are for the corresponding modifiers
H 	=> short
HH 	=> signed char
L 	=> long
LL 	=> long long

#### Flags, conversion type, minimum field width etc are saved in the struct 's_flagstruct' with the following fields :
- int		flags;          => an int where we save all the flags by setting the corresponding bits
- int		minfw;          => minimum field width
- int		precision;      => saving the number after the dot
- char		argtype;        => conversion type
- int		chars_printed;	=> to keep track how many chars where printed

#### The following flags are saved bitwise in an int named 'flags' :
- FLAG_MINUS (1 << 0)			=> 0000 0000 0001
- FLAG_PLUS (1 << 1)			=> 0000 0000 0010
- FLAG_SPACE (1 << 2)			=> 0000 0000 0100
- FLAG_ZERO (1 << 3)			=> 0000 0000 1000
- FLAG_HT (1 << 4)				=> 0000 0001 0000
- FLAG_APOSTR (1 << 5)			=> 0000 0010 0000
- FLAG_PRECIS (1 << 6)			=> 0000 0100 0000

### The flow of ft_printf when it is executed :
When **ft_printf** function is called :
- **clear_formatstruct** function is called to clear the struct
- **save_flags** function is called to save all flags, conversion type and modifiers
- **print_arg** function is called to print the argument with the correct formatting

#### when print_arg is called :
- first it verifies if there is an asterisk flag to call va_arg for the 1st argument
- then checks which conversion type we have
- depending on the conversion type that we have, the corresponding function is called
- eg. if conversion type = 'x', the function **print_hex** is called

##### when print_hex function is called :
- we retrieve the first argument (as a long long) from the va_list with the command va_arg 
- then the function **check_modif_un** is called which checks which modifier we have and typecasts respectively
- then the function **number_of_digits_un** is called to get the length of the hex argument in chars
- then we check if the conversion type is 'p' so we have to increase member 'special_chars_printed' by 2
- then we increase **total_chars_printed** by the length
- if FLAG_MINUS is present :
	function 'print_hex_ch' is called where :
	1. if FLAG_HT is present
		1.1 we write 0x
		1.2 increase the total_chars_printed by 2 
		1.3 increase the special_chars_printed by 2 
	2. if argtype = 'p'
		2.1 we write 0x
		2.2 increase the total_chars_printed by 2 
	3. if argtype = 'X'
		3.1 ft_putnbr_hex_capit
	4. if not function ft_putnbr_hex is called
	function print_sign is called
	function print_padding is called

- if FLAG_ZERO is is present 
	1. print_flagzero_on is called
	2. print_hex_ch is called

- In all other cases :
	1. print_padding is called first
	2. print_sign is called
	3. print_hex_ch is called


##### when print_integer function is called :
- the function **check_modifier** is called which checks which modifier we have and va_arg accordingly
- then the function **number_of_digits** is called to get the length of the integer in chars
- then we increase **total_chars_printed** by the length
- if FLAG_MINUS is present :
	- **int_with_minus** function is called
- else
	- **int_with_zero** function is called

##### when print_float function is called :
- for the integer part of the float 
	- if MINUS is present, the function **int_with_minus** is called
	- if MINUS is not present, the function **int_with_zero** is called
- for the decimal part, the function **return_decimal_part_as_int** is called
- a dot is printed
- the function **number_of_digits** is called and updates the member **float_decpart_len**
- the member **total_chars_printed** is increased by the length
- function **print_padding** is called
- function **ft_putnbr_int** is called

##### print_padding function :
- variable 'arg_digits_len' -> the number of digits that our argument has, eg. for int argument 234, variable arg_digits_len should be 3
- in print_string : the print_padding function is called only if (len != 0 && t_flags.minfw != 0)

##### variable (*t_flags).minfw affected in functions :
1. function save_flags
2. function print_arg
