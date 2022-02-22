#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int num;
    int temp;
    int array[8001] = {};
    // array[4000]에 있는 값은 0이 입력된 횟수를 의미함, +4000되어 입력됨.
    // array[0] ~ array[4000] = -4000 ~ 0, array[4001] ~ array[8001] = 1 ~ 4000

    int total = 0;
    int middle = 0;
    double avg = 0;
    int most_frequent = 0;
    int range = 0;

    vector <int> nums;

    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        nums.push_back(temp);
        array[temp+4000]++;
        total = total + temp;
    }

    sort(nums.begin(), nums.end());
    
    avg = double(total) / double(num);
    avg = round(avg);
    middle = nums[num/2];

    bool flag = true;
    int savepoint = 0;
    for(int i = 0; i <= 8000; i++)
    {
        if(array[i] > most_frequent)
        {
            most_frequent = array[i];
            savepoint = i;
            flag = true;
        }
        else if(array[i] == most_frequent && flag)
        {
            most_frequent = array[i];
            savepoint = i;
            flag = false;
        }
    }
    most_frequent = savepoint - 4000;

    if(num == 1)
    {
        range = 0;
    }
    else
    {
        range = nums[num-1] - nums[0];
    }

    if(avg == -0)
    {
        avg = 0;
    }

    cout << avg << endl;
    cout << middle << endl;
    cout << most_frequent << endl;
    cout << range << endl;
}