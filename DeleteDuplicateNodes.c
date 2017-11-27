/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{    
    Node *temp;
    if(head==NULL) {
        return NULL;
    }
    temp = head->next;
    while(temp!=NULL && head->data==temp->data) {
        temp = temp->next;
    }
    head->next = RemoveDuplicates(temp);
    return head;
    
    
    /*
    NON-RECURSSIVE APPROACH
    Node *temp = head , *pointer = head;
    while(head->next!=NULL) {
        if(head->data!=temp->data) {
            head = head->next;  
        }
        else {
            head->next = head->next->next; 
        }
        temp = head->next;
    }
    return pointer;
    
    */
    
  // This is a "method-only" submission. 
  // You only need to complete this method. 
}
