// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> myvec;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        myvec.push_back(p);
    }
    unordered_map<int, vector<int>> mpp;
    int i = 0;
    int s;
    cout << "enter numebr of relations: ";
    cin >> s;
    while (i < s)
    {
        int p, q;
        cin >> p >> q;
        mpp[p].push_back(q);

        i++;
    }

    int target = 1;
    for (auto e : mpp)
    {
        if (e.first == target)
        {
            vector<int> vec = e.second;

            set<int> mySet(vec.begin(), vec.end());
            for (auto s : myvec)
            {
                if (mySet.find(s) == mySet.end() && target != s)
                {
                    cout << s << " ";
                }
            }
        }
    }
}