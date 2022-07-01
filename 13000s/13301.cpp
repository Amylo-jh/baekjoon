#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> sqare = {1,1,2,3,5};
    vector <long long> sqare_round = {4,6,10,16,26};

    for(int i = 5; i < 80; i++)
    {
        long long next_sqare = sqare[i-2] + sqare[i-1];
        sqare.push_back(next_sqare);

        long long next_sqare_round = sqare_round[i-1] + 2 * sqare[i];
        sqare_round.push_back(next_sqare_round);
    }

    int query = 0;
    cin >> query;

    cout << sqare_round[query-1];
}