#include <iostream>
#include <vector>

using namespace std;

int n;
long long result = 0;

vector <int> arr;
vector <int> temp;

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;
    int cnt = 0;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
            result += cnt;
        }
        else
        {
            temp[k++] = arr[j++];
            cnt++;
        }
    }

    if(i <= mid)
    {
        for(int l = i; l <= mid; l++)
        {
            temp[k++] = arr[l];
            result += cnt;
        }
    }
    else
    {
        for(int l = j; l <= end; l++)
        {
            temp[k++] = arr[l];
        }
    }

    for(int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
}

void mergesort(int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        mergesort(start, mid);
        mergesort(mid+1, end);
        merge(start, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.resize(n);
    temp.resize(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(0, n-1);
    cout << result;
}