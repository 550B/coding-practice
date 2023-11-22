#include<iostream>
#include<string>
#include<queue>
using namespace std;
int cmpStr(string str){
	if(str.size()==0||str.size()==1)return str.size();
	int cnt=0;
	int qsize=0;
	queue<int> q;
	for(int i=0;i<str.size();i++){
		q.push(i);
	}
	qsize=q.size();
	cnt+=qsize;
	q.pop();
	
	for(int i=0;i<str.size();i++){
		while(qsize--){
			if(str[i]==str[q.front()+i]){
				q.push(q.front());
			}
			q.pop();
		}
		qsize=q.size();
		cnt+=qsize;
	}
	return cnt;
}
int main()
{
	string str;
	cin>>str;
	cout<<cmpStr(str)<<endl;
	return 0;
}
