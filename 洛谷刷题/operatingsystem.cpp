semaphore mutex1=1;			//������1�����ź���
semaphore mutex2=1;			//������2�����ź���
semaphore empty1=1;			//������1��
semaphore full1=0;			//������1��ʼ����
semaphore empty2=1;			//������2��
semaphore full2=0;			//������2��ʼ����
pa()
{
	while(1)
	{
		read;				//���ļ�
		P(empty1);			//��ȡ�ջ�����1
		P(mutex1);			//�����ٽ���1
		add;				//���ݷ��뻺����
		V(mutex1);			//�˳��ٽ���1
		V(full1);			//������1�� 
	}
}
pb()
{
	while(1)
	{
		P(full1);			//��ȡ��������1
		P(mutex1);			//�����ٽ���1
		remove;				//�ӻ�������ȡ����
		V(mutex1);			//�˳��ٽ���1
		V(empty1);			//������1��
		P(empty2);			//��ȡ�ջ�����2
		P(mutex2);			//�����ٽ���2
		add;				//���ݷ��뻺����
		V(mutex2);			//�˳��ٽ���2
		V(full2);			//������2�� 
	}
}
pc()
{
	while(1)
	{
		P(full2);			//��ȡ��������2
		P(mutex2);			//�����ٽ���2
		remove;				//�ӻ�������ȡ����
		V(mutex2);			//�˳��ٽ���2
		V(empty2);			//������2��
		print;				//��ӡ 
	}
}
