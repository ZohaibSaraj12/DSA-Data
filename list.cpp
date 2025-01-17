#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    list <int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
   l.sort();
    for (int i : l) {
        cout << i << " ";
    }
    return 0;
}