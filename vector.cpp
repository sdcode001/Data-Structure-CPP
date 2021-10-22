#include<iostream>
#include<vector>
using namespace std;
template<class T>
void display(vector<T> &v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";}
    cout<<endl;
}

int main(){
vector<int> v1;
vector<int> v2(5,10);
v1.push_back(4);
v1.push_back(5);
v1.push_back(6);
v1.push_back(7);
vector<int>:: iterator ite=v1.begin();
v1.insert(ite+1,5,100);
v1.erase(v1.begin()+1,v1.begin()+6);
v2.pop_back();
v1.swap(v2);
display<int>(v1);
display<int>(v2);
cout<<v1.at(3);
  return 0;
}
