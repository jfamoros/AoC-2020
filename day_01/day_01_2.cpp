#include "../tools.h"
#include <string>

int main(int argc, char *argv[])
{
    vector<string> values;
    parse_file("input1.txt", values);

    int v1, v2, v3;
    for (int i = 0; i < values.size(); ++i)
    {
        for (int j = i; j < values.size(); ++j)
        {
            for (int k = j; k < values.size(); ++k)
            {
                v1 = stoi(values[i]);
                v2 = stoi(values[j]);
                v3 = stoi(values[k]);
                if (v1 + v2 + v3 == 2020)
                {
                    cout << v1 * v2 * v3 << endl;
                }
            }
        }
    }

    return 0;
}
