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

class MyHashMap {
public:
//number of buckets == size of table
int n = 10000;
//Each arr[i] is a bucket, which is a vector of (key, value) pairs. This structure is used to handle collisions.
vector<vector<pair<int , int>>> arr;

//initializes the array of buckets to size n
    MyHashMap() {
        arr.resize(n);
    }
//put function    
    void put(int key, int value) {
        //find the idx for arr
        int idx = key%n;
        for(auto& it: arr[idx]){
            if(it.first == key){
                //if key is found then value is updated
                it.second = value;
                return;
            }
        }
        //else new {key, value} pair is pushed
        arr[idx].push_back({key, value});
    }
   
//get function    
    int get(int key) {
        //find the idx for arr
        int idx = key%n;
        for(auto it: arr[idx]){
            //if key is found then return its value
            if(it.first == key) return it.second;
        }
        //else return -1
        return -1;
    }
    
    void remove(int key) {
        //find the idx for arr
        int idx = key%n;
        for(int i=0;i<arr[idx].size();i++){
            //if key is found then remove its {key, value} pair
            if(arr[idx][i].first == key){
                arr[idx].erase(arr[idx].begin() + i);
                return;
            }
        }
    }
};


int main(){
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    cout << obj.get(1) << endl; // 10
    cout << obj.get(3) << endl; // -1
    obj.put(2, 30);
    cout << obj.get(2) << endl; // 30
    obj.remove(2);
    cout << obj.get(2) << endl; // -1
    return 0;
    return 0;
}