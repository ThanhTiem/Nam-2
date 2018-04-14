#include "SoPhuc.h"

int main()
{
	SoPhuc a(3, 5), b(4, 0);
	a.Xuat();
	cout << endl;
	b.Xuat();
	cout << "\nTong la: ";
	SoPhuc tong = a.Cong(b);
	tong.Xuat();
	cout << "\nHieu la: ";
	SoPhuc hieu = a.Tru(b);
	hieu.Xuat();
	cout << "\nTich la: ";
	SoPhuc tich = a.Nhan(b);
	tich.Xuat();
	cout << "\nThuong la: ";
	SoPhuc thuong = a.Chia(b);
	thuong.Xuat();
	system("pause");
	return 0;
}