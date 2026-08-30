#include "subtract.h"
#include "add.h"

using namespace std;

string subtract(const string& str1, const string& str2)
{
    string negativeStr2;

    if (str2[0] == '-')
        negativeStr2 = str2.substr(1);
    else
        negativeStr2 = "-" + str2;

    return add(str1, negativeStr2);
}