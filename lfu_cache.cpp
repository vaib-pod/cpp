class LFUCache 
{

public:
    struct Node {
   int key, value, cnt;
   Node *next; 
   Node *prev;
   Node(int _key, int _value) {
       key = _key;
       value = _value; 
       cnt = 1; 
   }
};
struct List {
   int size; // Size 
   Node *head; // Dummy head
   Node *tail; // Dummy tail
   
   // Constructor
   List() {
       head = new Node(0, 0); 
       tail = new Node(0,0); 
       head->next = tail;
       tail->prev = head; 
       size = 0;
   }
   
   // Function to add node in front 
   void addFront(Node *node) {
       Node* temp = head->next;
       node->next = temp;
       node->prev = head;
       head->next = node;
       temp->prev = node;
       size++; 
   }
   
   // Function to remove node from the list
   void removeNode(Node* delnode) {
       Node* prevNode = delnode->prev;
       Node* nextNode = delnode->next;
       prevNode->next = nextNode;
       nextNode->prev = prevNode;
       size--; 
   }
};
   map<int, Node*> keyNode; 
   map<int, List*> freqListMap; 
   int maxSizeCache;
   int minFreq; 
   int curSize; 
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        minFreq =0;
        curSize=0;
    }
    void updateFreqListMap(Node *node) {
       
       // Remove from Hashmap
       keyNode.erase(node->key); 
       
       // Update the frequency list hashmap
       freqListMap[node->cnt]->removeNode(node); 
       
       // If node was the last node having it's frequency
       if(node->cnt == minFreq && 
          freqListMap[node->cnt]->size == 0) {
              
           // Update the minimum frequency
           minFreq++; 
       }
       
       // Creating a dummy list for next higher frequency
       List* nextHigherFreqList = new List();
       
       // If the next higher frequency list already exists
       if(freqListMap.find(node->cnt + 1) != 
          freqListMap.end()) {
              
           // Update pointer to already existing list
           nextHigherFreqList = freqListMap[node->cnt + 1];
       } 
       
       // Increment the count of data-item
       node->cnt += 1; 
       
       // Add the node in front of higher frequency list
       nextHigherFreqList->addFront(node); 
       
       // Update the 
       freqListMap[node->cnt] = nextHigherFreqList; 
       keyNode[node->key] = node;
   }
   
    
    int get(int key) {
       if(keyNode.find(key) != keyNode.end()) {
           Node* node = keyNode[key];
           int val = node->value; 
           updateFreqListMap(node); 
           return val; 
       }
       return -1; 
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
           return;
        }
       if(keyNode.find(key) != keyNode.end()) {
           Node* node = keyNode[key]; 
           node->value = value; 
           updateFreqListMap(node); 
       }
       else {
           if(curSize == maxSizeCache) {
               List* list = freqListMap[minFreq]; 
               keyNode.erase(list->tail->prev->key); 
               freqListMap[minFreq]->removeNode(
                   list->tail->prev
               );
               curSize--; 
           }
           curSize++; 
           minFreq = 1;
           List* listFreq = new List(); 
           if(freqListMap.find(minFreq) != 
              freqListMap.end()) {
               listFreq = freqListMap[minFreq]; 
            }
           Node* node = new Node(key, value); 
           listFreq->addFront(node);
           keyNode[key] = node; 
           freqListMap[minFreq] = listFreq; 
       }
   
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */