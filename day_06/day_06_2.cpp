#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    auto begin = chrono::high_resolution_clock::now();
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
        int total {};

        while (*it)
        {
            unsigned answers['z'+1] {};
            unsigned n {};

            while (*it != '\n')
            {
                while (*it != '\n')
                {
                    ++answers[*it];
                    ++it;
                }
                
                ++it;
                ++n;
            }

            ++it;

            for (auto i = 'a'; i <= 'z'; ++i)
                total += (answers[i] == n);
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
        cout << duration / 1000000.0 << " milliseconds" << endl;

        cout << total << endl;
    }
  
    return 0;
}
