#include "PhanSo.h"
 
int main()
{
	PhanSo a(4, 6), b(3, 5);
	a.Xuat();
	b.Xuat();
	cout << "\nTong la: ";
	PhanSo tong = a.Tong(b);
	tong.Xuat();
	cout << "\nHieu la: ";
	PhanSo hieu = a.Hieu(b);
	hieu.Xuat();
	cout << "\nTich la: ";
	PhanSo tich = a.Tich(b);
	tich.Xuat();
	cout << "\nThuong la: ";
	PhanSo thuong = a.Thuong(b);
	thuong.Xuat();
	system("pause");
	return 0;
}