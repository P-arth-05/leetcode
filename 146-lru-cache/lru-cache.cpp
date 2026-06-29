class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;

    Node *head, *tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {

        cap = capacity;

        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(!mp.count(key))
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.count(key)){

            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        if(mp.size() == cap){

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key,value);

        insert(node);

        mp[key] = node;
    }
};