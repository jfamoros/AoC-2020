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

        cout << op << " " << arg << endl;

        ++it;

        code.push_back(test(pair<string,int>(op,stoi(arg)), false));
    }

    unsigned pc {};

    while(!code[pc].second)
    {
        cout << acc << endl;
        code[pc].second = true;

        switch (code[pc].first.first[0])
        {
            case 'a':
                cout << "add " << code[pc].first.second << endl;
                acc += code[pc].first.second;
                ++pc;
                break;

            case 'j':
                cout << "jmp " << code[pc].first.second << endl;
                pc += code[pc].first.second;
                break;

            default:
                ++pc;
        }
    }

    cout << acc << endl;

    return 0;
}
