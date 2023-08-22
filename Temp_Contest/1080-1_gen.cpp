#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//usage: ./gen (n) (seed)

int main(int argc, char* argv[])
{
    int n=atoi(argv[1]);
    ll seed=atoll(argv[2]);
    mt19937_64 mt(seed);
    vector<pair<int,int>>vec;
    for(int i=-15;i<=15;i++)
    {
        for(int j=-15;j<=15;j++)
        {
            if(i==0&&j==0)continue;
            vec.emplace_back(i,j);
        }
    }

    shuffle(begin(vec),end(vec),mt);
    cout<<n<<"\n";
    for(int i=0;i<n;i++)
    {
        auto[x,y]=vec[i];
        cout<<x<<" "<<y<<"\n";
    }
}