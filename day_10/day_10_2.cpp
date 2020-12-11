#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

vector<int> ratings = { 0 };
vector<long> solutions(117);

long combinations(int x)
{
    if (x > ratings.size() - 2) return solutions[x] = 1;

    if ((ratings[x] - ratings[x+1] == -3) || ratings[x] - ratings[x+1] == -1 && ratings[x] - ratings[x+2] != -2)
        return (solutions[x+1] = (solutions[x+1] != 0) ? solutions[x+1] : combinations(x+1));
    if (ratings[x] - ratings[x+1] == -1 && ratings[x] - ratings[x+2] == -2 && ratings[x] - ratings[x+3] != -3) 
        return (solutions[x+1] = (solutions[x+1] != 0) ? solutions[x+1] : combinations(x+1))
             + (solutions[x+2] = (solutions[x+2] != 0) ? solutions[x+2] : combinations(x+2));
    if (ratings[x] - ratings[x+1] == -1 && ratings[x] - ratings[x+2] == -2 && ratings[x] - ratings[x+3] == -3) 
        return (solutions[x+1] = (solutions[x+1] != 0) ? solutions[x+1] : combinations(x+1))
             + (solutions[x+2] = (solutions[x+2] != 0) ? solutions[x+2] : combinations(x+2))
             + (solutions[x+3] = (solutions[x+3] != 0) ? solutions[x+3] : combinations(x+3));

    return 69;
}

int main(int argc, char *argv[])
{
    auto begin = chrono::high_resolution_clock::now();
    fstream in("input.txt", ios::in);

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
        char *rating = it;
        while (*it != '\n') ++it;

        ratings.push_back(stoi(rating));
        ++it;
    }

    sort(ratings.begin(),ratings.end());
    ratings.push_back(ratings[ratings.size()-1] + 3);

    cout << combinations(0) << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
    cout << duration / 1000000.0 << " milliseconds" << endl;

    return 0;
}
