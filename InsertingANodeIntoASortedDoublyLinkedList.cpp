/*
Given a reference to the head of a doubly-linked list and an integer, data, create a new DoublyLinkedListNode object having data value

data and insert it into a sorted linked list while maintaining the sort.

Function Description :

Complete the sortedInsert function in the editor below. It must return a reference to the head of your modified DoublyLinkedList.
sortedInsert has two parameters:
 1.head: A reference to the head of a doubly-linked list of DoublyLinkedListNode objects.
 2.data: An integer denoting the value of the data field for the DoublyLinkedListNode you must insert into the list.
*/

#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *t = head;
    DoublyLinkedListNode *p = new DoublyLinkedListNode(data);
    //DoublyLinkedListNode *x = t;
    if(head == nullptr) {
        head = p;
    }
    else {
        while(t->next != nullptr) {
            if(t->data > data && t == head) {
                p->next = t;
                t->prev = p;
                head = p;
                break;
            }
            else if(t->next->data > data) {
                p->next = t->next;
                p->prev = t;
                t->next->prev = p;
                t->next = p;
                break;
            }
            //x = t;
            t = t->next;
        }
        //t = t->next;
        if(t->next == nullptr) {
            t->next = p;
            p->prev = t;
            p->next = nullptr;
        }
    }
    return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
