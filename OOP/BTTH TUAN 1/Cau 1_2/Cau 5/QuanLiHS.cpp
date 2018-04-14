#include <iostream>
#include <string>
using namespace std;
struct HOCSINH
{
	float toan, van;
	string ten;
 };
void Nhap(HOCSINH &hs)
{
	
	cout << "\nNhap ho ten: ";
	getline(cin, hs.ten);
	do {
		cout << "\nNhap diem toan: ";
		cin >> hs.toan;
		if (hs.toan < 0 || hs.toan>10)
			cout << "\nDiem khong hop le! Nhap lai!";
	} while (hs.toan<0||hs.toan>10);
	do {
		cout << "\nNhap diem van: ";
		cin >> hs.van;
		if (hs.van < 0 || hs.van>10)
			cout << "\nDiem khong hop le! nhap lai!";
	} while (hs.van < 0 || hs.van>10);
}
void Xuat(HOCSINH hs)
{
	cout << "------Thong tin hoc sinh:---------";
	cout << "\nHo ten: " << hs.ten;
	cout << "\nDiem toan: " << hs.toan;
	cout << "\nDiem van: " << hs.van;
	cout << "\nDiem trung binh: " << (float)(hs.toan + hs.van) / 2;
}

int main()
{
	HOCSINH hs;
	Nhap(hs);
	Xuat(hs);
	system("pause");
	return 0;
}