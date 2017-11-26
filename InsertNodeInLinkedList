/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  };
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node *newnode = (Node *)malloc(sizeof(Node *));
    newnode->data = data;
    newnode->next = NULL;
    Node *temp;
    if(head==NULL) {
        head = newnode;
    }
    else {
        temp = head;
        if(position==0){
            newnode->next = head;
            head = newnode;
        }
        else{
            int count = 1;
            while(count!=position){
                temp = temp->next;
                count++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        
    }
    return head;
    // Complete this method only
  // Do not write main function. 
}
