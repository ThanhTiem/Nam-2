#include <iostream>
using namespace std;

struct DATE
{
	int ngay, thang, nam;
};
int Check_Nhuan(int n)
{
	return ((n % 100 != 0 && n % 4 == 0) || (n % 400 == 0)) ? 1 : 0;
}

void Nhap(DATE &d)
{
	while (d.nam <= 0)
	{
		cout << "Nhap nam : ";
		cin >> d.nam;
		if (d.nam <= 0)
			cout << "Nhap sai! Nhap lai !!" << endl;
	}
	while (d.thang <= 0 || d.thang > 12)
	{
		cout << "Nhap thang :";
		cin >> d.thang;
		if (d.thang <= 0 || d.thang > 12)
			cout << "Nhap sai! Nhap lai !!" << endl;
	}
	switch (d.thang) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		while (d.ngay <= 0 || d.ngay > 31)
		{
			cout << "Nhap ngay : ";
			cin >> d.ngay;
			if (d.ngay <= 0 || d.ngay > 31)
				cout << "Nhap sai! Nhap lai !!" << endl;
		}
		break;
	}
	case 4: case 6: case 9: case 11:
	{

		while (d.ngay <= 0 || d.ngay > 30)
		{
			cout << "Nhap ngay : ";
			cin >> d.ngay;
			if (d.ngay <= 0 || d.ngay > 30)
				cout << "Nhap sai! Nhap lai !!" << endl;
		}
		break;
	}
	case 2:
	{
		if (Check_Nhuan(d.nam) == 1) {
			while (d.ngay <= 0 || d.ngay > 29)
			{
				cout << "Nhap ngay : ";
				cin >> d.ngay;
				if (d.ngay <= 0 || d.ngay > 29)
					cout << "Nhap sai! Nhap lai !!" << endl;
			}
		}
		else {
			while ((d.ngay <= 0 || d.ngay > 28))
			{
				cout << "Nhap ngay : ";
				cin >> d.ngay;
				if (d.ngay <= 0 || d.ngay > 28)
					cout << "Nhap sai! Nhap lai !!" << endl;
			}
		}
	}
	}
}
void Xuat(DATE d)
{
	cout << d.ngay << "/" << d.thang << "/" << d.nam;
 }
void NgayKeTiep(DATE &d)
{
	if (Check_Nhuan(d.nam) == 1) {
		if (d.thang == 2) {
			if (d.ngay == 29) {
				d.ngay = 1;
				d.thang = 3;
			}
		}
	}
	else {
		if (d.thang == 2) {
			if (d.ngay == 28) {
				d.ngay = 1;
				d.thang = 3;
			}
		}
	}
	if (d.thang == 1, d.thang == 3, d.thang == 5, d.thang == 7, d.thang == 8, d.thang == 10) {
		if (d.ngay == 31) {
			d.ngay = 1;
			d.thang = d.thang + 1;
		}
	}
	if (d.thang == 4, d.thang == 9, d.thang == 11) {
		if (d.ngay == 30) {
			d.ngay = 1;
			d.thang = d.thang + 1;
		}
	}
	if (d.thang == 12) {
		if (d.ngay == 31) {
			d.ngay = 1;
			d.thang = 1;
			d.nam = d.nam + 1;
		}
	}
}

int main()
{
	DATE d;
	Nhap(d);
	Xuat(d);
	cout << "\nNgay tiep theo la: ";
	NgayKeTiep(d);
	Xuat(d);
	system("pause");
	return 0;
}