#include <iostream>
#include <omp.h>

using namespace std;

void primosParalelo();

int main(int argc, char const *argv[])
{
    primosParalelo();
    return 0;
}

void primosParalelo()
{
    int infinity = 100000000;
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
