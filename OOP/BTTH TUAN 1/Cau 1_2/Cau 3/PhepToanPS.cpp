#include <iostream>

using namespace std;

struct PHANSO
{
	int tu;
	int mau;
};
void NhapPS(PHANSO &ps)
{
	cout << "\nNhap vao tu: ";
	cin >> ps.tu;
	do {
		cout << "\nNhap vao mau: ";
		cin >> ps.mau;
		if (ps.mau == 0)
			cout << "\nMau khong hop le! nhap lai! ";
	} while (ps.mau == 0);
}
int UCLN(int a, int b)
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
void RutGon(PHANSO ps)
{
	int a = UCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / a;
	ps.mau = ps.mau / a;
}
void XuatPS(PHANSO ps)
{
	int a = UCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / a;
	ps.mau = ps.mau / a;
	if (ps.mau>0) {
		cout << "\nPhan so: " << ps.tu << "/" << ps.mau;
	}
	if ((ps.tu > 0 && ps.mau < 0) || (ps.tu<0 && ps.mau<0)) {
		cout << "\nPhan so: " << -1 * ps.tu << "/" << -1 * ps.mau;
	}
}
void Tong(PHANSO pa, PHANSO pb)
{
	PHANSO Tong;
	Tong.tu = pa.tu*pb.mau + pb.tu*pa.mau;
	Tong.mau = pa.mau*pb.mau;
	XuatPS(Tong);
}
void Hieu(PHANSO pa, PHANSO pb)
{
	PHANSO Hieu;
	Hieu.tu = pa.tu*pb.mau - pb.tu*pa.mau;
	Hieu.mau = pa.mau*pb.mau;
	XuatPS(Hieu);
}
void Tich(PHANSO pa, PHANSO pb)
{
	PHANSO Tich;
	Tich.tu = pa.tu*pb.tu;
	Tich.mau = pa.mau*pb.mau;
	XuatPS(Tich);
	
}
void Thuong(PHANSO pa, PHANSO pb)
{
	PHANSO Thuong;
	Thuong.tu = pa.tu*pb.mau;
	Thuong.mau = pa.mau*pb.tu;
	XuatPS(Thuong);
}

int main()
{
	PHANSO ps1, ps2;
	cout << "\nNhap vao phan so thu 1:";
	NhapPS(ps1);
	XuatPS(ps1);
	cout << "\nNhap vao phan so thu 2:";
	NhapPS(ps2);
	XuatPS(ps2);
	cout << "\nTong la:";
	Tong(ps1, ps2);
	cout << "\nHieu la: ";
	Hieu(ps1, ps2);
	cout << "\nTich la: ";
	Tich(ps1, ps2);
	cout << "\nThuong la: ";
	Thuong(ps1, ps2);

	system("pause");
	return 0;
}
