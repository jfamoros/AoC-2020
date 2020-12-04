#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

const regex birth("byr:(19[2-9][0-9]|200[0-2])");
const regex issue("iyr:(201[0-9]|2020)");
const regex expiration("eyr:(202[0-9]|2030)");
const regex height("hgt:((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)");
const regex hair("hcl:#(\\d|[a-f]){6}");
const regex eye("ecl:(amb|blu|brn|gry|grn|hzl|oth)");
const regex pid("pid:[0-9]{9}");

bool is_valid(string &passport)
{
    if (!regex_search(passport, birth)) return false;
    if (!regex_search(passport, issue)) return false;
    if (!regex_search(passport, expiration)) return false;
    if (!regex_search(passport, height)) return false;
    if (!regex_search(passport, hair)) return false;
    if (!regex_search(passport, eye)) return false;
    if (!regex_search(passport, pid)) return false;
       
    return true;
}

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
        char *passport = input;
        vector<string> passports;
        passports.reserve(size);

        while (*it)
        {
            if (*it == '\n' && *(it + 1) == '\n')
            {
                it++;
                *it = '\0';

                passports.push_back(passport);
                it++;
                passport = it;

                continue;
            }

            it++;
        }

        int valid {};
        for (auto p : passports)
        {
            if (is_valid(p)) ++valid;
        }

        delete [] input;

        cout << valid << endl;
    }
    else
    {
        cout << "I/O Error: cannot open input file." << endl;
    }

    return 0;
}
