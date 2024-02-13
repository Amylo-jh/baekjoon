#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
double inf = 1e9;
double cost[16][16];
double dp[16][65536];

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
double tsp(int here, int visit)
{
    // 현재 도시를 방문했다고 마킹
    visit |= (1 << here);

    // 모든 도시를 지난 경우
    if(visit == (1 << n) - 1)
    {
        if(cost[here][0] > 0)
        {
            return cost[here][0];
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
        if(next != here && !has_visited(visit, next) && cost[here][next] > 0)
        {
            double new_cost = tsp(next, visit) + cost[here][next];
            dp[here][visit] = min(dp[here][visit], new_cost);
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
    vector <pair <int, int>> location(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> location[i].first >> location[i].second;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double dist = 0;
            double dx = abs(location[i].first - location[j].first);
            double dy = abs(location[i].second - location[j].second);
            dx = dx*dx;
            dy = dy*dy;
            dist = sqrt(dx + dy);
            cost[i][j] = dist;
        }
    }

    cout.precision(20);
    cout << tsp(0, 0);
}