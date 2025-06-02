#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;
typedef set<int> si;

// Macros
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

class LRUCache {
    private:
    //structure of Node 
    //used doubly linked list data structure where most recently used is at front and least recently used at the back
    // node structure contains a pair of key and value
    struct Node
    {
        /* data */
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {} 
    };
    

    //global variable declaration
    //hashmap for O(1) access
    //dummy head and tail
    int capacity;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;

    //remove node function for DLL
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }


    //inserts a new node after the dummy node marking as most recently node
    void insertToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    public:
    //function for deciding the LRUCache capacity
    //declares the dummy head and tail
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }


    //Return the value of the key if it exists in the cache, otherwise return -1
    int get(int key) {
        if (map.find(key) == map.end()){
            //key not found hence return -1
            return -1;
        }
        //if found then remove the node from it position and insert it in front marking a most recently used
        //return it value
        Node* node = map[key];
        remove(node);
        insertToFront(node);
        return node->value;
    }


    //Update or insert the value. If the cache is full, remove the least recently used item before inserting
    void put(int key, int value) {
        //if key is found then updates it value
        //remove it from the current position
        //insert it in front of the DLL marking as most recently used
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            remove(node);
            insertToFront(node);
        } else {
            //if key is not found
            //if LRUCache is full then remove the LRU
            if (map.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                map.erase(lru->key);
                delete lru;
            }
            //create new node and insert it in front
            Node* newNode = new Node(key, value);
            insertToFront(newNode);
            map[key] = newNode;
        }
    }


    //destructor
    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout<<lru.get(1)<<endl; //1
    lru.put(3, 3);
    cout<<lru.get(2)<<endl; // -1
    lru.put(4, 4);
    cout<<lru.get(1)<<endl; //-1
    cout<<lru.get(3)<<endl; //3
    cout<<lru.get(4)<<endl; //4
    return 0;
}
