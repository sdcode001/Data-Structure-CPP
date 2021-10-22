#include<iostream>
#include<string>
#include<math.h>

int isInteger(float a){
  string s=to_string(a);
  int i=0,t=0,r=0;
  while(s[i]!='\0'){
    if(s[i]==46){t=i;break;}
    i++;}
    t++;
    while(s[t]!='\0'){
      if(s[t]!='0'){r++;}
       t++;}
      if(r==0){return 1;}
      return 0;
}
int main(){

  
  return 0;
}
