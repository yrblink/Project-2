//  ifeanyi ugwuoke
//  Project 2
#include <cmath>
#include <iostream>
#include "convert.h"
using namespace std;

int main()
{
    double num, fracPart;
    int intPart;
    Convert conv;

    cout << "Enter a decimal number: ";
    cin >> num;

    intPart = static_cast<int>(num);
    fracPart = num - intPart;

    conv.convertIntPart(intPart);
    conv.convertFracPart(fracPart);

    conv.displayBinary();

    return 0;
}
