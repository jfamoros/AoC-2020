#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("input1.txt", ios::in);

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

        int len_row {31};

        it = input;
        int trees {};
        int x_offset {3}, y_offset {1 * len_row};
        int x {};

        while (*it)
        {
            if (*it == '#') ++trees;
            *it = 'O';

            x += x_offset;

            if (x >= len_row)
            {
                x = x % len_row;
                it += x_offset + y_offset - len_row;
            }
            else
            {
                it += y_offset + x_offset;
            }
        }
        
        cout << trees << endl;
    }
    else
    {
        cout << "I/O Error: couldnt open file" << endl;
    }


  return 0;
}
