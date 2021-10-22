#include<iostream>
using namespace std;
class upper_diagonal_triangle_matrix{
  int n;
  int* matrix;

public:
  upper_diagonal_triangle_matrix(int order){
    n=order;
    int p=(n*(n+1))/2;
    matrix=new int[p];}
  void setdata(int i,int j,int val){
    if(j>=i){
    int x=(2*i*n-2*n-i*i+3*i-2)/2 + (j-i);   //row major formula for upper diagonal triangle.
    matrix[x]=val;}
    }
  int showdata(int i,int j){
    if(i>j){return 0;}
    else{
      int x=(2*i*n-2*n-i*i+3*i-2)/2 + (j-i);
      return matrix[x];}
    }
  ~upper_diagonal_triangle_matrix(){
      delete[]matrix;
    }
};

class toeplitz_matrix{
  int n;
  int* matrix;
public:
  toeplitz_matrix(int order){
    n=order;
    matrix=new int[2*n-1];}

  void setdata(int i,int j,int val){
    if(j>=i){
        matrix[j-i]=val;}
    else{
      matrix[(n-1)+(i-j)]=val;}
     }
  int showdata(int i,int j){
     if(j>=i){return matrix[j-i];}
     else{return matrix[(n-1)+(i-j)];}
     }


  ~toeplitz_matrix(){
    delete[]matrix;
  }
};

int main(){
   toeplitz_matrix m(5);
   m.setdata(1,1,5);
   m.setdata(1,2,6);
   m.setdata(1,3,7);
   m.setdata(1,4,8);
   m.setdata(1,5,9);
   m.setdata(2,1,1);
   m.setdata(3,1,2);
   m.setdata(4,1,3);
   m.setdata(5,1,4);
   cout<<m.showdata(5,2)<<endl;


  return 0;
}
