#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
/*
int rand(void),����������ķ�Χ��0~65536�� ����Ϊunsigned int ,
���ܳ�����Χ��rand()���������ܲ����� Ĭ����1Ϊ����(����ʼֵ)��
�������������������ͬ�����ӿ�ʼ�������γɵ�α�������Ҳ��ͬ��ʧȥ��
��������塣��Ҫ��ͬ����ʱ��Ҫʹ�ú���srand()������������趨��
srand()����������ʼ����������������÷�Ϊ void srand(unsigned int seed), 
����seed�����Ǹ����������ÿ��seed������ֵͬ��rand()�������������ֵ����ͬ��
��������srand((unsigned int)(time(NULL))�ķ�����������ͬ��������ӣ���Ϊÿ��
���г����ʱ���ǲ�ͬ��
*/

int main()
{
	srand((unsigned int)time(NULL));	//�������������

	int a = 0; int b = 9;
	int n = 9;
	for (int i = 0; i != 10; ++i)
	{
		//ȡ��[a,b)�������
		cout << (rand() % (b - a)) + a << " ";

		//ȡ��[a,b]�������
		cout << (rand() % (b - a + 1)) + a << " ";

		//ȡ��(a,b]�������
		cout << (rand() % (b - a)) + a + 1 << " ";

		//��ʼֵa,n������Χ
		cout << a + rand() % n << " ";
		
		//Ҫȡ��0~1֮������������
		cout << rand() / double(RAND_MAX);
	}

	cout << endl;

	return 0;


}