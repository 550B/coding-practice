#include<iostream>
#include<string.h>
#include<string>
using namespace std;
void Substring(string str){
 for(int i=1;i<str.size();i++)
  for(int j=1;j<=((str.substr(i)).size());j++)  //�ɰٶ�substr()�������÷��Ͳ������� 
      //�жϵ������ǵ�i���ַ����������Ӵ����� 
   //cout<<i<<" "<<j<<endl,    �����ȡ�Ŀ�ʼ�ַ����±�ͽ�ȡ���� 
   cout<<str.substr(i,j)<<endl;  //����Ӵ�������ԭ�ַ��� 
}
int main(){
 string str;
 cin>>str;
 Substring(str);
 return 0;
}

