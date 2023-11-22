semaphore mutex1=1;			//缓冲区1互斥信号量
semaphore mutex2=1;			//缓冲区2互斥信号量
semaphore empty1=1;			//缓冲区1空
semaphore full1=0;			//缓冲区1初始化空
semaphore empty2=1;			//缓冲区2空
semaphore full2=0;			//缓冲区2初始化空
pa()
{
	while(1)
	{
		read;				//读文件
		P(empty1);			//获取空缓冲区1
		P(mutex1);			//进入临界区1
		add;				//数据放入缓冲区
		V(mutex1);			//退出临界区1
		V(full1);			//缓冲区1满 
	}
}
pb()
{
	while(1)
	{
		P(full1);			//获取满缓冲区1
		P(mutex1);			//进入临界区1
		remove;				//从缓冲区中取数据
		V(mutex1);			//退出临界区1
		V(empty1);			//缓冲区1空
		P(empty2);			//获取空缓冲区2
		P(mutex2);			//进入临界区2
		add;				//数据放入缓冲区
		V(mutex2);			//退出临界区2
		V(full2);			//缓冲区2满 
	}
}
pc()
{
	while(1)
	{
		P(full2);			//获取满缓冲区2
		P(mutex2);			//进入临界区2
		remove;				//从缓冲区中取数据
		V(mutex2);			//退出临界区2
		V(empty2);			//缓冲区2空
		print;				//打印 
	}
}
