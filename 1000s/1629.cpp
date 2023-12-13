#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    
    vector <long long> arr(64);
    arr[0] = 1;
    arr[1] = a % c;
    for(int i = 2; i < 64; i++)
    {
        arr[i] = arr[i-1] * arr[i-1] % c;
    }

    long long answer = 1;
    int counter = 1;
    while(b)
    {
        if(b & 1)
        {
            answer = answer * arr[counter] % c; 
        }
        counter++;
        b /= 2;
    }

    cout << answer;
}