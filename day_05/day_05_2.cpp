#include <bits/stdint-uintn.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    fstream in("input.txt", ios::in);

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
        int max_id {};

        bool seats[938] {};

        while (*it)
        {
            uint16_t row {};
            uint8_t col {};

            row = (*it == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            if (*(++it) == 'B') ++row;

            col = (*(++it) == 'R') ? ++col << 1 : col << 1;
            col = (*(++it) == 'R') ? ++col << 1 : col << 1;
            if (*(++it) == 'R') ++col;

            seats[(row << 3) + col] = true;

            it += 2;
        }

        unsigned i = 938;
        while (seats[--i] != false) continue;

        cout << i << endl;
    }

    return 0;
}
