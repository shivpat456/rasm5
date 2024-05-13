#include <iostream>
using namespace std;

void BubbleSort (long long int a[], int length)
{
	int i, j;
    long long int temp;
	
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}