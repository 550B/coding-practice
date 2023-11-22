#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.1415926;

void welcome()
{
	cout<<"================"<<endl;
	cout<<"***���ʼ�����***"<<endl;
	cout<<"================"<<endl;
	cout<<"1.����F:F=(gamma)*g*h*(beta)*A"<<endl;
	cout<<"��λ:F:N gamma:kg/m^3(Ĭ��1800) g:m/s^2(Ĭ��9.8) h:m beta:null(Ĭ��1) A:m^2"<<endl;
	cout<<"2.����P:P=Fv=(s*F/t)*w"<<endl;
	cout<<"��λ:P:W s:m F:N t:min(Ĭ��60) w:r/min"<<endl;
	cout<<"3.����T:T=9500*P/w"<<endl;
	cout<<"��λ:T:Nm P:kW w:r/min"<<endl<<endl;
}

int main()
{
	welcome();	//��ӡ��ͷ 
	
	double F=0,gamma=1800,g=9.8,h=0,beta=1,fai=0,A=0;
	
	char f1;
	while(1)
	{
		cout<<"�Ƿ�ı� gamma = 1800 kg/m^3 ?����y��n�����س�:";
		cin>>f1;
		if(f1=='y'||f1=='n')break;
	}
	if(f1=='y')
	{
		while(1)
		{
			cout<<"�������µ� gamma ֵ,��λ kg/m^3 :";
			cin>>gamma;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore();
			}
			else break;
		}
	}
	cout<<"gamma = "<<gamma<<" kg/m^3"<<endl<<endl;
	
	char f2;
	while(1)
	{
		cout<<"�Ƿ�ı� g = 9.8 m/s^2 ?����y��n�����س�:";
		cin>>f2;
		if(f2=='y'||f2=='n')break;
	}
	if(f2=='y')
	{
		while(1)
		{
			cout<<"�������µ� g ֵ,��λ m/s^2 :";
			cin>>g;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore();
			}
			else break;
		}
	}
	cout<<"g = "<<g<<" m/s^2"<<endl<<endl;
	
	while(1)
	{
		cout<<"������ h ֵ,��λ m :";
		cin>>h;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else break;
	}
	cout<<"h = "<<h<<" m"<<endl<<endl;
	
	char f3;
	while(1)
	{
		cout<<"�Ƿ�ı� beta = 1 ?����y��n�����س�:";
		cin>>f3;
		if(f3=='y'||f3=='n')break;
	}
	if(f3=='y')
	{
		cout<<"���㹫ʽ:beta = tan(fai)"<<endl;
		while(1)
		{
			cout<<"������������Ħ���� fai ֵ,��λ�Ƕ�:";
			cin>>fai;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore();
			}
			else break;
		}
		beta = tan(fai*PI/180);
	}
	cout<<"beta = "<<beta<<" "<<endl<<endl;
	
	while(1)
	{
		cout<<"������ A ֵ,��λ m^2 :";
		cin>>A;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else break;
	}
	cout<<"A = "<<h<<" m^2"<<endl<<endl;
	
	F=gamma*g*h*beta*A;
	cout<<"================"<<endl;
	cout<<"������: F = "<<setprecision(10)<<F<<" N"<<endl;
	cout<<"================"<<endl<<endl;
	
	double P=0,s=0,t=60,w=0;
	
	while(1)
	{
		cout<<"������ s ֵ,��λ m :";
		cin>>s;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else break;
	}
	cout<<"s = "<<s<<" m"<<endl<<endl;
	
	char f4;
	while(1)
	{
		cout<<"�Ƿ�ı� t = 60 min ?����y��n�����س�:";
		cin>>f4;
		if(f4=='y'||f4=='n')break;
	}
	if(f4=='y')
	{
		while(1)
		{
			cout<<"�������µ� t ֵ,��λ min :";
			cin>>t;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore();
			}
			else break;
		}
	}
	cout<<"t = "<<t<<" min"<<endl<<endl;
	
	while(1)
	{
		cout<<"������ w ֵ,��λ r/min :";
		cin>>w;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else break;
	}
	cout<<"w = "<<w<<" r/min"<<endl<<endl;
	
	P = w*s*F/t;
	double T = 9550*P/1000/w;
	cout<<"================"<<endl;
	cout<<"������: P = "<<setprecision(10)<<P<<" W = "<<P/1000<<" kW"<<endl;
	cout<<"������: T = "<<setprecision(10)<<T<<" Nm"<<endl;
	cout<<"================"<<endl;
	cout<<"����";
	system("pause");
	
	return 0;
}

