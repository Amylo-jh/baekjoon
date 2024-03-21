#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    long long n, t;
    cin >> n >> t;

    vector <string> tier_name(t);
    vector <long long> tier(t);

    long long total_user = 0;
    for(long long i = 0; i < t; i++)
    {
        string tiername;
        string quarter;
        cin >> tiername >> quarter;

        tier_name[i] = tiername;
        if(quarter.find("%") != string::npos)
        {
            long long curr_user_pool = (n - total_user) * stoi(quarter) / 100;
            total_user += curr_user_pool;
            tier[i] = curr_user_pool;
        }
        else
        {
            tier[i] = stoi(quarter);
            total_user += stoi(quarter);
        }
    }

    if(total_user < n)
    {
        cout << "Invalid System";
        return 0;
    }

    total_user = n;

    for(int i = 0; i < t; i++)
    {
        if(total_user >= tier[i])
        {
            total_user -= tier[i];
        }
        else
        {
            tier[i] = max(total_user, (long long)0);
            total_user = 0;
        }
    }

    string raw_friend_tier;
    string friend_tier;
    long long detail_friend_tier = 0;
    cin >> raw_friend_tier;

    friend_tier = raw_friend_tier;
    if('1' <= friend_tier[friend_tier.length()-1] && friend_tier[friend_tier.length()-1] <= '4')
    {
        detail_friend_tier = stoi(friend_tier.substr(friend_tier.length()-1, 1));
        friend_tier = raw_friend_tier.substr(0, raw_friend_tier.length()-1);
    }
    vector <long long> detail_tier(4);

    long long index = -1;
    for(long long i = 0; i < t; i++)
    {
        if(friend_tier == tier_name[i])
        {
            index = i;
            break;
        }
    }

    if(index < 0 || detail_friend_tier > 4)
    {
        cout << "Liar";
        return 0;
    }

    if(detail_friend_tier)
    {
        long long detail_tier_quarter = tier[index] / 4 + 1;
        if(tier[index] % 4 == 0)
        {
            detail_tier_quarter--;
        }

        long long curr_people = tier[index];

        for(long long i = 0; i < 4; i++)
        {
            if(curr_people >= detail_tier_quarter)
            {
                detail_tier[i] = detail_tier_quarter;
            }
            else
            {
                detail_tier[i] = max(curr_people, (long long)0);
            }
            curr_people -= detail_tier_quarter;
            
        }
    }

    // 거짓말 판독 부분
    if(tier[index] == 0 || detail_tier[detail_friend_tier-1] == 0)
    {
        cout << "Liar";
        return 0;
    }

    long long start = 0, end = 0;
    for(long long i = 0; i < index; i++)
    {
        start += tier[i];
    }
    start++;
    end = start + tier[index]-1;

    if(detail_friend_tier)
    {
        for(long long i = 0; i < detail_friend_tier-1; i++)
        {
            start += detail_tier[i];
        }
        end = start + detail_tier[detail_friend_tier-1] - 1;
    }

    end = min(end, n);

    cout << start << " " << end;
}