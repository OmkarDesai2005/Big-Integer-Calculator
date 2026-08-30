#include "add.h"
#include <algorithm>

using namespace std;

string add(const string& str1, const string& str2)
{
    bool neg1 = str1[0] == '-';
    bool neg2 = str2[0] == '-';

    string a = neg1 ? str1.substr(1) : str1;
    string b = neg2 ? str2.substr(1) : str2;

    // Same signs -> addition
    if (neg1 == neg2)
    {
        string result = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry)
        {
            int temp = carry;

            if (i >= 0)
                temp += a[i--] - '0';

            if (j >= 0)
                temp += b[j--] - '0';

            result += char(temp % 10 + '0');
            carry = temp / 10;
        }

        reverse(result.begin(), result.end());

        if (neg1 && result != "0")
            result = "-" + result;

        return result;
    }

    // Different signs -> subtraction

    while (a.size() > 1 && a[0] == '0')
        a.erase(0, 1);

    while (b.size() > 1 && b[0] == '0')
        b.erase(0, 1);

    string bigger, smaller;
    bool negative;

    if (a.size() > b.size() || (a.size() == b.size() && a > b))
    {
        bigger = a;
        smaller = b;
        negative = neg1;
    }
    else
    {
        bigger = b;
        smaller = a;
        negative = neg2;
    }

    string result = "";

    int i = bigger.size() - 1;
    int j = smaller.size() - 1;
    int borrow = 0;

    while (i >= 0)
    {
        int temp = bigger[i] - '0' - borrow;

        if (j >= 0)
            temp -= smaller[j--] - '0';

        if (temp < 0)
        {
            temp += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result += char(temp + '0');
        i--;
    }

    reverse(result.begin(), result.end());

    int pos = 0;

    while (pos < result.size() - 1 && result[pos] == '0')
        pos++;

    result = result.substr(pos);

    if (result == "0")
        return "0";

    if (negative)
        result = "-" + result;

    return result;
}
