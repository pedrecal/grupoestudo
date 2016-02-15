// icpc numPrimos.cpp -o -lm numPrimos.o
#include <iostream>
#include <math.h>

using namespace std;

void numerosPrimos();

void numerosPrimos2();

int main(int argc, char const *argv[]) {

    numerosPrimos();
    cout << endl;
    //numerosPrimos2();

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
        {
            cout << " " << i;
            flag = true;
        }
    }
    cout << endl;
}

void numerosPrimos2()
{
    int infinity = 100;
    int flag = 0;

    for(int i = 1; i < infinity; i++)
    {
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            cout << " " << i;
        }
        flag = 0;
    }
    cout << endl;
}
