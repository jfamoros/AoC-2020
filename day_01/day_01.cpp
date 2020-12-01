#include "../tools.h"
#include <string>

int main(int argc, char *argv[])
{
    vector<string> values;
    parse_file("input1.txt", values);

    int v1, v2;
    for (int i = 0; i < values.size(); ++i)
    {
        for (int j = i; j < values.size(); ++j)
        {
            v1 = stoi(values[i]);
            v2 = stoi(values[j]);
            if (v1 + v2 == 2020)
            {
                cout << v1 * v2 << endl;
            }
        }
    }

    return 0;
}
