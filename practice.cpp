 # practice
 //dll
 #include <iostream>

using namespace std;
class node
{ public:
  int data;
  node *next;
  node*pri;
};
class dll
{ public:
  node*head;
  node*tail;
  int n;
  dll()
  {
   head=NULL;
   tail=NULL;
   n=0;
  }
  void insert(int x)
  {
    node*temp=new node;
    temp->data=x;
    ++n;
    if(head==NULL)
    {
      head=temp;
      tail=temp;
      head->next=NULL;
      head->pri=NULL;
      tail->pri=NULL;
    }
    else{
     tail->next=temp;
     temp->pri=tail;
     tail=temp;

    }
    temp->next=NULL;
    }
 void insertAt(int x,int p)
 {
   if(p>n+1)
   cout<<"No more space...";
   else if(p==1 || p==n+1)
    insert(x);
   else{
    node*locate=head;
    for(int i=0;i<p-1;i++)
      locate=locate->next;
    node*temp=new node;
    temp->data=x;
    ++n;
    temp->pri=locate->pri;
    locate->pri=temp;
    temp->next=locate;}
 }
 void Delete()
 {
   node*temp;
   temp=tail;
   tail=tail->pri;
   tail->pri=tail->pri;
   tail->next=NULL;
   delete temp;
   --n;
 }
 void DeleteAt(int p)
 {
   if(p>n+1)
   cout<<"No more space...";
   else if(p==n)
    Delete();
   else{
    node*locate=head;
    for(int i=0;i<p-1;i++)
      locate=locate->next;
    node*temp;
    temp=locate;
    locate->next->pri=temp->pri;
     locate->pri->next=temp->next;
     delete temp;--n;}

 }
void display()
{
  node*print=tail;
  while(print!=NULL)
  {
    cout<<print->data<<endl;
    print=print->pri;
  }
  cout<<endl<<n;
}
};

int main()
{
    int ch;dll d;
    do{
    cout << "1.insert \n 2.display \n 3.insertAt\n 4.Delete \n 5.DeleteAt\n" << endl;cout<<"Enter your choice : ";cin>>ch;
    switch(ch)
    {
      case 1:int x;cout<<"Enter data : ";cin>>x;d.insert(x);break;
      case 2:d.display();break;
      case 3:int a,p;cout<<"Enter the data and position : ";cin>>a>>p;d.insertAt(a,p);break;
      case 4:d.Delete();break;
      case 5: int f;cout<<"Enter the position : ";cin>>f;
              d.DeleteAt(f);break;
      default :break;
    }
    }while(ch!=6);
    return 0;
 }


