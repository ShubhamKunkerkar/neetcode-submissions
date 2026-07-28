class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, Node*> list;
    Node* start = nullptr;
    Node* curr = start;
    int capacity = 0;

    LRUCache(int capacity) { this->capacity = capacity; }
    int get(int key) {
        if(list.contains(key)){
            int out = list[key]->value;
            get_helper(key);
            return out;
        }
        return -1;
    }
    void get_helper(int key) {
        if (curr == list[key])
            return;
        int value = list[key]->value;
        list[key]->prev->next = list[key]->next;
        list[key]->next->prev = list[key]->prev;
        if(list[key] == start){
            start = start->next;
        }
        delete list[key];
        list.erase(key);
        put(key, value);
    }
    void get_helper(int key, int value) {
        if (curr == list[key]) {
            curr->value = value;
            return;
        }
                
        list[key]->prev->next = list[key]->next;
        list[key]->next->prev = list[key]->prev;
        if(list[key] == start){
            start = start->next;
        }
        delete list[key];
        list.erase(key);
        put(key, value);
    }

    void put(int key, int value) {
        if (curr == nullptr) {
            curr = new Node(key, value);
            start = curr;
            curr->prev = curr;
            list[key] = curr;
        } else if (list.contains(key)) {
            get_helper(key, value);
        } else {
            curr->next = new Node(key, value);
            Node* prev = curr;
            curr = curr->next;
            curr->prev = prev;
            start->prev = curr;
            list[key] = curr;
        }
        if (list.size() > capacity) {
            Node* prev_start = start;
            list.erase(prev_start->key);
            start->next->prev = start->prev;
            start = start->next;
            delete prev_start;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */