/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node *pre , *post , *temp = head;
    pre = NULL;
    while(temp!=NULL) {
        post = temp->next;
        temp->next = pre;
        pre = temp;
        temp = post;
    }
    head = pre;
    return head;
    // Complete this method
}
