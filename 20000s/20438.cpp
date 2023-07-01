#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, q, m;
    cin >> n >> k >> q >> m;
    
    vector <bool> sleep(n+3);
    vector <int> prefix_sum(n+3);
    for(int i = 0; i < k; i++)
    {
        int student_num;
        cin >> student_num;
        sleep[student_num] = true;
    }

    //아직 출석을 부르기 전, 1의 의미는 출석 전이다.
    for(int i = 3; i <= n+2; i++)
    {
        prefix_sum[i] = 1;
    }

    for(int i = 0; i < q; i++)
    {
        int qr;
        cin >> qr;
        
        if(sleep[qr])
        {
            continue;
        }
        else
        {
            for(int j = 1; j*qr <= n+2; j++)
            {
                if(sleep[qr*j])
                {
                    continue;
                }
                else
                {
                    prefix_sum[qr*j] = 0;
                }
            }
        }
    }

    for(int i = 4; i <= n+2; i++)
    {
        prefix_sum[i] += prefix_sum[i-1];
    }

    for(int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << prefix_sum[end] - prefix_sum[start-1] << "\n";
    }
}