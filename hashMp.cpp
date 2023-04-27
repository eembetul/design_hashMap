
#include <bits/stdc++.h>
using namespace std;

#include <vector>
class MyHashMap {
    private: 
    const int MAX_SIZE = 1000000; // maximum size of the hash table
    std::vector<std::pair<int, int>> data; // the hash table

    // Hash function to map a key to an index in the hash table
    int hash(int key) {
        return key%MAX_SIZE;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() : data(MAX_SIZE, std::make_pair(-1, -1)) {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        int i = 0;
        while(i < MAX_SIZE && data[(index+i)%MAX_SIZE].first != -1 && data[(index+i)%MAX_SIZE].first != key) {
            i++;
        }
        data[(index+i)%MAX_SIZE] = std::make_pair(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        int i = 0;
        while(i < MAX_SIZE && data[(index+i)%MAX_SIZE].first != -1) {
            if (data[(index+i)%MAX_SIZE].first == key) {
                return data[(index+i)%MAX_SIZE].second;
            }
            i++;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        int i = 0;
        while(i < MAX_SIZE && data[(index+i)%MAX_SIZE].first != -1) {
            if (data[(index+i)%MAX_SIZE].first == key) {
                data[(index+i)%MAX_SIZE].first = -1;
                data[(index+i)%MAX_SIZE].second = -1;
                return;
            }
            i++;
        }
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        MyHashMap obj;
        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;
            if (s == "put") {
                int key, val;
                cin >> key >> val;
                obj.put(key, val);
            }
            else if ( s == "remove") {
                int key;
                cin >> key;
                obj.remove(key);
            }
            else {
                int key;
                cin >> key;
                cout << obj.get(key) << endl;
            }
        }
}
    return 0;
}

