#include<iostream>
#include<string.h>
#include<string>
using namespace std;
void Substring(string str){
 for(int i=1;i<str.size();i++)
  for(int j=1;j<=((str.substr(i)).size());j++)  //可百度substr()函数的用法和参数意义 
      //判断的条件是第i个字符往后最大的子串长度 
   //cout<<i<<" "<<j<<endl,    输出截取的开始字符的下标和截取长度 
   cout<<str.substr(i,j)<<endl;  //输出子串，包括原字符串 
}
int main(){
 string str;
 cin>>str;
 Substring(str);
 return 0;
}

