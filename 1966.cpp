#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        queue <pair<int, int>> printqueue;
        priority_queue <int> importance;
        
        int documents;
        int query;
        int sequence = 0;
        cin >> documents >> query;

        //값을 우선순위 큐와 pair로 구성된 큐에 입력
        for(int i = 0; i < documents; i++)
        {
            int doc_priority;
            cin >> doc_priority;

            printqueue.push( {doc_priority, i} );
            importance.push(doc_priority);
        }

        while(1)
        {
            if(printqueue.front().first != importance.top())
            {
                pair <int, int> tmppair = printqueue.front();
                printqueue.pop();
                printqueue.push(tmppair);
            }
            else
            {
                if(printqueue.front().second == query)
                {
                    sequence++;
                    break;
                }

                importance.pop();
                printqueue.pop();
                sequence++;
            }
        }

        cout << sequence << endl;
    }
}