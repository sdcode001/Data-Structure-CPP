#include<iostream>
#include<string>
using namespace std;
char compliment(char x){
  if(x=='('){return ')';}
  else if(x=='{'){return '}';}
  else{return ']';}
}
template<class T1>
class stack_linkedlist{    //here is no limit of storing data. and indexes starts from 1.
  typedef struct Node{
   T1 data;
   Node* next;
   }Node;

    Node *frist;
    Node *t;
    Node* last;

friend string paranthesis_match(string s);
public:
   int size=0;
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
    while(p!=NULL){
      cout<<p->data<<endl;
      p=p->next;
    }}
  }
bool isEmpty(){
    if(size==0){return true;}
    return false;
  }

};

string paranthesis_match(string s){

  stack_linkedlist<char> l;
  for(int i=0;i<s.length();i++){
    if(s[i]=='('||s[i]=='{'||s[i]=='['){l.push(s[i]);}
    else if(s[i]==')'||s[i]=='}'||s[i]==']'){
      char y=l.pop();
      if(s[i]==compliment(y)){}
      else{l.push(y);}
    }
    else{}
  }
  if(l.size==0){return "Success";}
  return "Dont match!!";
}


int main(){


cout<<paranthesis_match("{(2+4)*[7-8]}");

  return 0;
}
