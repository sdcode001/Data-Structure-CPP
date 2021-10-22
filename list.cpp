#include<iostream>
#include<list>
using namespace std;
template<class T>
void display(list<T> &lst){
  list<int>::iterator it=lst.begin();
  for(int i=0;i<lst.size();i++){
    cout<<*it<<" ";
    it++;}
    cout<<endl;
}
int main(){
list<int> list1;
list1.push_back(5);
list1.push_back(23);
list1.push_back(15);
list1.push_back(74);
list1.push_back(54);
list1.push_back(94);
list1.sort();
list<int>::iterator ite=list1.begin();
ite++;
ite++;
list1.insert(ite,4,100);
list1.remove(100);
list<int> list2;
int t=103;
for(int i=0;i<5;i++){
   list2.push_back(t);
   t+=7;}
display<int>(list1);
display<int>(list2);
list1.merge(list2);
list1.reverse();
display<int>(list1);
  return 0;
}
