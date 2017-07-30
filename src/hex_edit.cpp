#include <array>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

int ndigits(int number)
{
    int i = 0; 
    for(; number > 0; ++i)
        number = number / 10;

    return i;
}


int main()
{
    using namespace std;

    std::streampos buffer_size = 0;
    char *char_buffer = nullptr;

    std::string input_file_name = "test.txt";
    std::ifstream input_file(input_file_name, ios::in|ios::binary|ios::ate);

    if(input_file.is_open())
    {
        buffer_size = input_file.tellg();
        char_buffer = new char[buffer_size];

        input_file.seekg(0, ios::beg); /* Set position to beginning of file. */
        input_file.read(char_buffer, buffer_size);

        input_file.close();
        delete[] char_buffer;
    }
    else
    {
        std::cout << "couldn't open file\n";
    }

    return 0;
}