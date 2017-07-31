#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>


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
            for(int i = 1; i <= buffer_size; ++i)
            {
                output_file << std::hex << std::setw(2) << std::setfill('0') <<  uint32_t(char_buffer[i]) << ' ';

                if((i % (sizeof(char) << 4)) == 0)
                    output_file << '\n';
            }
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