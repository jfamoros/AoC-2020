#include <bits/stdint-uintn.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdint>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    auto begin = chrono::high_resolution_clock::now();
    fstream in("bigboy.txt", ios::in);

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
        uint32_t max_id {};

        while (*it)
        {
            uint32_t row {};
            uint8_t col {};

            row = (*it == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            row = (*(++it) == 'B') ? ++row << 1 : row << 1;
            if (*(++it) == 'B') ++row;

            col = (*(++it) == 'R') ? ++col << 1 : col << 1;
            col = (*(++it) == 'R') ? ++col << 1 : col << 1;
            col = (*(++it) == 'R') ? ++col << 1 : col << 1;
            col = (*(++it) == 'R') ? ++col << 1 : col << 1;
            if (*(++it) == 'R') ++col;

            uint32_t id = (row << 5) + col;
            if (id > max_id) max_id = id;

            it += 2;
        }

        cout << max_id << endl;
    }

  return 0;
}
