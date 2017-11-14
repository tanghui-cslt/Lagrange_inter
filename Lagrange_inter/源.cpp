#include <iostream>
#include <iomanip>
#define ERROR 1e-11
using namespace std;

void scanf_data(double ** &A, double &x, int &n);
void solution(double **A, double x, const int n);

int main()
{
	double **A = NULL, x = 0;
	int n = 0;

	scanf_data(A, x, n);

	solution(A, x, n);

	getchar();
	getchar();
	return 0;
}

void solution(double **A, double x, const int n)
{
	double sum = 0;
	for (size_t i = 0; i < n; i++)
	{

		double tempX_mulit = 1.0;
		double tempY_mulit = 1.0;
		for (size_t k = 0; k < n; k++)
		{
			if (k != i)
			{
				tempX_mulit *= (x - A[k][0]);
				tempY_mulit *= (A[i][0] - A[k][0]);
			}

		}
		sum += A[i][1] * (tempX_mulit / tempY_mulit);


	}
	cout << "结果是：\n";
	cout << "sum = " << sum;
}
void scanf_data(double ** &A, double &x, int &n)
{
	cout << "********请输入数值的个数:**********\n";
	cin >> n;

	A = new double *[n];

	cout << "********请输入" << n << "组x,y:**********\n";
	for (size_t i = 0; i < n; i++)
	{
		A[i] = new double[2];
		for (size_t j = 0; j < 2; j++)
		{
			cin >> A[i][j];
			//A[i][j] = 1.0/(i+1+j+1);
		}
	}

	cout << "********需要计算的x的值**********\n";
	cin >> x;
}
