#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  double tmp;
  double res=0,sum=0;
  cin>>n;
  vector<double> s(n);
  for(int i=0;i<n;i++){
    cin>>tmp;
    s.push_back(tmp);
  }
  sort(s.begin(),s.end(),greater<double>());
  sum=s[0]+s[1];
  for(int i=2;i<=n;i++){
    res+=sum;
    sum+=s[i];
  }
  cout<<res;
  return 0;
}
