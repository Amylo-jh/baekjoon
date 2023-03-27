#include <iostream>
#include <vector>

using namespace std;

// smmh = Symmetric Min-Max Heap
// https://constructionsite.tistory.com/48
// http://iiitdm.ac.in/old/Faculty_Teaching/Sadagopan/pdf/ADSA/new/min_max%20_heap.pdf
vector <int> smmh;

void push(int value)
{
    smmh.push_back(value);
    
    int node_location = smmh.size()-1;
    // 조건 P1 위배 확인
    if(node_location % 2)
    {
        if(smmh[node_location-1] > smmh[node_location])
        {
            int temp = smmh[node_location-1];
            smmh[node_location-1] = smmh[node_location];
            smmh[node_location] = temp;
            node_location--;
        }
    }

    bool done = false;
    while(!done && 4 <= node_location)
    {
        int grandparent = node_location / 4;
        int leftOfGrand = grandparent * 2;
        int rightOfGrand = leftOfGrand + 1;

        // 조건 P2 위배 확인
        if(smmh[leftOfGrand] > smmh[node_location])
        {
            int temp = smmh[node_location];
            smmh[node_location] = smmh[leftOfGrand];
            smmh[leftOfGrand] = temp;
            node_location = leftOfGrand;
        }
        // 조건 P3 위배 확인
        else if(smmh[node_location] > smmh[rightOfGrand])
        {
            int temp = smmh[node_location];
            smmh[node_location] = smmh[rightOfGrand];
            smmh[rightOfGrand] = temp;
            node_location = rightOfGrand;
        }
        else
        {
            done = true;
        }
    }
}

void pop(int direction)
{
    int node_location = smmh.size() - 1;
    int value = smmh[node_location];
    smmh.resize(smmh.size()-1);

    
    if(direction > 0) // 최댓값 삭제
    {
        if(smmh.size() <= 3)
        {
            return;
        }

        bool done = false;
        node_location = 3;
        while(!done && (node_location*2) <= smmh.size())
        {
            int rightChild = (node_location*2) + 1;
            int siblingRightChild = (node_location-1)*2 + 1;
            int maxChild = siblingRightChild;
            if(rightChild < smmh.size() && smmh[siblingRightChild] < smmh[rightChild])
            {
                maxChild = rightChild;
            }

            if(smmh[maxChild] > value)
            {
                smmh[node_location] = smmh[maxChild];
                node_location = maxChild;

                if(value < smmh[node_location-1])
                {
                    smmh[node_location] = smmh[node_location-1];
                    smmh[node_location-1] = value;
                    value = smmh[node_location];
                }
            }
            else
            {
                done = true;
            }
        }
        smmh[node_location] = value;
    }
    else // 최솟값 삭제
    {
        if(smmh.size() <= 2)
        {
            return;
        }
        
        bool done = false;
        node_location = 2;
        while(!done && node_location * 2 <= smmh.size())
        {
            int leftChild = node_location * 2;
            int siblingLeftChild = (node_location+1)*2;
            int minChild = leftChild;
            if(siblingLeftChild < smmh.size() && smmh[siblingLeftChild] < smmh[leftChild])
            {
                minChild = siblingLeftChild;
            }

            if(smmh[minChild] < value)
            {
                smmh[node_location] = smmh[minChild];
                node_location = minChild;

                if(node_location + 1 < smmh.size() && smmh[node_location + 1] < value)
                {
                    smmh[node_location] = smmh[node_location+1];
                    smmh[node_location+1] = value;
                    value = smmh[node_location];
                }
            }
            else
            {
                done = true;
            }
        }
        smmh[node_location] = value;
    }
}

void solve()
{
    smmh.clear();
    smmh.push_back(0);
    smmh.push_back(0);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        char ch;
        int value;
        cin >> ch >> value;

        if(ch == 'I')
        {
            push(value);
        }
        else
        {
            if(smmh.size() <= 2)
            {
                continue;
            }

            if(value > 0)
            {
                pop(1);
            }
            else
            {
                pop(-1);
            }
        }
    }

    if(smmh.size() <= 2)
    {
        cout << "EMPTY";
    }
    else if(smmh.size() == 3)
    {
        cout << smmh[2] << " " << smmh[2];
    }
    else
    {
        cout << smmh[3] << " " << smmh[2];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        solve();
    }
}