#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector <int> sequence;
    list <int> actual_sequence;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sequence.push_back(temp);
    }

    for(int i = n-1; i >= 0; i--)
    {
        auto iter = actual_sequence.begin();
        std::advance(iter, sequence[i]);
        actual_sequence.insert(iter, i+1);
    }

    for(auto i : actual_sequence)
    {
        cout << i << " ";
    }
}