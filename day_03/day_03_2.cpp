#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

const int len_row {31};
const int x_offset {3}, y_offset {1 * len_row};
const int next_move = x_offset + y_offset;
const int next_warp = next_move - len_row;

int main(int argc, char *argv[])
{
    auto begin = chrono::high_resolution_clock::now();
    ifstream in("input1.txt", ios::in);
    int trees {};

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

        it = input;
        int x {};

        while (*it)
        {
            if (*it == '#') ++trees;
            x += x_offset;

            if (x >= len_row)
            {
                x %= len_row;
                it += next_warp;
            }
            else
            {
                it += next_move;
            }
        }
    }
    else
    {
        cout << "I/O Error: couldnt open file" << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
    cout << duration / 1000000.0 << " milliseconds" << endl;

    cout << trees << endl;

    return 0;
}
