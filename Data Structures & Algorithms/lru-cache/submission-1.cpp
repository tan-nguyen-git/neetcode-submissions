class LRUCache {
public:
    struct ListNode{
        std::pair <int,int> kV;
        ListNode* next;
        ListNode* prev;
        ListNode(int key, int val){
            kV = std::make_pair(key,val);
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    //key value are int pair 
    int size = 0;
    int capacity =0;
    //head for the least recently used
    //tail for the recently used
    //these esure the time to remove/add element will be O(1)
    ListNode* head = nullptr;
    ListNode* tail =nullptr;
    //map for get function to ensure the finding will bre O(1)
    //key and address of the map
    std::unordered_map<int,ListNode*> m;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    //update the cache
    //find the pointer using map, then compute the res
    //update the recently cache

    int get(int key) {
        if(!m.contains(key)) return -1;

        ListNode* ptr = m.at(key);
        int res = ptr->kV.second;
        //already most recently used
        if(ptr == tail){
            return res;
        }
        //least recently used
        if(ptr == head){
            head = ptr->next;
            head->prev = nullptr;
        }
        //in the middle
        else{
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        tail->next = ptr;
        ptr->prev = tail;
        tail = tail->next;

        ptr->next = nullptr;
        
        return res;
    }
    
    void put(int key, int value) {
       
        if(m.contains(key)){
            ListNode* ptr= m.at(key);
            ptr->kV = {key, value};

            get(key);//update the cache;
            return;
        }
        ListNode* newNode = new ListNode(key, value);
        if(size == capacity && size ==0){
            delete(newNode);
            return;
        
        }
        else{
            size++;
            m.insert({key, newNode});
            if(!head){
                head = newNode;
                tail = newNode;
                return;
            }
            ListNode* currTail = tail;
            tail->next = newNode;
            tail = tail->next;
            tail->prev =currTail;
           
            if(size > capacity){
                //erase the least cache
                //map
                size--;
                ListNode* toRemove = head;
                std::pair<int, int> kV = toRemove->kV;
                int key = kV.first;
                m.erase(key);
                //linked list
                head = head->next;
                head->prev = nullptr;
                delete(toRemove);

                
            }
            
        }
        
    }
};
