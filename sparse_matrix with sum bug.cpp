#include<iostream>
using namespace std;
typedef struct element{
  int i;
  int j;
  int val;
}element;

class sparse_matrix{

  int row;
  int col;
  int no_nonzero_element;
  element* e;
public:
  sparse_matrix(int no_row,int no_col,int nonzero_element_no){
    row=no_row; col=no_col; no_nonzero_element=nonzero_element_no;
    e=new element[no_nonzero_element];
   }

  void setdata(int row,int col,int value){
    e->i=row;
    e->j=col;
    e->val=value;
    e++;
  }
  void showdata(){
    e=e-no_nonzero_element;
    for(int i=0;i<no_nonzero_element;i++){
      cout<<"row="<<e[i].i<<" "<<"collum="<<e[i].j<<" "<<"value="<<e[i].val<<endl;
      }
      cout<<endl;
  }
  sparse_matrix sum(sparse_matrix& m2){
    if(row==m2.row && col==m2.col){
      sparse_matrix m(row,col,no_nonzero_element+m2.no_nonzero_element);
      int i=0,j=0,k,count=0;
      for(k=0;k<no_nonzero_element+m2.no_nonzero_element;k++){
        if(e[i].i<m2.e[j].i){m.setdata(e[i].i,e[i].j,e[i].val); i++;}
        else if(m2.e[j].i<e[i].i){m.setdata(m2.e[j].i,m2.e[j].j,m2.e[j].val); j++;}
        else if(e[i].i==m2.e[j].i && e[i].j<m2.e[j].j){m.setdata(e[i].i,e[i].j,e[i].val); i++;}
        else if(e[i].i==m2.e[j].i && m2.e[j].j<e[i].j){m.setdata(m2.e[j].i,m2.e[j].j,m2.e[j].val); j++;}
        else if(e[i].i==m2.e[j].i && m2.e[j].j==e[i].j){m.setdata(m2.e[j].i,m2.e[j].j,e[i].val+m2.e[j].val);i++;j++; }
        else{}
        }

        return m;}
  }
  ~sparse_matrix(){delete[]e;}
};


int main(){
sparse_matrix m3(4,5,6);
sparse_matrix m4(4,5,4);
m3.setdata(1,3,3);
m3.setdata(2,1,4);
m3.setdata(2,5,7);
m3.setdata(3,3,5);
m3.setdata(3,5,8);
m3.setdata(4,2,6);
m3.showdata();
m4.setdata(1,5,2);
m4.setdata(2,5,6);
m4.setdata(3,1,4);
m4.setdata(4,5,4);
m4.showdata();

 sparse_matrix m5=m3.sum(m4);
    m5.showdata();

  return 0;
}
