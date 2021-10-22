#include<iostream>
using namespace std;
void honoi_tower_suffel(int n,int a[],int b[],int c[]){

     if(n==1){c[n-1]=a[n-1];a[n-1]=0;}
     else{
        honoi_tower_suffel(n-1,a,c,b);
        c[n-1]=a[n-1]; a[n-1]=0;
        honoi_tower_suffel(n-1,b,a,c);
         }
}

int main(){
int n;      //number of ring
cout<<"enter number of ring for tower 1"<<endl;
cin>>n;
int t1[n];
int t2[n];
int t3[n];
// putting rings in tower 1;
for(int m=0;m<n;m++){
    t1[m]=m+1;}
// keeping blank t2 & t3 by putting zero;
for(int m=0;m<n;m++){
  t2[m]=0;
  t3[m]=0;}
cout<<"tower 1 before suffel"<<endl;
for(int m=0;m<n;m++){
    cout<<t1[m]<<endl;}
cout<<"tower 3 before suffel"<<endl;
for(int m=0;m<n;m++){
    cout<<t3[m]<<endl;}

honoi_tower_suffel(n,t1,t2,t3);

cout<<"tower 1 after suffel"<<endl;
  for(int m=0;m<n;m++){
      cout<<t1[m]<<endl;}
cout<<"tower 3 after suffel"<<endl;
  for(int m=0;m<n;m++){
      cout<<t3[m]<<endl;}
  return 0;
}
