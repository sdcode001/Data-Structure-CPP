#include<iostream>
using namespace std;
class Array{
  int size;
  int length;
  int* array;
public:

  Array(int a,int b){
    length=a;
    size=b;
    array=new int[length];
    for(int m=0;m<length;m++){array[m]=0;}
  }


  void set_array(){
    for(int i=0;i<size;i++){
    cout<<"enter element"<<i+1<<endl;
    cin>>array[i]; }
  }
  void show_array(){
    cout<<"array--->";
    for(int i=0;i<length;i++){cout<<array[i]<<" ";}
    cout<<endl;
  }

  void append(int a){
    if(length>size){
      array[size]=a;
      size++;}
  }
  void insert(int e,int i){
    if(length>size && i<size){
      for(int m=size;m>i;m--){
        array[m]=array[m-1];}
        array[i]=e;
        size++;}
    else{cout<<"wrong insertion !"<<endl;}
  }

  void remove(int s){
    for(int m=s;m<size-1;m++){
      array[m]=array[m+1];}
      size--;
  }

void left_rotate(){
  int start=array[0];
   for(int i=0;i<length-1;i++){array[i]=array[i+1];}
   array[length-1]=start;
}


~Array(){
  delete []array;
}



};
int main(){
Array a(10,7);
a.set_array();
a.show_array();
a.left_rotate();
a.show_array();
a.left_rotate();
a.show_array();
a.left_rotate();
a.show_array();
a.left_rotate();
a.show_array();
  return 0;
}
