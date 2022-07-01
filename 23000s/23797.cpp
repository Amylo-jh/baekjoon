#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int max_frog = 0;
    multiset <bool> frog_state;    
    //마지막으로 K를 울었던 개구리는 True 상태로 저장,
    //마지막으로 P를 울었던 개구리는 False 상태로 저장

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if(ch == 'K')
        {
            auto iter = frog_state.find(false);
            
            if(iter != frog_state.end())
            {
                frog_state.erase(iter);
            }    

            frog_state.insert(true);
        }
        else
        {
            auto iter = frog_state.find(true);
            
            if(iter != frog_state.end())
            {
                frog_state.erase(iter);
            }
            
            frog_state.insert(false);
        }
    }

    int k = frog_state.count(true);
    int p = frog_state.count(false);

    cout << k + p;
}