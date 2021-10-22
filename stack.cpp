#include<iostream>
using namespace std;
template<class T>
class stack_array{
 int size=0;
 T* data=NULL;
 int pointer=-1;
public:
  stack_array(int n){
    size=n;
    data=new T[size];
  }
  ~stack_array(){delete []data;}

  void push(int x){
    if(pointer==size-1){cout<<"Stack Overflow!"<<endl;}
    else{
      pointer++;
      data[pointer]=x;
    }
  }
  int pop(){
    int y;
    if(pointer==-1){cout<<"Stack underflow"<<endl;}
    else{
      y=data[pointer];
      data[pointer]=NULL;
      pointer--;
      return y;
    }
  }
void display(){
  if(pointer==-1){cout<<"Stack underflow"<<endl;}
  else{for(int i=pointer;i>=0;i--){cout<<data[i]<<endl;}}
}

bool isEmpty(){
  if(pointer==-1){return true;}
  return false;
}
bool isFull(){
  if(pointer==size-1){return true;}
  return false;
}

};

//--------------------------------------------------------------------------------------------------------------------------------------------------
//there is a problem with(pointer) stack_linkedlist when we reaches to size=0; so we intialy take size=1 by push some element.
template<class T1>
class stack_linkedlist{    //here is no limit of storing data. and indexes starts from 1.
  int size=0;
  typedef struct Node{
   T1 data;
   Node* next;
   }Node;

    Node *frist;
    Node *t;
    Node* last;

public:
   stack_linkedlist(){frist=new Node;}
  ~stack_linkedlist(){Node* p=last;for(int i=0;i<size;i++){delete p;p=p->next;}}

 void push(T1 x){
   if(size==0){frist->data=x;frist->next=NULL;last=frist;size++;}
    else{
      t=new Node;
      t->data=x;
      t->next=last;
      last=t;
      size++;
    } }
  T1 pop(){
    Node* q=last;
    T1 x=q->data;
    if(size!=0){last=last->next;}

    if(size==0){cout<<"stack underflow!"<<endl;}
    else{
      q->next=NULL;
      delete q;
      size--;
      return x;}
   }
  void display(){
    Node* p=last;
    if(p==NULL){cout<<"stack underflow!"<<endl;}
    else{
    while(true){
      if(p->next==NULL){break;}
      cout<<p->data<<endl;
      p=p->next;
    }}
  }
bool isEmpty(){
    if(size==0){return true;}
    return false;
  }

};
int main(){
// stack_array<int> s(7);
// s.push(2);
// s.push(4);
// s.push(6);
// s.push(8);
// s.push(10);
// s.push(12);
// s.push(14);
// int a=s.pop();
// int b=s.pop();
// s.display();
stack_linkedlist<int> s1;
s1.push(3);
s1.push(5);
s1.push(7);
int a=s1.pop();
int b=s1.pop();
int c=s1.pop();
//s1.display();
cout<<a<<b<<c;
  return 0;
}
