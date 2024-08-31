#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lnthOfIncrs;


vector<int> L;
vector<int> L_id;

void construct(const vector<int>& numbers)
{
    L.clear();
    lnthOfIncrs = 0;

    for (int i = 0; i < numbers.size(); ++i)
    {
        const int num = numbers[i];


        int pos = upper_bound(L.begin(), L.end(), num) - L.begin();
        if (pos == L.size())
        {
            L.push_back(num);
        }
        else
        {
            L[pos] = num;
        }


        if (pos + 1 >= lnthOfIncrs) {
            lnthOfIncrs = pos + 1;
        }
    }
}

int main()
{
    vector<int> numbers;
    int T = 1;

    int num;

    string sep = "";

    while (cin >> num, num != -1)
    {
        numbers.clear();
        numbers.push_back(num);

        while (cin >> num, num != -1)
            numbers.push_back(num);

        reverse(numbers.begin(), numbers.end());
        construct(numbers);

        cout << sep << "Test #" << T++ << ":\n  maximum possible interceptions: " << lnthOfIncrs << '\n';
        sep = "\n";
    }
}

