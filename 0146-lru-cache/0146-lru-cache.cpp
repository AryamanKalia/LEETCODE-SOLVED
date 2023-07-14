#include <unordered_map>
#include<bits/stdc++.h>
class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void moveToFront(Node* node) {
        if (node == head) {
            return;
        }
        removeNode(node);
        addToFront(node);
    }

    void removeNode(Node* node) {
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
    }

    void addToFront(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if (head) {
            head->prev = node;
        }
        head = node;
        if (!tail) {
            tail = node;
        }
    }

    void removeLast() {
        if (tail) {
            cache.erase(tail->key);
            Node* prev = tail->prev;
            if (prev) {
                prev->next = nullptr;
            } else {
                head = nullptr;
            }
            tail = prev;
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToFront(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (cache.size() >= capacity) {
                removeLast();
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);
        }
    }
};
