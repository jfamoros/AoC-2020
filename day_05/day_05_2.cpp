#include <bits/stdint-uintn.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdint>
#include <algorithm>
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
        int max_id {};

        bool seats[259982] {};

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

            seats[(row << 5) + col] = true;

            it += 2;
        }

        unsigned i = 225998;
        while (seats[--i] != false) continue;

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
        cout << duration / 1000000.0 << " milliseconds" << endl;

        cout << i << endl;
    }

    return 0;
}
