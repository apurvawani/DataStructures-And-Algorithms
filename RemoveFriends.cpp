After getting her PhD, Christie has become a celebrity at her university, and her facebook profile is full of friend requests. 
Being the nice girl she is, Christie has accepted all the requests.
Now Kuldeep is jealous of all the attention she is getting from other guys, so he asks her to delete some of the guys from her 
friend list.
To avoid a 'scene', Christie decides to remove some friends from her friend list, since she knows the popularity of each of the
friend she has, she uses the following algorithm to delete a friend.

Algorithm Delete(Friend):
    DeleteFriend=false
    for i = 1 to Friend.length-1
         if (Friend[i].popularity < Friend[i+1].popularity)
            delete i th friend
            DeleteFriend=true
            break
    if(DeleteFriend == false)
        delete the last friend

Input:
First line contains T number of test cases. First line of each test case contains N, the number of friends Christie currently has
and K ,the number of friends Christie decides to delete. Next lines contains popularity of her friends separated by space.

Output:
For each test case print N-K numbers which represent popularity of Christie friend's after deleting K friends.

Constraints :
1<=T<=1000
1<=N<=100000
0<=K< N
0<=popularity_of_friend<=100

NOTE:
Order of friends after deleting exactly K friends should be maintained as given in input.

/*
EXECUTION TIME IS MORE
#include <bits/stdc++.h> 
using namespace std;

class Node {
    public :
    int data;
    Node *prev;
    Node *next;
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    friend class List;
};

class List {
    public :
    Node *head;
    List() {
        head = NULL;
    }
    void Insert(int d) {
        Node *temp = new Node(d);
        if(head == NULL) {
            head = temp;
        }
        else {
            Node *x = head;
            while(x->next != NULL) {
                x = x->next;
            }
            x->next = temp;
            temp->prev = x;
        }
    }
    void display() {
        Node *a = head;
        while(a != NULL) {
            cout << a->data << " ";
            a = a->next;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while(t != 0) {
        List l;
        int n , k , d;
        cin >> n >> k;
        for(int i = 0 ; i < n ; i++) {
            cin >> d;
            l.Insert(d); 
        }
        Node *p = l.head;
        while(p->next != NULL) {
            if(p->data < p->next->data && k!=0) {
                Node *x = p;
                if(p == l.head) {
                    l.head = p->next;
                    p->next->prev = NULL;
                    p = p->next;
                    x->next = NULL;
                }
                else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    p = p->prev;
                    x->prev = NULL;
                    x->next = NULL;
                }
                delete(x);
                k--;
            }
            else {
                p = p->next;   
            }
        }
        l.display();
        cout << endl;
        t--;
    }
    return 0;
}*/

//BETTER APPROACH
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n , k;
        cin >> n >> k;
        vector <int> v;
        while(n) {
            int p;
            cin >> p;
            while(!v.empty() && v.back() < p && k != 0) {
                v.pop_back();
                k--;
            }
            v.push_back(p);
            n--;
        }
        for(int i = 0 ; i < v.size() ; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
