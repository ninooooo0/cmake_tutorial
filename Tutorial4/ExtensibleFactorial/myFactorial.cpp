#include <iostream>
using namespace std;
void myFactorial(int fact)
{
    int temp[10000] = {0};
    int dig = 9999;
    temp[0] = 1;
    for (int k = 1; k <= fact; k++)
    {
        for (int i = 0; i < dig; i++)
            temp[i] = temp[i] * k;

        for (int j = 0; j < dig; j++)
        {
            temp[j + 1] += temp[j] / 10;
            temp[j] = temp[j] % 10;
        }
    }
    bool flag = false;
    for (int i = dig; i >= 0; i--)
        if (temp[i] != 0 || flag)
        {
            cout << temp[i];
            flag = true;
        }
    cout << endl;
}