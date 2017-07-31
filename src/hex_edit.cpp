#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

typedef unsigned int uint32_t;

void write_to_file(std::ofstream &output_file, char *char_buffer, int buffer_size);

int main()
{

    std::streampos buffer_size = 0;
    char *char_buffer = nullptr;
       
    std::cout << "Enter the name of the file you want to read from:\n";
    std::string input_file_name = "";
    std::cin >> input_file_name;

    /* Open input_file with the flags (input, binary and "at end") */
    std::ifstream input_file(input_file_name, std::ios::in|std::ios::binary|std::ios::ate);

    if(input_file.is_open())
    {
        buffer_size = input_file.tellg(); /* Get the file length */
        char_buffer = new char[buffer_size];

        input_file.seekg(0, std::ios::beg); /* Set position to beginning of file. */
        input_file.read(char_buffer, buffer_size); /* Read contents of input_file into char_buffer */
        input_file.close();

        std::cout << "Enter the name of the file you'd like to write to:\n";
        std::string output_file_name = "";
        std::cin >> output_file_name;

        std::ofstream output_file(output_file_name);

        if(output_file.is_open())
        {   
            write_to_file(output_file, char_buffer, buffer_size);
           
            output_file.close();
        }
    
        delete[] char_buffer;
        char_buffer = nullptr;
    }
    else
    {
        std::cout << "The file probably doesn't exist\n";
    }

    return 0;
}


void write_to_file(std::ofstream &output_file, char *char_buffer, int buffer_size)
{
    constexpr int end_line = sizeof(char) << 4; /* \n every 16 characters */

    /* We assume the file was "opened" succesfully */    
    for(int i = 1; i < buffer_size; ++i)
    {
        output_file << std::hex << std::setw(2) << char_buffer[i] << ' ';

        if(i % end_line == 0)
            output_file << '\n';
    }
}