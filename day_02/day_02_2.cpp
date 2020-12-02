#include <iostream>
#include "tools.h"

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
        int valid_counter {};
        char target {}; 

        while (*it)
        {
            int l {}, h {};
            char *v_start = it;
            while (*it != '-')
            {
                ++it;
            }
            *it = '\0';
            l = stoi(v_start) - 1;

            ++it;
            v_start = it;

            while (*it != ' ')
            {
                ++it;
            }
            *it = '\0';
            h = stoi(v_start) - 1;

            // next character is our target
            target = *(it + 1);

            //advance to first character of the password
            it += 4;
            v_start = it;

            while (*it != '\n')
            {
                ++it;
            }
            *it = '\0';

            if (!(*(v_start + l) == target) != !(*(v_start + h) == target)) ++valid_counter;
            ++it;
        }

        cout << valid_counter << endl; 
    }
    else
    {
        cout << "IO Error" << endl;
    }

    return 0;
}
