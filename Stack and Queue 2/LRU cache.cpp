#include<bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            prev = NULL;
            next = NULL;
        }
    };

    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);

    unordered_map<int,Node*> mp;
    int cap;

    void addNode(Node* newnode){
        Node* temp = head->next;
        
        newnode->prev = head ;
        newnode->next = temp;

        temp->prev = newnode;
        head->next = newnode;
    }

    void deleteNode(Node * delnode){
        Node* prevv= delnode->prev;
        Node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    LRUCache(int capacity)
    {
        cap = capacity; 
        head->next = tail;
        tail->prev = head;  
    }

    int get(int key)
    {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            int ans = temp->val;

            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return ans;
            
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()){
            Node * temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
       
    }
};
