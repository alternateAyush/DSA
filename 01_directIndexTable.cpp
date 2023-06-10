// Key are in limited range
// insert,search,delete;

// Let say range = 1000-1999

#include <iostream>
using namespace std;

bool table[1000];

void insert(int i)
{
    table[i - 1000] = 1;
    return;
}
void remove(int i)
{
    if (table[i - 1000] == 1)
    {
        table[i - 1000] = 0;
    }
    return;
}
bool search(int i)
{
    if (table[i - 1000] == 1)
    {
        return true;
    }
    return false;
}
int main()
{
    insert(1000);
    // insert(300);
    cout << search(1000) << endl;
    cout << search(1100) << endl;
}