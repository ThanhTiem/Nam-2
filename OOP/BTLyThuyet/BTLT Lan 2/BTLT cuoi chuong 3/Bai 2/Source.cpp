#include <iostream>
using namespace std;
#define max 50
int n;
class vector
{
public:
	float v[max];
	vector()
	{
		for (int i = 1; i <= n; i++)
		{
			v[i] = 0;
		}
	}
	void nhapsl()
	{
		for (int i = 1; i <= n; i++)
		{
			cout << "v[" << i << "]: ";
			cin >> v[i];
		}
	}
	void insl()
	{
		for (int i = 1; i <= n; i++)
		{
			cout << " " << v[i];
		}
		cout << endl;
	}
};
vector cong(vector a, vector b)
{
	vector c;
	for (int i = 1; i <= n; i++)
	{
		c.v[i] += a.v[i] + b.v[i];
	}
	return c;
}
vector hieu(vector a, vector b)
{
	vector c;
	for (int i = 1; i <= n; i++)
	{
		c.v[i] += a.v[i] - b.v[i];
	}
	return c;
}
vector nhan(vector a, vector b)
{
	vector c;
	for (int i = 1; i <= n; i++)
	{
		c.v[i] += a.v[i] * b.v[i];
	}
	return c;
}

int main()
{
	vector a, b, d;
	cout << "Nhap so phan tu cua vector a : "; cin >> n;
	cout << "Nhap vector a : \n";
	a.nhapsl();
	cout << "\nNhap vector b : \n";
	b.nhapsl();
	cout << "\nVector a: ";
	a.insl();
	cout << "Vector b: ";
	b.insl();
	d = cong(a, b);
	cout << "Tong 2 vector: ";
	d.insl();
	d = hieu(a, b);
	cout << "Hieu 2 vector: ";
	d.insl();
	d = nhan(a, b);
	cout << "Nhan 2 vector: ";
	d.insl();
	system("pause");
	return 0;
}
