#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    queue <int> qa, qa2;
    queue <int> qb, qb2;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++)
    {
        qa.push(a[i]);
        qb.push(b[i]);
    }
    int ans = 0;
    int cnt = 0;

    while(!qa.empty() && !qb.empty())
    {
        if(qa.front() == qb.front())
        {
            a[cnt] = qa.front();
            b[cnt] = qb.front();
            qa.pop();
            qb.pop();
            cnt++;
        }
        else if(qa.front() > qb.front())
        {
            qb2.push(qb.front());
            qb.pop();
        }
        else
        {
            qa2.push(qa.front());
            qa.pop();
        }
    }
    while(!qa.empty())
    {
        qa2.push(qa.front());
        qa.pop();
    }
    while(!qb.empty())
    {
        qb2.push(qb.front());
        qb.pop();
    }
    
    cout << cnt << "\n";
    for(int i = cnt; i < n; i++)
    {
        a[i] = qa2.front();
        b[i] = qb2.front();
        qa2.pop();
        qb2.pop();
    }

    for(int i : a)
    {
        cout << i << " ";
    }
    cout << "\n";
    for(int i : b)
    {
        cout << i << " ";
    }
}