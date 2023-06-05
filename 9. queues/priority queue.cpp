#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue<int> pq1)
{
    priority_queue<int> g =pq1;

    while(!g.empty())
    {
        cout<<g.top()<<" ";
        g.pop();
    }
    cout<<endl;

    // if(g.empty())
    // {
    //     cout<<"The queue is empty\n";
    // }
}
int main()
{   
    priority_queue<int> pq1;

    //push()
    //pop()
    //showpq()

    cout<<"Enter the number of elements you want to enter "<<endl;
    
    int x;
    cin>>x;

    while(x--)
    {   
        int y;
        // cout<<"Enter the element you to enter\n";
        cin>>y;
        pq1.push(y);
    }

    showpq(pq1);

    cout<<"Enter the number of elements you want to delete\n";
    int del;
    cin>>del;

    while(del--)
    {
        int t;
        t = pq1.top();
        cout<<t<<" ";
        pq1.pop();
    }

    cout<<endl;
    showpq(pq1);
    return 0;
}