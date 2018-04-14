#include "PhanSo.h"



PhanSo::PhanSo(void)
{
	tu = 0;
	mau = 1;
}
PhanSo::PhanSo(int ts, int ms)
{
	tu = ts;
	mau = ms;
}
PhanSo::PhanSo(int ts)
{
	tu = ts;
	mau = 1;
}
PhanSo::PhanSo(const PhanSo &ps)
{
	tu = ps.tu;
	mau = ps.mau;
}
PhanSo::~PhanSo()
{
}


int PhanSo::UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a*b != 0) {
		if (a > b)
			a = a%b;
		else
			b = b%a;
	}
	return (a + b);
}
void PhanSo::Xuat()
{
	int m = UCLN(tu, mau);
	tu = tu / m;
	mau = mau / m;
	if (tu == 1 && mau == 1) {
		cout << "1";
	}
	else {
		cout << tu << "/" << mau << endl;
	}
}
PhanSo PhanSo::RutGon()
{
	int m = UCLN(tu, mau);
	PhanSo x;
	x.tu = tu / m;
	x.mau = mau / m;
	return x;
}
PhanSo PhanSo::Tong(PhanSo ps)
{
	PhanSo Tong;
	Tong.tu = tu*ps.mau + ps.tu*mau;
	Tong.mau = mau*ps.mau;
	
	return Tong;
}
PhanSo PhanSo::Hieu(PhanSo ps)
{
	PhanSo Hieu;
	Hieu.tu = tu*ps.mau - ps.tu*mau;
	
	return Hieu;
}
PhanSo PhanSo::Tich(PhanSo ps)
{
	PhanSo Tich;
	Tich.tu = tu*ps.tu;
	Tich.mau = mau*ps.mau;
	
	return Tich;
}
PhanSo PhanSo::Thuong(PhanSo ps)
{
	PhanSo Thuong;
	Thuong.tu = tu*ps.mau;
	Thuong.mau = mau*ps.tu;
	
	return Thuong;
}