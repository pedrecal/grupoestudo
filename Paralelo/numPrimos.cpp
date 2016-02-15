// icpc numPrimos.cpp -o -lm numPrimos.o
#include <iostream>
#include <math.h>

using namespace std;

void numerosPrimos();

void numerosPrimos2();

int main(int argc, char const *argv[]) {

    numerosPrimos();

    return 0;
}

void numerosPrimos()
{
    int max = 100;
    bool flag = true;

    for(int i = 1; i < max; i++)
    {
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = false;
                break;
            }
        }

        if(flag)
            cout << " " << i;

        flag = true;
    }
    cout << endl;
}
