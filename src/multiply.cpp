#include "multiply.h"
#include <vector>
#include <algorithm>

using namespace std;

string multiply(const string& str1, const string& str2)
{
    bool neg1 = str1[0] == '-';
    bool neg2 = str2[0] == '-';

    string a = neg1 ? str1.substr(1) : str1;
    string b = neg2 ? str2.substr(1) : str2;

    if (a == "0" || b == "0")
        return "0";

    int n = a.size();
    int m = b.size();

    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int product = (a[i] - '0') * (b[j] - '0');

            int p1 = i + j;
            int p2 = i + j + 1;

            int temp = product + result[p2];

            result[p2] = temp % 10;
            result[p1] += temp / 10;
        }
    }

    string ans = "";

    for (int x : result)
    {
        if (ans.empty() && x == 0)
            continue;

        ans += char(x + '0');
    }

    if (neg1 != neg2)
        ans = "-" + ans;

    return ans;
}