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

void XuatPS(PHANSO ps)
{
	int a = UCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / a;
	ps.mau = ps.mau / a;
	if (ps.mau > 0) {
		cout << "\nPhan so: " << ps.tu << "/" << ps.mau;
	}
	if ((ps.tu > 0 && ps.mau < 0) || (ps.tu < 0 && ps.mau < 0)) {
		cout << "\nPhan so: " << -1 * ps.tu << "/" << -1 * ps.mau;
	}
}
void SoSanh(PHANSO pa, PHANSO pb)
{
	if ((float)pa.tu / pa.mau > (float)pb.tu / pb.mau) {
		cout << "\nPhan so " << pa.tu << "/" << pa.mau << " lon hon!";
	}
	else {
		if ((float)pa.tu / pa.mau == (float)pb.tu / pb.mau){
			cout << "\nHai phan so bang nhau!";
		}
		else
			cout << "\nPhan so " << pb.tu << "/" << pb.mau << " lon hon!";
	}
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
	SoSanh(ps1, ps2);

	system("pause");
	return 0;
}
