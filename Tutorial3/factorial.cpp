#include <iostream>
#include <cstdlib>
#include "factorialConfig.h"

#ifdef USE_MYFACTORIAL
    #include "myFactorial.h"
#endif

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << argv[0] << " Version " << Factorial_VERSION_MAJOR << "."
            << Factorial_VERSION_MINOR << std::endl;
        cout << "Usage: \n      factorial <integer1> [integer2] ..." << endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {   
        int temp = atoi(argv[i]);
        if (temp < 0)
        {
            cout << "Integer " << temp << " is negative, no factorial!" << endl;
            break;
        }
#ifdef USE_MYFACTORIAL
        if (temp > 3248)
#else 
        if (temp > 20)
#endif
        {
            cout << "Integer " << temp << " is too large, no way to calculate!" << endl;
            break;
        }

        cout << "The factorial of " << temp << " is ";
        
#ifdef USE_MYFACTORIAL
        myFactorial(temp);
#else
        unsigned long long fact = 1;
        while (temp != 0)
        {
            fact *= temp;
            --temp;
        }
        cout << fact << "!" << endl;
#endif
    }

    return 0;
}