# Flam-Assignment

# 🧠 LRU Cache - C++ Implementation

This project implements a **Least Recently Used (LRU) Cache** using **C++**. The LRU cache is designed to support efficient operations in **O(1)** time complexity for both `get` and `put` by combining a **hash map** and a **doubly linked list**.

---

## 🚀 Features 

- Stores key-value pairs with a fixed capacity.
- Evict the **least recently used** item to make space for the new one.
- `get` and `put` operations in **constant time**.
- Uses:
  - A **hash map** for fast key look-up.
  - A **doubly linked list (DLL)** to track usage order (most recently used at the front).

---

## 🧩 Data Structures Used

- **Hash Map (`unordered_map<int, Node*>`)**: Maps keys to their corresponding nodes in the DLL for O(1) access.
- **Doubly Linked List (DLL)**:
  - Stores the actual key-value nodes.
  - Head → Most Recently Used (MRU).
  - Tail → Least Recently Used (LRU).

---

## 🔧 Functions

### `LRUCache(int capacity)`
- Function for deciding the LRUCache capacity.
- Declares the dummy head and tail.

### `int get(int key)`
Return the value of the key if it exists in the cache, otherwise return -1.

### `void put(int key, int value)`
Update or insert the value. If the cache is full, removes the least recently used item before inserting.

---

## 🧪 Sample Usage

```cpp
int main() {
    LRUCache lru(2);
    lru.put(1, 1);              // Cache: {1=1}
    lru.put(2, 2);              // Cache: {2=2, 1=1}
    cout << lru.get(1) << endl; // Output: 1, Cache: {1=1, 2=2}
    lru.put(3, 3);              // Evicts key 2, Cache: {3=3, 1=1}
    cout << lru.get(2) << endl; // Output: -1 (not found)
    lru.put(4, 4);              // Evicts key 1, Cache: {4=4, 3=3}
    cout << lru.get(1) << endl; // Output: -1
    cout << lru.get(3) << endl; // Output: 3
    cout << lru.get(4) << endl; // Output: 4
}
```

# 🗃️ MyHashMap - C++ Implementation

This project implements a simplified version of a **HashMap (unordered map / dictionary)** from scratch in **C++**, without using any built-in hash table libraries like `unordered_map`, `map`, or `dict`.

The goal is to support the following operations in average-case **O(1)** time:

- `put(key, value)`: Insert or update a key-value pair.
- `get(key)`: Retrieve the value for a given key.
- `remove(key)`: Remove the key and its associated value.

---

## 📦 Data Structure Overview

### 🔢 Hash Table Design

- A **fixed-size array** (of size `10000`) is used to simulate buckets in a hash table.
- Each bucket is a `vector<pair<int, int>>`, i.e., a list of key-value pairs.
- This handles **collisions** using **separate chaining** via vectors.

### 🧮 Hash Function

```cpp
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
```
