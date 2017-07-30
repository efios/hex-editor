#include <string>
#include <fstream>
#include <iostream>

#include <stdio.h> /* Used for printing hex values */



int main()
{
    std::streampos buffer_size = 0;
    char *char_buffer = nullptr;

    std::string input_file_name = "";
    printf("Enter the name of the file you want to read from\n");
    std::cin >> input_file_name;

    std::ifstream input_file(input_file_name, std::ios::in|std::ios::binary|std::ios::ate);

    if(input_file.is_open())
    {
        buffer_size = input_file.tellg(); /* Get the file length */
        char_buffer = new char[buffer_size];

        input_file.seekg(0, ios::beg); /* Set position to beginning of file. */
        input_file.read(char_buffer, buffer_size); /* Read contents of input_file into char_buffer */
        input_file.close();


        printf("Enter the name of the file you'd like to write to\n");
        std::string output_file_name = "";
        std::cin >> output_file_name;

        std::ofstream output_file(output_file_name);

        if(output_file.is_open())
        {
            output_file.write(char_buffer, buffer_size);

            output_file.close();
        }

        delete[] char_buffer;
    }
    else
    {
        std::cout << "couldn't open file\n";
    }

    return 0;
}