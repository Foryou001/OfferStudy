#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
/*
int rand(void),产生随机数的范围是0~65536， 类型为unsigned int ,
不能超过范围，rand()函数不接受参数， 默认以1为种子(即起始值)。
随机数产生器总是以相同的种子开始，所以形成的伪随机数列也行同，失去了
随机的意义。若要不同，此时需要使用函数srand()进行随机种子设定。
srand()函数用来初始化随机数发生器，用法为 void srand(unsigned int seed), 
参数seed必须是个整数，如果每次seed都设相同值，rand()所产生的随机数值都相同。
可以利用srand((unsigned int)(time(NULL))的方法，产生不同的随机种子，因为每次
运行程序的时间是不同的
*/

int main()
{
	srand((unsigned int)time(NULL));	//设置随机数种子

	int a = 0; int b = 9;
	int n = 9;
	for (int i = 0; i != 10; ++i)
	{
		//取得[a,b)的随机数
		cout << (rand() % (b - a)) + a << " ";

		//取得[a,b]的随机数
		cout << (rand() % (b - a + 1)) + a << " ";

		//取得(a,b]的随机数
		cout << (rand() % (b - a)) + a + 1 << " ";

		//起始值a,n整数范围
		cout << a + rand() % n << " ";
		
		//要取得0~1之间的随机浮点数
		cout << rand() / double(RAND_MAX);
	}

	cout << endl;

	return 0;


}