#include <iostream>
#include <fstream>


int ndigits(int value)
{
    int i, temp;
    temp = value;
    for(i = 0; temp > 0; ++i)
        temp = temp / 10;

    return i;
}

int digit_at(int index, int value)
{
    int i, temp;
    temp = value;
    if(ndigits(value) >= index)
    {
        for(i = 0; i < index; ++i)
        {
            
        }
    }

}

int to_hex(int decimal_value)
{
    for(int i = 0; i < ndigits(decimal_value); ++i)
    {

    }

    return 0;
}

int main()
{
    const char *input_file_name = "test.txt";

    std::ofstream input_file;
    input_file.open(input_file_name);

    const short buffer_size = 1024;
    char buffer[1024];
    
    int n = 1;
    for(int i = 0; i < 10; ++i)
    {
        std::cout << "n" << i << " = " << n << '\n';
        n = n << 4; 
    }

    return 0;
}