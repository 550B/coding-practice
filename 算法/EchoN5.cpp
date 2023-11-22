#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,short>m;
int cmpStr(string str){
	if(str.size()==0||str.size()==1)return str.size();
	for(int i=0;i<str.size();i++)
		for(int j=1;j<=((str.substr(i)).size());j++)
   			m[str.substr(i,j)]++;
	int cnt=0;
	for(int i=1;i<str.size();i++){
		cnt+=m.count(str.substr(0,i));
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
