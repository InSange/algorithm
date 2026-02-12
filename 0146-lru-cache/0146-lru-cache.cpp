class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    void removeNode(Node* node) {
        // node의 앞뒤를 서로 연결
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;

        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        Node* curNode = cache[key];
        moveToHead(curNode);

        return curNode->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end())
        {
            Node* newNode = new Node(key, value);

            if(cache.size() == capacity)
            {
                Node* delNode = tail->prev;
                cache.erase(delNode->key);
                removeNode(delNode);
            }
            addNode(newNode);
            cache[key]=newNode;
        }
        else
        {
            cache[key]->val = value;
            moveToHead(cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */