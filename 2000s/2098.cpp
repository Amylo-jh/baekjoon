#include <iostream>
#include <vector>

using namespace std;

int n;
int inf = 1e9;
int dp[16][65536];
vector <vector <int>> costs;

bool has_visited(int bits, int city)
{
    if(bits & (1 << city))
    {
        return true;
    }
    return false;
}

// here : 이번에 지날 도시 번호
// visit : 이미 방문한 도시 체크
int tsp(int here, int visit)
{
    // 현재 도시를 방문했다고 마킹
    visit |= (1 << here);

    // 모든 도시를 지난 경우
    if(visit == (1 << n) - 1)
    {
        if(costs[here][0] > 0)
        {
            return costs[here][0];
        }
        else
        {
            return inf;
        }
    }

    // 메모이제이션 체크
    // 메모되어 있으면 해당 값 반환, 없으면 max로 초기화 하고 값 계산 수행
    if(dp[here][visit] > 0)
    {
        return dp[here][visit];
    }
    dp[here][visit] = inf;

    // 현재 도시에서 아직 방문하지 않은 다른 도시로의 이동 코스트 계산
    for(int next = 0; next < n; next++)
    {
        if(next != here && !has_visited(visit, next) && costs[here][next] > 0)
        {
            int new_cost = tsp(next, visit) + costs[here][next];
            if(new_cost < dp[here][visit])
            {
                dp[here][visit] = new_cost;
            }
        }
    }

    return dp[here][visit];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    costs.resize(n);
    for(int i = 0; i < n; i++)
    {
        costs[i].resize(n);
        //fill_n(dp[i], sizeof(dp[i]) / sizeof(int), -1);

        for(int j = 0; j < n; j++)
        {
            cin >> costs[i][j];
        }
    }

    cout << tsp(0, 0);
}