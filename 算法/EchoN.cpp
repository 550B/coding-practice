#include<iostream>
#include<string>
using namespace std;
int cmpStr(string str){
 if(str.size()==0||str.size()==1)return str.size();
 int cnt=0;
 for(int i=1;i<str.size();i++){
 	if(str[i]!=str[0])continue;
  for(int j=1;j<=((str.substr(i)).size());j++){
   if(str.compare(0,j,str.substr(i,j))==0){
 	 cnt++;
    }
  }
 }
  return cnt+str.size();
}
int main()
{
	string str;
	cin>>str;
	cout<<cmpStr(str)<<endl;
	return 0;
}
