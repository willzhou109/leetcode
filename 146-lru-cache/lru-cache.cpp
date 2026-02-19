#include <unordered_map>
#include <iostream>
#include <string>


// remember head = least recently used, tail = most recently used
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node * prev;
        Node * next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };


    int cap;
    int count = 0;
    Node * head = nullptr;
    Node * tail = nullptr;
    std::unordered_map<int, Node *> hm; // you can lookup the key and its node's address


    LRUCache(int capacity) {
        cap = capacity;
    }
   
    int get(int key) { // returns the value
        //std::cout << "get called, searching for " << key << "'s value " << std::endl;
        if (hm.find(key) == hm.end()) { // key not found in LRU cache
            /*std::cout << "not found" << std::endl;
            std::cout << std::endl;*/
            return -1;
        }


        // move this node to the tail
        if (hm[key] != tail) {
            if (hm[key]->prev) { // if it's not at the head
                hm[key]->prev->next = hm[key]->next;
                hm[key]->next->prev = hm[key]->prev;
            } else { // if it is at the head
                head = hm[key]->next;
                head->prev = nullptr;
            }
            tail->next = hm[key];
            hm[key]->prev = tail;
            hm[key]->next = nullptr;
            tail = hm[key];
        } // (no action is needed if it's already at the tail)


        /*std::cout << "hashmap: " << std::endl;
        for (const auto& [key, value] : hm) {
            std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }*/
        //std::cout << "nodes: " << std::endl;
        /*Node * it = head;
        while (it) {
            std::cout << "Node: (Key: " << it->key << ", Value: " << it->val << ")" << std::endl;
            it = it->next;
        }
        std::cout << hm[key]->val << std::endl;
        std::cout << std::endl;*/
        return hm[key]->val;
    }
   
    void put(int key, int value) {
        if (hm.find(key) == hm.end()) { // key doesn't exist in LRU cache
            Node * new_node = new Node(key, value); // create new node (key-value pair)
            hm[key] = new_node; // add it to the hashmap
            if (!head) { // list originally empty
                head = tail = new_node;
            } else {
                // attach it to the tail because it's the most recently used, and assign new_node as the tail
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
            count += 1;
            if (count > cap) {
                count -= 1;
                // evict LRU (head node) from the hashmap and from the doubly linked list
                hm.erase(head->key);
                Node * temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
        } else { // key does exist in LRU cache
            //std::cout << "changing a value..." << std::endl;
            (hm[key])->val = value; // change the node's value


            // move this node to the tail
            if (hm[key] != tail) {
                if (hm[key]->prev) { // if it's not at the head
                    hm[key]->prev->next = hm[key]->next;
                    hm[key]->next->prev = hm[key]->prev;
                } else { // if it is at the head
                    head = hm[key]->next;
                    head->prev = nullptr;
                }
                tail->next = hm[key];
                hm[key]->prev = tail;
                hm[key]->next = nullptr;
                tail = hm[key];
            } // (no action is needed if it's already at the tail)


        }
        /*std::cout << "put called, putting pair " << key << ", " << value << std::endl;
        std::cout << "count: " << count << std::endl;
        std::cout << "hashmap: " << std::endl;
        for (const auto& [key, value] : hm) {
            std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }
        std::cout << "nodes: " << std::endl;
        Node * it = head;
        while (it) {
            std::cout << "Node: (Key: " << it->key << ", Value: " << it->val << ")" << std::endl;
            it = it->next;
        }
        std::cout << std::endl;*/
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
