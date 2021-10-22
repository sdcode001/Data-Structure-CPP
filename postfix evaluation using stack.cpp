#include<iostream>
#include <string>
using namespace std;
int precidence(char x){
  if(x=='+'||x=='-'){return 1;}
  else if(x=='*'||x=='/'){return 2;}
  else{return 0;}
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
friend string postfix_exp(string s);
friend int postfix_evaluation(string postfix);
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

string postfix_exp(string s){
  int j=-1;
  string res=s;
  stack_linkedlist<char> l;
  l.push('x');   //there is a problem with stack_linkedlist when we reaches to size=0; so we intialy take size=1.
  for(int i=0;i<s.length();i++){
    if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
      if(l.size==1){l.push(s[i]);}
      else{
        char y=l.pop();
        if(precidence(s[i])<=precidence(y)){l.push(s[i]);res[++j]=y;}
        else{l.push(y);l.push(s[i]);} }
       }

    else{
      res[++j]=s[i];
      }
    }

  while(l.size!=1){res[++j]=l.pop();}
  return res;
};
int claculate(int a,int b,char sign){
  if(sign=='+'){return b+a;}
  else if(sign=='-'){return b-a;}
  else if(sign=='/'){return b/a;}
  else{return b*a;}
}
string charTostring(char a){
  string x=" ";
  x[0]=a;
  //x[1]='\0';
  return x;
}

int postfix_evaluation(string postfix){
  int a,b,c;
  stack_linkedlist<string> l1;
  l1.push(" ");
  for(int i=0;i<postfix.length();i++){
    if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'){
      a=stoi(l1.pop()); b=stoi(l1.pop());
      c=claculate(a,b,postfix[i]);
      l1.push(to_string(c));
    }
    else{
      l1.push(charTostring(postfix[i]));
    }
  }
  int result=stoi(l1.pop());
  return result;
}
int main(){
  
string s="3*5+6/2-4";
string postfix=postfix_exp(s);
int res=postfix_evaluation(postfix);
cout<<res;
  return 0;
}
