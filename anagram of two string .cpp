#include<iostream>
using namespace std;
int isAnagram(string s1,string s2){
  // creating hash table;
  int h[26];
  for(int i=0;i<26;i++){h[i]=0;}
  if(s1.length()==s2.length()){
    for(int i=0;i<s1.length();i++){h[s1[i]-93]++;}
    for(int i=0;i<s2.length();i++){h[s2[i]-93]--;}
    int x=0;
    for(int i=0;i<26;i++){if(h[i]!=0){x++;}}
    if(x==0){return 1;}
  }
  return 0;
}
int main(){
string a="decimal";
string b="medical";
// if strings are anagram,return 1. otherwise return 0.
cout<<isAnagram(a,b);
  return 0;
}
