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
    int infinity = 1000;
    bool flag = false;
    int qntd = 0;

    for(int i = 1; i < infinity; i++)
    {
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            cout << " " << i;
	    qntd++;
        }
        flag = false;
    }
    cout << endl << qntd << endl;
}
