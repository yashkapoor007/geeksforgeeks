Node*  addTwoLists(Node* first, Node* second){
  // Code here
  Node* result=NULL;
  Node* tail=NULL;
  int c=0;
  while(first&&second)
  {
      if(first->data+second->data+c>=10)
      {
          int data=(first->data+second->data+c)%10;
          c=1;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      else
      {
          int data=first->data+second->data+c;
          c=0;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      first=first->next;
      second=second->next;
  }
  while(first)
  {
      if(first->data+c>=10)
      {
          int data=(first->data+c)%10;
          c=1;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      else
      {
          int data=first->data+c;
          c=0;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      first=first->next;
  }
  while(second)
  {
      if(second->data+c>=10)
      {
          int data=(second->data+c)%10;
          c=1;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      else
      {
          int data=second->data+c;
          c=0;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      second=second->next;
  }
  if(c==1)
  {
      Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=1;
          tail->next=newnode;
          tail=tail->next;
  }
  return result;
}
