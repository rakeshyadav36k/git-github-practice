/*
Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

PUT x y: sets the value of the key x with value y
GET x: gets the key of x if present else returns -1.
The LRUCache class has two methods get() and put() which are defined as follows.

get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be initialized.
*/


struct Node {
    int key, val;
    Node *next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
    }
};

class LRUCache {
  private:
    int cap;
    Node *head, *tail;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        this->cap = cap;
        head = tail = nullptr;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(!head) return -1;
        else if(tail->key == key) return tail->val;
        else if(head->key == key) {
            tail->next = head;
            head = head->next;
            tail = tail->next;
            tail->next = nullptr;
            return tail->val;
        }
        else {
            Node *prev = head, *cur = head->next;
            while(cur) {
                if(cur->key == key) {
                    prev->next = cur->next;
                    tail->next = cur;
                    tail = tail->next;
                    tail->next = nullptr;
                    return tail->val;
                }
                
                prev = cur;
                cur = cur->next;
            }
        }
        
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(!head) {
            head = tail = new Node(key, value);
            cap--;
            return;
        }
        else if(tail->key == key) {
            tail->val = value;
            return;
        }
        else if(head->key == key) {
            tail->next = head;
            head = head->next;
            tail = tail->next;
            tail->next = nullptr;
            tail->val = value;
            return;
        }
        else {
            Node *prev = head, *cur = head->next;
            while(cur) {
                if(cur->key == key) {
                    prev->next = cur->next;
                    tail->next = cur;
                    tail = tail->next;
                    tail->next = nullptr;
                    tail->val = value;
                    return;
                }
                
                prev = cur;
                cur = cur->next;
            }
        }
        
        // if not found
        tail->next = new Node(key, value);
        tail = tail->next;
        cap--;
        
        // if there was no space
        if(cap<0) {
            Node *temp = head;
            head = head->next;
            delete temp;
            cap++;
        }
    }
};

/*  it is giving TLE
class LRUCache {
  private:
    class Node{
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int,Node*> mp;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode){
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode){
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // Function to return value corresponding to the key.
    int get(int key_) {
        if(mp.find(key_) != mp.end()){
            Node *resNode = mp[key_];
            int res = resNode->val;
            mp.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key_, int value) {
        if(mp.find(key_) != mp.end()){
            Node *existingNode = mp[key_];
            mp.erase(key_);
            deleteNode(existingNode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key_, value));
        mp[key_] = head->next;
    }
};
*/