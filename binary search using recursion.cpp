//array must be sorted
#include<iostream>
using namespace std;
void binary_search(int list[],int size,int n){   //n=number, which is searched.
  static int start=0;
  int mid =(start+size)/2;
  if(list[mid]==n){cout<<"element found at index "<<mid<<endl;}
  else if(n<list[mid]){size=mid;binary_search(list,size,n);}
  else{start=mid;binary_search(list,size,n);}
}

int main(){
int arr[18]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
binary_search(arr,18,);
  return 0;
}
