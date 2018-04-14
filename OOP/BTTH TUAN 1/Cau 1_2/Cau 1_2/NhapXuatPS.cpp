#include <iostream>

using namespace std;

struct PHANSO 
{
	int tu;
	int mau;
};
 void NhapPS (PHANSO &ps)
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
	 if (ps.mau>0) {
		 cout << "\nPhan so: " << ps.tu << "/" << ps.mau;
	 }
	 if ((ps.tu > 0 && ps.mau < 0)||(ps.tu<0 && ps.mau<0)) {
		 cout << "\nPhan so: " << -1 * ps.tu << "/" << -1 * ps.mau;
	 }
 }
 
 
 int main()
 {
	 PHANSO ps;
	 NhapPS(ps);
	 XuatPS(ps);
	 system("pause");
	 return 0;
 }
