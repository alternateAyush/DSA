#include <iostream>
#include <list>
using namespace std;

struct HashIt
{
    int bucket;
    list<int> *table;
    HashIt(int n)
    {
        bucket = n;
        table = new list<int>[n];
    }

    void insert(int key)
    {
        int i = key % bucket;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i = key % bucket;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = key % bucket;
        for (auto x : table[i])
        {
            if (x == key)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    HashIt *hash = new HashIt(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        hash->insert(temp);
    }
    int key;
    cin >> key;
    cout << hash->search(key) << endl;

    return 0;
}