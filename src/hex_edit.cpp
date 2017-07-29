#include <iostream>
#include <fstream>

int to_hex()
{

    return 0;
}

int ndigits(const int value)
{
    int i, temp;
    temp = value;
    for(i = 0; temp > 0; ++i)
        temp = temp / 10;

    return i;
}

int main()
{
    std::ofstream temp_name;
    const short buffer_size = 1024;
    char buffer[1024];


    return 0;
}