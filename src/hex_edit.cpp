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

    std::string input_file_name = "../test.txt";

    std::ifstream input_file(input_file_name, ios::in|ios::binary|ios::ate);

    if(input_file.is_open())
    {

    }
    char *char_buffer;
      

    input_file.close();

    return 0;
}