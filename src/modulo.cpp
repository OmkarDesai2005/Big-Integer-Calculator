#include "modulo.h"
#include <algorithm>

using namespace std;

string removeLeadingZeros(string s)
{
    int i = 0;

    while (i < s.size() - 1 && s[i] == '0')
        i++;

    return s.substr(i);
}

int compareNumbers(string a, string b)
{
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);

    if (a.size() != b.size())
        return a.size() > b.size() ? 1 : -1;

    if (a == b)
        return 0;

    return a > b ? 1 : -1;
}

string subtractPositive(string a, string b)
{
    string result = "";

    int i = a.size() - 1;
    int j = b.size() - 1;

    int borrow = 0;

    while (i >= 0)
    {
        int temp = (a[i] - '0') - borrow;

        if (j >= 0)
            temp -= b[j] - '0';

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
        j--;
    }

    reverse(result.begin(), result.end());

    return removeLeadingZeros(result);
}

string multiplyByDigit(string num, int digit)
{
    string result = "";
    int carry = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        int temp = (num[i] - '0') * digit + carry;

        result += char((temp % 10) + '0');

        carry = temp / 10;
    }

    if (carry)
        result += char(carry + '0');

    reverse(result.begin(), result.end());

    return removeLeadingZeros(result);
}

string modulo(const string& str1, const string& str2)
{
    if (str2 == "0" || str2 == "-0")
        return "Error: Division by zero";

    bool neg1 = str1[0] == '-';

    string dividend = neg1 ? str1.substr(1) : str1;
    string divisor = str2[0] == '-' ? str2.substr(1) : str2;

    dividend = removeLeadingZeros(dividend);
    divisor = removeLeadingZeros(divisor);

    string current = "";

    for (int i = 0; i < dividend.size(); i++)
    {
        current += dividend[i];

        current = removeLeadingZeros(current);

        int lo = 0;
        int hi = 9;
        int best = 0;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            string product = multiplyByDigit(divisor, mid);

            if (compareNumbers(product, current) <= 0)
            {
                best = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        string product = multiplyByDigit(divisor, best);

        current = subtractPositive(current, product);
    }

    current = removeLeadingZeros(current);

    // C++ style: sign of remainder follows dividend
    if (neg1 && current != "0")
        current = "-" + current;

    return current;
}