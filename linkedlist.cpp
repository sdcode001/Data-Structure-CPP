#include<iostream>
using namespace std;
template<class T>
class LinkedList{
  typedef struct Node{
   T data;
   Node* next;
   }Node;

    Node *frist;
    Node *t;
    Node *last;

    int n=0; // initializing number of element.

public:
  LinkedList(T arr[]=NULL, int a=0){  //setting default values for empty linkedlist.
    n=a;

    //creating 1st node.
    if(n!=0){
    frist=new  Node;
    frist->data=arr[0];
    frist->next=NULL;
    last=frist;}
    //creating other nodes.
    for(int i=1;i<n;i++){
      t=new Node;
      t->data=arr[i];
      t->next=NULL;
      last->next=t;
      last=t;}
     }
~LinkedList(){Node* p=frist;for(int i=0;i<n;i++){delete p;p=p->next;}}

void display(){
  Node* p=frist;
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;}
   }
void Recursive_display(){
  static Node* q=frist;
  if(q!=NULL){
  cout<<q->data<<" ";
  q=q->next;
  Recursive_display();}
}
int length(){
  int count=0;
  Node* p=frist;
  while(p!=NULL){
    count++;
    p=p->next;}
    return count;
   }
T sum_elements(){
  T sum=0;
  Node* p=frist;
  while(p!=NULL){
    sum+=p->data;
    p=p->next;}
    return sum;
}
T max_element(){
  Node* p=frist;
  T max=p->data;
  p=p->next;
  while(p!=NULL){
    if(p->data>max){max=p->data;}
    p=p->next;}
    return max;}
void push_back(T a){

  if(n==0){
    frist=new Node;
    frist->data=a;
    frist->next=NULL;
    last=frist;
    n++;}
    else{
      t=new Node;
      t->data=a;
      t->next=NULL;
      last->next=t;
      last=t;
      n++;}
  }
void sorted_insert(T c){
  Node* p=frist;
  Node* q=frist->next;
  while(p!=NULL){
    if(p->data<=c && q->data>c){
      Node* ptr=new Node;
      ptr->data=c;
      p->next=ptr;
      ptr->next=q;
      break;}
    p=p->next;
    q=q->next;}
  n++;
  }

  void insert(T val,int index){   //index starts from 1.
    Node* p=frist;
    for(int i=1;i<index-1;i++){p=p->next;}
    Node* q=new Node;
    q->data=val;
    q->next=p->next;
    p->next=q;
    n++;
  }
  void remove(int index){  //index starts from 1.
      Node*p=frist;
      Node*q=frist->next;
      if(index==1){
        frist=q;
        p->next=NULL;
        delete p;}
      else{
        int count=2;
        while(q!=NULL){
          if(count==index){
            p->next=q->next;
            q->next=NULL;
            delete q;
            break;}
          count++;
          p=p->next;
          q=q->next;}
        } n--;
      }
void reverse(){   //by reversing the links.
  Node* p=frist;
  Node* q=frist->next;
  Node* r=frist->next;
  while(q!=NULL){
    if(q->next==NULL){r->next=p;frist->next=NULL;last=frist;frist=q;break;}
    q=q->next;
    r->next=p;
    p=r;
    r=q;}
 }

};
//---------------------------------------------------------------------------------
template<class T1>
class CircularLinkedList{
  typedef struct Node{
   T1 data;
   Node* next;
   }Node;

    Node *frist;
    Node *t;
    Node *last;
    int n=0; // initializing number of element.
  public:

    CircularLinkedList(T1 arr[]=NULL,int a=0){
      n=a;
      //creating 1st node.
      if(n!=0){
      frist=new  Node;
      frist->data=arr[0];
      frist->next=NULL;
      last=frist;}
      //creating other nodes.
      for(int i=1;i<n;i++){
        t=new Node;
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;}
        last->next=frist;
    }
    ~CircularLinkedList(){Node* p=frist;for(int i=0;i<n;i++){delete p;p=p->next;}}

    void display(){
      Node* p=frist;
      do{
        cout<<p->data<<" ";
        p=p->next;}while(p!=frist);
     }

     void insert(T1 val,int index){   //index starts from 1.
       Node* p=frist;
       for(int i=1;i<index-1;i++){p=p->next;}
       Node* q=new Node;
       q->data=val;
       q->next=p->next;
       p->next=q;
       n++;
       if(index==1){frist=q;}
     }
};

template<class T2>
class DoublyLinkedList{
  typedef struct Node{
    Node* prev;
    T2  data;
    Node* next;
  }Node;

Node* frist;
Node* t;
Node* last;
int n=0; // initializing number of element.
public:
    DoublyLinkedList(T2 arr[]=NULL,int a=0){
      n=a;
      if(n!=0){
      frist=new Node;
      last=frist;
      frist->prev=NULL;
      frist->data=arr[0];
      frist->next=NULL;}
      for(int i=1;i<n;i++){
        t=new Node;
        t->data=arr[i];
        last->next=t;
        t->prev=last;
        last=t;
        t->next=NULL;}
     }
  ~DoublyLinkedList(){Node* p=frist;for(int i=0;i<n;i++){delete p;p=p->next;}}

  void display(){
    Node* p=frist;
    while(p!=NULL){
      cout<<p->data<<" ";
      p=p->next;}
     }

  void insert(int val,int index){    //index starts from 1.
    Node* p=frist;
    if(index==1){
      Node* r=new Node;
      r->data=val;
      r->next=frist;
      frist->prev=r;
      r->prev=NULL;
      frist=r;
      n++;
    }
    else{
    for(int i=1;i<index-1;i++){p=p->next;}
    Node* q=p->next;
    Node* r=new Node;
    r->data=val;
    p->next=r;
    r->prev=p;
    r->next=q;
    q->prev=r;
    n++;}
  }

  void remove(int index){   //index starts from 1.
    Node* p=frist;
    Node* q=p->next;
    if(index==1){
      frist=q;
      q->prev=NULL;
      p->next=NULL;
      delete p;
      n--;}
    else{
      for(int i=1;i<index-1;i++){q=q->next;p=p->next;}
      Node* r=q->next;
      p->next=r;
      r->prev=p;
      q->next=NULL;
      q->prev=NULL;
      delete q;
      n--;}
  }

};
int main(){
int array[5]={1,2,4,5,7};
int array1[5]={11,13,15,17,19};
LinkedList <int> l(array,5);
CircularLinkedList <int> l1(array1,5);
DoublyLinkedList<int> l2(array1,5);
// l.Recursive_display();
// //cout<<l.sum_elements();
// LinkedList<int> l;
// l.push_back(4);
// l.push_back(7);
// l.push_back(9);
// l.push_back(10);
// l.push_back(13);
// l.display();
// cout<<l.sum_elements();
// l.sorted_insert(3);
// l.remove(4);
// l.reverse();
//concatenate(l,l1);


//l1.insert(300,1);
l2.insert(100,4);
l2.remove(4);
l2.display();
// l1.display();
  return 0;
}
