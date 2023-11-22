#include <stdio.h>
int main(){
	int sum=0;
	int tmp;
	for(int i=0;i<7;i++){
		scanf("%d",&tmp);
		sum+=tmp;
	}
	if(sum>0){
		printf("IMissYou!\n%d",sum);
	}
	else{
		printf("OvO");
	}
	return 0;
}
