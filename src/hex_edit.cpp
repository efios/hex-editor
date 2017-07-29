#include <stdio.h>
#include <fstream>
#include <string>

int ndigits(int number)
{
    int i = 0; 
    for(; number != 0; ++i)
        number = number / 10;

    return i;
}

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
    return hex_number;
}

int main()
{
    const char *input_file_name = "test.txt";

    std::ofstream input_file;
    input_file.open(input_file_name);

    const short buffer_size = 1024;
    char buffer[1024];

    std::string hex_num = to_hex(2555);
    for(int i = 0; i < 4; ++i)
        printf("%c", hex_num[i]);
    
    printf("\n%X\n", 2555);

    return 0;
}