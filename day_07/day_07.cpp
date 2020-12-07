#include <cctype>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

unordered_map<string, vector<pair<string, int>>> rules;

bool can_hold(const string& bag)
{
    for (auto& b : rules[bag])
    {
        if (b.first == "shiny gold") return true;
        if (can_hold(b.first)) return true;
    }

    return false;
}

int n_bags(const string& bag)
{
    int total {};
    for (const auto& b : rules[bag])
    {
        total += b.second + (b.second*n_bags(b.first));
    }

    return total;
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
    
        while (*it)
        {
            char *main_bag = it;
            char *n;
            char *inner_bag;
            int nbags {};
            
            while (*it != ' ') ++it;
            ++it;
            while (*it != ' ') ++it;

            *it = '\0';
            it += 12;

            if (isdigit(*(it + 2)))
            {
                vector<pair<string,int>> contained {};

                do
                {
                    it += 2;
                    n = it;
                    while (*it != ' ') ++it;

                    *it = '\0';
                    ++it;
                    nbags = stoi(n);

                    inner_bag = it;
                    while (*it != ' ') ++it;
                    ++it;
                    while (*it != ' ') ++it;

                    *it = '\0';
                    it += (nbags == 1) ? 4 : 5;

                    contained.push_back(pair<string,int>(inner_bag, nbags));
                } while (*it != '.');

                rules[main_bag] = contained;
                it += 2;
            }
            else
            {
                it += 17;

                rules[main_bag] = vector<pair<string, int>>();
            }
        }
        
        int total {};
        for (const auto& r : rules)
        {
            total += can_hold(r.first);
        }

        cout << total << endl;

        cout << n_bags("shiny gold") << endl;

    }

    return 0;
}
