#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

    typedef pair<pair<string, int>, bool> test;
    vector<test> code;

    char *it = input; 
    char *op = it; 
    char sign; 

    int acc {};

    while (*it)
    {
        op = it;
        it += 3;
        *it = '\0';

        char *arg = ++it;
        while (*it != '\n') ++it;

        *it = '\0';

        ++it;

        code.push_back(test(pair<string,int>(op,stoi(arg)), false));
    }

    unsigned pc {};
    int corrupted { -1 };

    for (auto i = 0; i < code.size(); ++i)
    {
        cout << "i: " << i << endl;

        if (code[i].first.first == "jmp")
        {
            code[i].first.first = "nop";
        }
        else if (code[i].first.first == "nop")
        {
            code[i].first.first = "jmp";
        }

        pc = 0;
        acc = 0;

        while(true)
        {
            if (code[pc].second == true) break;
            code[pc].second = true;

            switch (code[pc].first.first[0])
            {
                case 'a':
                    acc += code[pc].first.second;
                    ++pc;
                    break;

                case 'j':
                    pc += code[pc].first.second;
                    break;

                default:
                    ++pc;
                    break;
            }

            if (pc >= code.size()) {
                cout << acc << endl;
                return 0;
            }
        }

        for (auto& v : code)
        {
            v.second = false;
        }

        if (code[i].first.first == "jmp")
        {
            code[i].first.first = "nop";
        }
        else if (code[i].first.first == "nop")
        {
            code[i].first.first = "jmp";
        }
    }

    return 0;
}
