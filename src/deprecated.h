/* Decimal to hex (0 - FF) */
std::string to_hex(int decimal_number)
{
    std::string hex_number("", ndigits(decimal_number));

    int remainder = 0;
    int quotient = decimal_number;
    int i = 0;

    while(quotient != 0)
    {
        remainder = quotient % 16;

        if(remainder < 10)
            hex_number[i] = remainder + 48;
        else
            hex_number[i] = remainder + 55;

        ++i;
        quotient = quotient / 16;    
    }

    hex_number[i] = '\0';
    std::reverse(hex_number.begin(), hex_number.end());

    return hex_number;
}

int ndigits(int number)
{
    int i = 0; 
    for(; number > 0; ++i)
        number = number / 10;

    return i;
}
