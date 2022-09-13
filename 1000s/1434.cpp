#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int box, book;
    cin >> box >> book;

    vector <int> boxs(box);
    vector <int> books(book);
    int freespace = 0;

    for(int i = 0; i < box; i++)
    {
        cin >> boxs[i];
    }
    for(int i = 0; i < book; i++)
    {
        cin >> books[i];
    }

    int box_pointer = 0;
    int book_pointer = 0;
    while(book_pointer != book)
    {
        if(boxs[box_pointer] >= books[book_pointer])
        {
            boxs[box_pointer] -= books[book_pointer];
            book_pointer++;
        }
        else
        {
            box_pointer++;
        }
    }

    for(int i = 0; i < box; i++)
    {
        freespace += boxs[i];
    }

    cout << freespace;
}