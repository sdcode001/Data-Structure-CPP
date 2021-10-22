#include<iostream>
using namespace std;
class Array{
  int size;
  int length;

public:

  Array(int a,int b){
    length=a;
    size=b;
  }
  int* array=new int[length];

  void set_array(){
    for(int i=0;i<size;i++){
    cout<<"enter element"<<i+1<<endl;
    cin>>array[i]; }
  }
  void show_array(){
    cout<<"array--->";
    for(int i=0;i<size;i++){
      cout<<array[i]<<" ";
    }
  }

~Array(){
  delete []array;
}



};
int main(){
Array a(8,5);
a.set_array();
a.show_array();
  return 0;
}
