#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "ncurses.h"

#define UNSIGNED_TYPES
#include "types.h"

void write_to_file(std::ofstream &output_file, char *char_buffer, int buffer_size);
void read_file(std::ifstream &input_file, char *char_buffer, int buffer_size);


int main()
{
    initscr(); /* Initalize ncurses */
    raw(); /* No signal from special characters/combinations */
    noecho(); /* Turn of echoing */
    keypad(stdscr, TRUE); /* Enable arrow keys and such */
   
    int rows, columns;
    getmaxyx(stdscr, rows, columns);
      
    mvprintw(rows/2, (columns-55)/2, "Please enter the name of the file you want to read from:\n");
    refresh();
    
    echo(); /* Enable echoing for file name */
    char input_file_name[55];
    getstr(input_file_name);
    
    noecho(); /* Disable again. */

    /* Open input_file with the flags (input, binary and at end) */
    std::ifstream input_file(input_file_name, std::ios::in | std::ios::binary | std::ios::ate);
    std::streampos buffer_size = 0;
    char *char_buffer = nullptr;

    if(input_file.is_open())
    {
        printw("inside input_file\n");
        refresh();

        buffer_size = input_file.tellg(); /* Get the file length */
        char_buffer = new char[buffer_size];
        
        read_file(input_file, char_buffer, buffer_size);
        input_file.close();

        /*
        std::cout << "Enter the name of the file you'd like to write to:\n";
        std::string output_file_name = "";
        std::cin >> output_file_name;

        std::ofstream output_file(output_file_name);

        if(output_file.is_open())
        {   
            write_to_file(output_file, char_buffer, buffer_size);
           
            output_file.close();
        }
        */

        for(int i = 1; i-1 < buffer_size; ++i)
        {
            printw("%X ", char_buffer[i]);
            if(i % 16 == 0)
                printw("\n");
        }

        refresh();
        getch();

        delete[] char_buffer;
        char_buffer = nullptr;

        endwin();
    }
    else
    {
        printw("The file probably doesn't exist\n");
        endwin();
    }
    
    return 0;
}


void write_to_file(std::ofstream &output_file, char *char_buffer, int buffer_size)
{
    constexpr int end_line = sizeof(char) << 4; /* \n every 16 characters */

    /* We assume the file was "opened" succesfully */    
    for(int i = 1; i < buffer_size; ++i)
    {
        output_file << std::hex << std::setw(2) << uint32_t(char_buffer[i]) << ' ';

        if(i % end_line == 0)
            output_file << '\n';
    }
}

/* Read contents of file into char buffer */
void read_file(std::ifstream &input_file, char *char_buffer, int buffer_size)
{
    input_file.seekg(0, std::ios::beg); /* Move to beginning of file */
    input_file.read(char_buffer, buffer_size);
}
