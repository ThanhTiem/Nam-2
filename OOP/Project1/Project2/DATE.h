#pragma once
#include <iostream>
using namespace std;

const int Month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
struct DATE {
	int ngay;
	int thang;
	int nam;
};

void Nhap(DATE &t, int i) {
	cout << "\nNhap ngay: ";
	cin >> t.ngay;
	do {
		cout << "\nNhap thang: ";
		cin >> t.thang;
		if (t.thang <= 0 || t.thang > 12)
			cout << "\nThang khong hop le! vui long nhap lai.";
	} while (t.thang <= 0 || t.thang > 12);
	do {
		cout << "\nNhap vao nam: ";
		cin >> t.nam;
		if (t.nam <= 0)
			cout << "\nNam nhap khong hop le! vui long nhap lai.";
	} while (t.nam <= 0);
}
void Xuat(DATE t, int i) {

	cout << t.ngay << " / " << t.thang << " / " << t.nam;
}
int Check_Nhuan(int nam) {
	return((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) ? 1 : 0;
}
void CheckDay(DATE t)
{
	int x;
	do
	{
		switch (t.thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			x = 31;
			break;
		case 4: case 6: case 9: case 11:
			x = 30;
			break;
		case 2:
			if ((t.nam % 4 == 0 && t.nam % 100 != 0) || (t.nam % 400 == 0))
				x = 29;
			else
				x = 28;
			break;
		default: x = 0;
		}
		if (x == 0 || t.ngay <= 0 || t.ngay > x)
			cout << "\nngay khong hop le! vui long nhap lai. " << endl;
	} while (x == 0 || t.ngay <= 0 || t.ngay > x);
}

int SoNgayCuaThang(int th, int nm) {
	if (th == 2) return(28 + Check_Nhuan(nm));
	return Month[th + 1];
}

long TongNgay(DATE t) {
	long Tong = 0;
	int i;
	for (i = 0; i < t.nam; i++) {
		Tong += 365 + Check_Nhuan(i);
	}
	for (i = 0; i < t.thang; i++) {
		Tong += SoNgayCuaThang(i, t.nam);
	}
	Tong += t.ngay;
	return Tong;
}
long KhoangCach(DATE t1, DATE t2) {
	return abs((TongNgay(t1) - TongNgay(t2)));
}
