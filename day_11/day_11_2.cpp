#include <iostream>
#include <fstream>
#include <vector>

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
    vector<vector<char>> seats;
    unsigned i {}, n {};

    while (*it != '\n') ++it;
    n = it - input;

    seats.push_back(vector<char>());
    for (auto i = 0; i < n+2; ++i) seats.back().push_back('0');

    it = input;

    while (*it)
    {
        unsigned j {};
        seats.push_back(vector<char>());

        seats.back().push_back('0');
        while (*it != '\n') seats.back().push_back(*(it++));
        seats.back().push_back('0');

        ++it;
    }

    seats.push_back(vector<char>());
    for (auto i = 0; i < n+2; ++i) seats.back().push_back('0');

    vector<vector<char>> dbuffer(seats);

    vector<vector<char>>* s1 = &seats;
    vector<vector<char>>* s2 = &dbuffer;
    vector<vector<char>>* aux = &dbuffer;
    vector<pair<int,int>> neighbours {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    unsigned changes {};

    auto find_seat = [](int ix, int iy, pair<int,int> dir, vector<vector<char>>* s)
    {
        do
        {
            iy += dir.second;
            ix += dir.first;

            if (s->at(ix)[iy] == '0') return false;
            if (s->at(ix)[iy] == 'L') return false;
            if (s->at(ix)[iy] == '#') return true;
        } while (true);
    };

    do
    {
        changes = 0;
        for (auto x = 1; x < seats.size()-1; ++x)
        {
            for (auto y = 1; y <= n ; ++y)
            {
                int adjacents {};
                for (auto neighbour : neighbours)
                    if (find_seat(x, y, neighbour, s1)) ++adjacents;

                if (s1->at(x)[y] == 'L' && adjacents == 0) { s2->at(x)[y] = '#'; ++changes; }
                if (s1->at(x)[y] == '#' && adjacents >= 5) { s2->at(x)[y] = 'L'; ++changes; }
            }
        }

        *s1 = *s2;

        aux = s2; 
        s2 = s1;
        s1 = aux;

    }while (changes != 0);


    unsigned occupied {};
    for (auto x = 0; x < s1->size(); ++x){
        for (auto y : s1->at(x))
            if (y == '#') ++occupied;
    }

    cout << occupied << endl;

    return 0;
}
