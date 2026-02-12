#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        deleteNode(node);
        addNode(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            deleteNode(existing);
            mp.erase(key);
        }

        if (mp.size() == capacity) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addNode(newNode);
    }
};

int main() {
    LRUCache cache(2);

    cout << "Put(1,1)\n";
    cache.put(1, 1);

    cout << "Put(2,2)\n";
    cache.put(2, 2);

    cout << "Get(1): " << cache.get(1) << endl;

    cout << "Put(3,3)  -> Evicts 2\n";
    cache.put(3, 3);

    cout << "Get(2): " << cache.get(2) << endl; 

    cout << "Put(4,4)  -> Evicts 1\n";
    cache.put(4, 4);

    cout << "Get(1): " << cache.get(1) << endl; 
    cout << "Get(3): " << cache.get(3) << endl; 
    cout << "Get(4): " << cache.get(4) << endl; 

    return 0;
}
