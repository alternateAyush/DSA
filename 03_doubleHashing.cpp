#include <iostream>
#include <vector>
using namespace std;

// double hashing
struct HashIt
{
    int n;
    vector<int> v;
    int size;
    HashIt(int x)
    {
        n = x;
        size = 0;
        for (int i = 0; i < n; i++)
        {
            v.push_back(-1);
        }
    }
    void insert(int x)
    {
        if (size == n)
        {
            cout << "ERROR" << endl;
            return;
        }
        int h1 = x % n;
        int h2 = (n - 1) - (x % (n - 1));
        while (v[h1] != -1 && v[h1] != -2 && v[h1] != x)
        {
            h1 = (h1 + h2) % n;
        }
        if (v[h1] == x)
        {
            cout << "Already present" << endl;
            return;
        }
        v[h1] = x;
        size++;
        return;
    }
    void erase(int x)
    {
        int h1 = x % n;
        int h2 = (n - 1) - (x % (n - 1));
        int i = h1;
        while (v[i] != -1)
        {
            if (v[i] == x)
            {
                v[i] = -2;
                size--;
                return;
            }
            i = (i + h2) % n;
            if (i == h1)
            {
                return;
            }
        }
        return;
    }
    bool search(int x)
    {
        int h1 = x % n;
        int h2 = (n - 1) - (x % (n - 1));
        int i = h1;
        while (v[i] != -1)
        {
            if (v[i] == x)
            {
                return true;
            }
            i = (i + h2) % n;
            if (i == h1)
            {
                return false;
            }
        }
        return false;
    }
    void get()
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
};

int main()
{
    int n;
    cin >> n;
    int x;
    HashIt *hash = new HashIt(7);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        hash->insert(x);
    }
    hash->get();
    hash->erase(49);
    hash->erase(54);
    hash->get();
    if (hash->search(52))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    hash->insert(71);
    hash->insert(42);
    hash->get();
    return 0;
}