#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.1415926;

void welcome()
{
	cout<<"================"<<endl;
	cout<<"***功率计算器***"<<endl;
	cout<<"================"<<endl;
	cout<<"1.计算F:F=(gamma)*g*h*(beta)*A"<<endl;
	cout<<"单位:F:N gamma:kg/m^3(默认1800) g:m/s^2(默认9.8) h:m beta:null(默认1) A:m^2"<<endl;
	cout<<"2.计算P:P=Fv=(s*F/t)*w"<<endl;
	cout<<"单位:P:W s:m F:N t:min(默认60) w:r/min"<<endl;
	cout<<"3.计算T:T=9500*P/w"<<endl;
	cout<<"单位:T:Nm P:kW w:r/min"<<endl<<endl;
}

int main()
{
	welcome();	//打印表头 
	
	double F=0,gamma=1800,g=9.8,h=0,beta=1,fai=0,A=0;
	
	char f1;
	while(1)
	{
		cout<<"是否改变 gamma = 1800 kg/m^3 ?输入y或n并按回车:";
		cin>>f1;
		if(f1=='y'||f1=='n')break;
	}
	if(f1=='y')
	{
		while(1)
		{
			cout<<"请输入新的 gamma 值,单位 kg/m^3 :";
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
		cout<<"是否改变 g = 9.8 m/s^2 ?输入y或n并按回车:";
		cin>>f2;
		if(f2=='y'||f2=='n')break;
	}
	if(f2=='y')
	{
		while(1)
		{
			cout<<"请输入新的 g 值,单位 m/s^2 :";
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
		cout<<"请输入 h 值,单位 m :";
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
		cout<<"是否改变 beta = 1 ?输入y或n并按回车:";
		cin>>f3;
		if(f3=='y'||f3=='n')break;
	}
	if(f3=='y')
	{
		cout<<"计算公式:beta = tan(fai)"<<endl;
		while(1)
		{
			cout<<"请输入土壤内摩擦角 fai 值,单位角度:";
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
		cout<<"请输入 A 值,单位 m^2 :";
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
	cout<<"计算结果: F = "<<setprecision(10)<<F<<" N"<<endl;
	cout<<"================"<<endl<<endl;
	
	double P=0,s=0,t=60,w=0;
	
	while(1)
	{
		cout<<"请输入 s 值,单位 m :";
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
		cout<<"是否改变 t = 60 min ?输入y或n并按回车:";
		cin>>f4;
		if(f4=='y'||f4=='n')break;
	}
	if(f4=='y')
	{
		while(1)
		{
			cout<<"请输入新的 t 值,单位 min :";
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
		cout<<"请输入 w 值,单位 r/min :";
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
	cout<<"计算结果: P = "<<setprecision(10)<<P<<" W = "<<P/1000<<" kW"<<endl;
	cout<<"计算结果: T = "<<setprecision(10)<<T<<" Nm"<<endl;
	cout<<"================"<<endl;
	cout<<"结束";
	system("pause");
	
	return 0;
}

