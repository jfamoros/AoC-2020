#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
    vector<int> ratings = { 0 };

    while (*it)
    {
        char *rating = it;
        while (*it != '\n') ++it;

        ratings.push_back(stoi(rating));

        ++it;
    }

    sort(ratings.begin(),ratings.end());
    ratings.push_back(ratings[ratings.size()-1] + 3);

    int diff3 {}, diff1 {};

    for (auto i = 1; i < ratings.size(); ++i)
    {
        if (ratings[i] - ratings[i-1] == 3) 
            ++diff3;
        else if (ratings[i] - ratings[i-1] == 1)
            ++diff1;
    }

    cout << diff3 * diff1 << endl;

    return 0;
}
