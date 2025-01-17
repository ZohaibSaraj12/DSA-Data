#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(20);
    q.push(10);
    q.push(23);


    cout << "Front is : " << q.front() << endl;

    cout << "Rear is: " << q.back() << endl;


    cout << "Empty or not : " << q.empty() << endl;


    cout << "Size is : " <<  q.size() << endl;
    return 0;
}