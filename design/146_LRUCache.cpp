#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    /*
    使用hashmap作为存储，使用链表维护先后关系
    使用双向链表，因为可以在常数时间内删除节点
    */
    struct DoubleLinkedNode
    {
        int key;
        int val;
        DoubleLinkedNode *prev;
        DoubleLinkedNode *next;
        DoubleLinkedNode(int k, int v):key(k),val(v),prev(NULL),next(NULL){}
    };

    class DoubleLinkedList
    {
    public:
        void printList()
        {
            DoubleLinkedNode *p = head;
            cout << "list: ";
            while (p)
            {
                cout << p->key << " ";
                p = p->next;
            }
            cout << endl;
        }

        /*
        双向链表
        */
        void moveToTail(DoubleLinkedNode *node)
        {
            if (tail == node)
            {
                return;
            }
            cout << "moveToTail:" << node->key << endl;
            removeNode(node);
            addNode(node);
            cout << "head:" << head->key << "tail:" << tail->key << endl;
        }

        void removeNode(DoubleLinkedNode *node)
        {
            if (!node)
            {
                return;
            }
            if (head == node)
            {
                printf("head is node:%d\n", node->key);
                head = node->next;
            }
            if (tail == node)
            {
                tail = node->prev;
            }
            //process 这是list操作最关键的地方，记住要把node前后连接起来
            if (node->next)
            {
                node->next->prev = node->prev;
            }
            if (node->prev)
            {
                node->prev->next = node->next;
            }
            node->prev = NULL;
            node->next = NULL;
        }

        //移除最老的，在链表中第一个节点
        DoubleLinkedNode* removeOldest()
        {
            if (!head)
            {
                return NULL;
            }
            if (tail == head)
            {
                tail = NULL;
            }
            cout << "removeOldest:" << head->key << endl;
            DoubleLinkedNode *next = head->next;
            DoubleLinkedNode *res = head;
            removeNode(head);
            head = next;
            return res;
        }

        void addNode(DoubleLinkedNode *node)
        {
            if (!head)
            {
                head = node;
            }
            //process
            node->prev = tail;
            node->next = NULL;
            if (tail)
            {
                tail->next = node;     
            }
            tail = node;
        }

        DoubleLinkedList()
        {
            head = NULL;
            tail = NULL;
        }
    private:
        DoubleLinkedNode *head;
        DoubleLinkedNode *tail;
    };

    LRUCache(int n) 
    {
        capacity = n;
        size = 0;
    }
    
    int get(int key) 
    {
        int value = -1;
        if (g_map.find(key) != g_map.end() && g_map[key])
        {
            value = g_map[key]->val;
            //move 
            g_list.moveToTail(g_map[key]);
        }
        return value;
    }
    
    void put(int key, int value) 
    {
        if (g_map.find(key) != g_map.end() && g_map[key])
        {
            g_map[key]->val = value;
            //move 
            g_list.moveToTail(g_map[key]);
        }
        else
        {
            DoubleLinkedNode *node = new DoubleLinkedNode(key, value);
            node->val = value;
            g_list.addNode(node);
            size++;
            if (size > capacity)
            {
                DoubleLinkedNode* res = g_list.removeOldest();
                g_map.erase(res->key);
                size--;
            }
            g_map[key] = node;
        }
    }

    void printList()
    {
        g_list.printList();
    }

private:
    int size;
    int capacity;
    DoubleLinkedList g_list;
    unordered_map<int, DoubleLinkedNode*> g_map;
};

int main(int argc, char const *argv[])
{
    /* code */
    LRUCache cache(3);
    cache.put(1,1);
    cache.put(2,2);
    cache.put(3,3);
    cache.put(4,4);
    cache.printList();
    cout << cache.get(4) << endl;
    cache.printList();
    cout << cache.get(3) << endl;
    cache.printList();
    cout << cache.get(2) << endl;
    cache.printList();
    cout << cache.get(1) << endl;
    cache.printList();
    cache.put(5,5);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    return 0;
}
