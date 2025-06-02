# Flam-Assignment

# 🧠 LRU Cache - C++ Implementation

This project implements a **Least Recently Used (LRU) Cache** using **C++**. The LRU cache is designed to support efficient operations in **O(1)** time complexity for both `get` and `put` by combining a **hash map** and a **doubly linked list**.

---

## 🚀 Features 

- Stores key-value pairs with a fixed capacity.
- Automatically evicts the **least recently used** item when full.
- Provides `get` and `put` operations in **constant time**.
- Uses:
  - A **hash map** (`unordered_map`) for fast key look-up.
  - A **doubly linked list (DLL)** to track usage order (most recently used at the front).

---

## 🧩 Data Structures Used

- **Hash Map (`unordered_map<int, Node*>`)**: Maps keys to their corresponding nodes in the DLL for O(1) access.
- **Doubly Linked List (DLL)**:
  - Stores the actual key-value nodes.
  - Head → Most Recently Used (MRU).
  - Tail → Least Recently Used (LRU).
  - Two dummy nodes (`head` and `tail`) are used for easy insert/remove operations.

---

## 🔧 Functions

### `LRUCache(int capacity)`
Initializes the cache with a given capacity.

### `int get(int key)`
Returns the value if the key exists, otherwise returns `-1`. Moves the accessed node to the front (most recently used).

### `void put(int key, int value)`
Inserts or updates the key-value pair. If the cache exceeds capacity, evicts the least recently used node.

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
