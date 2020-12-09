#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char *argv[])
{
    fstream in("input.txt", ios::in);

    in.seekg(0, ios::end);
    int size = in.tellg();
    char *input = new char [size + 1];
    in.seekg(0, ios::beg);
    in.read(input, size);
    input[size] = 0;
    in.close();

    char *it = input;
    vector<unsigned long long> numbers;

    while (*it)
    {
        char *n = it;
        while (*it != '\n') ++it;
        *it = '\0';
        numbers.push_back(stoull(n));
        ++it;
    }

    unsigned long long invalid {};

    for (auto i = 25; i < numbers.size(); ++i)
    {
        for (auto j = i-25; j < i; ++j)
        {
            for (auto k = j + 1; k < i; ++k)
            {
                if (numbers[j] + numbers[k] == numbers[i]) goto next; 
            }
        }

        invalid = numbers[i];
        break;
        next: continue;
    }

    unsigned long long sum {};

    for (auto i = 0; i < numbers.size(); ++i)
    {
        sum = numbers[i];
        for (auto j = i + 1; j < numbers.size(); ++j)
        {
            sum += numbers[j];

            if (sum == invalid)
            {
                unsigned long long min {ULLONG_MAX};
                unsigned long long max {};
                for (auto k = i; k <= j; ++k)
                {
                    if (numbers[k] > max) max = numbers[k];
                    if (numbers[k] < min) min = numbers[k];
                }

                cout << min + max << endl;
            }
        }
    }

    sum = 0;
    for (auto i = 394; i <= 410; ++i)
        sum += numbers[i];

    cout << sum << endl;
    
    return 0;
}
