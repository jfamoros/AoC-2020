#include "tools.h"
#include <string>

// Parses the file and returns a vector with the line separated values
void parse_file(const string &filename, vector<string>& values)
{
    ifstream in(filename, ios::in);

    if (in)
    {
        in.seekg(0, ios::end);
        int size = in.tellg();
        char *input = new char [size + 1];
        in.seekg(0, ios::beg);
        in.read(input, size);
        input[size] = 0;
        in.close();
        
        char *it = input;

        while (*it)
        {
            char *v_start = it;
            while (*it != '\n')
            {
                ++it;
            }
            *it = '\0';
            values.push_back(v_start);

            ++it;
        }
    }
    else
    {
        cout << "IO Error" << endl;
    }
}

// Parses the file and returns a vector with the values parsed to integer
void parse_file_int(const string &filename, vector<int>& values)
{
    ifstream in(filename, ios::in);

    if (in)
    {
        in.seekg(0, ios::end);
        int size = in.tellg();
        char *input = new char [size + 1];
        in.seekg(0, ios::beg);
        in.read(input, size);
        input[size] = 0;
        in.close();
        
        char *it = input;

        while (*it)
        {
            char *v_start = it;
            while (*it != '\n')
            {
                ++it;
            }
            *it = '\0';
            values.push_back(stoi(v_start));

            ++it;
        }
    }
    else
    {
        cout << "IO Error" << endl;
    }
}
