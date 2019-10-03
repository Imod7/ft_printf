#### To Run the program in its current state
1. Clone the repo
2. Go into folder tests
3. make re 
2. ./ft_printf
3. give 0 to run all the tests or
4. give a number from 1 to 60 to run a specific test

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

##### print_padding function :
- variable 'arg_digits_len' -> the number of digits that our argument has, eg. for int argument 234, variable arg_digits_len should be 3
- in print_string : the print_padding function is called only if (len != 0 && t_flags.minfw != 0)

##### when print_string function is called :
- if arg is NULL then we write (null) and increase the total_chars_printed
- else :
	- calculate the length of string
	- call the print_sign function
	- check if len > precision
	- if FLAG_MINUS is ON

##### variable (*t_flags).minfw affected in functions :
1. function save_flags
2. function print_arg
3. function print_hex_octal

##### variable (*t_flags).special_chars_printed affected in functions :
1. function check_ht
2. function print_hex_octal
3. function print_padding
4. function print_sign
5. function check_modifier
6. function print_order

##### a ZERO is printed in functions :
1. function check_ht (if criteria are met)
2. function print_number (if criteria are met)

##### Deal with the ZERO argument in Octal :
1. function check_arg_zero
2. function print_number

##### Deal with the ZERO argument in Integer :
1. function print_integer
2. function check_arg_zero
3. function print_number

##### Deal with negative argument :
1. function check_negative_num
2. function print_sign

### Floats
1. Function "str_add_prod_frac"
   - length of product is always going to be equal or smaller than length of fraction
   - So I need to fill with zeros the extra positions that the fraction might have before starting the addition
   - Then I start from the end of both strings (that now are of equal size) and start adding the digits
   - I move the carry on to the next loop/addition
   - When I iterated all the decimal part of the strings, I check if my carry is bigger than zero
   - If it is, I add a 1 before my dot

##### Floats Precision 
1. If precision == 0 then precision is set to 6
2. If precision != 0, we take the precision specified

##### Floats Rounding
1. Check cases :
	- If next_digit (one digit after precision) is bigger than 5 and precision is not ZERO
		- function 'dec_part_rounding' is called
	- If next_digit (one after precision) is less than 5 and precision is not ZERO
		- then we leave the current_digit (that equals to precision) as it is
	- If next_digit (one digit after precision) is equal to 5 and precision is not ZERO
		- Then function 'equal_five' is called
	- If precision is ZERO
		- Then function 'zero_prec_rounding' is called which increments the digit before the dot of the float

##### Floats Rounding - function 'dec_part_rounding'
- Then keep increment the digits that are before the precision until the remainder is different is zero and the index of precision is zero.
- Check if the current_digit after incrementing results to 10 then set it to 0

##### Floats Rounding - function 'equal_five'
This function is called when the next_digit (one digit after precision) of the float equals five.
In that case, we use a temp variable to store the current_digit (that equals to our precision) incremented by one and check :
- If variable temp is even and different than 10 -> we just increment the current_digit 
- If variable temp is 10 -> we keep setting the current_digit equal to 0 (or the result of temp % 10) and checking also the previous digits until we find one that doesnt result to 10 or the index is equal to zero
- If variable temp is odd -> we are not doing anything
- At the end we check if we have something leftover (the carry) from our previous additions. If yes, we save the save the increase in the corresponding digit (we already performed the increase in the while loop and the index is in the correct digit so we only need to save it)

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