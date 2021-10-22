#include<iostream>
using namespace std;
 typedef struct bird{
   int id;
   int count;
 }bird;

int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
  cin>>arr[i];}
bird b[5];
for(int i=0;i<5;i++){
  b[i].id=0;
  b[i].count=0;
}
for(int i=0;i<n;i++){
  if(arr[i]>arr[i+1]){
    int c=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=c;
    i=-1;
  }
}

int start=0;
int index=0;
for(int i=0;i<n;i++){
  if(arr[i]==arr[start]){b[index].id=arr[start]; b[index].count++;}
  else{start=i;i--;index++;}
}


  int max=b[0].count;
  for(int i=1;i<5;i++){
    if(b[i].count>max){max=b[i].count;}}


int result;
 for(int i=0;i<5;i++){
   if(max==b[i].count){result=b[i].id; break; }
 }
cout<<result;


  return 0;
}
