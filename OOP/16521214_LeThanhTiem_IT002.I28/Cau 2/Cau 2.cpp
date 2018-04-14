#include <iostream>
#include "DATE.h"
#include<string>
using namespace std;

struct NVSX {
	int LuongCB, SoSP;
	string HoTen;
	struct DATE t;
};

struct NVVP {
	int SoNgayLV;
	string HoTen;
	struct DATE t;
 };
void NhapNVSX(NVSX sx[1000],int &n) {
	cout << "\nNhap so luong NVSX can nhap: ";
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cout << "\nNhap thong tin  thu: " << i + 1;
		cout << "\nNhap ho ten: ";
		cin.ignore();
		getline(std::cin, sx[i].HoTen);
		
		Nhap(sx[i].t, i);
		cout << "\nNhap luong co ban: ";
		cin >> sx[i].LuongCB;
		cout << "\nNhap so san pham: ";
		cin >> sx[i].SoSP;
	}

}
void  NhapNVVP(NVVP vp[1000], int &m) {
	cout << "\nNhap so luong NVVP can nhap: ";
	cin >> m;
	for (int i = 0; i < m; i++) {
		cout << "\nNhap thong tin  thu: " << i + 1;
		cout << "\nNhap ho ten: ";
		cin.ignore();
		getline(std::cin, vp[i].HoTen);
		Nhap(vp[i].t, i);
		cout << "\nNhap So ngay lam viec: ";
		cin >> vp[i].SoNgayLV;
	}
}
int TinhLuongNVSX(NVSX sx) {
	return (sx.LuongCB + sx.SoSP * 5000);
}
int TinhLuongNVVP(NVVP vp) {
	return(vp.SoNgayLV * 100000);
}



void XuatNVSX(NVSX sx[1000], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\nTen: " << sx[i].HoTen;
		cout << "\nNgay sinh: ";
		Xuat(sx[i].t,i);
		cout << "\nLuong can ban: " << sx[i].LuongCB;
		cout << "\nSo san pham: " << sx[i].SoSP;
	}
}
void XuatNVVP(NVVP vp[1000], int m) {
	for (int i = 0; i < m; i++)
	{
		cout << "\nTen: " << vp[i].HoTen;
		cout << "\nNgay sinh: " ;
		Xuat(vp[i].t, i);
		cout << "\nSo ngay lam viec: "<<vp->SoNgayLV;

	}

}
int TongLuong(NVSX sx[], NVVP vp[], int n, int m) {
	int sum=0;
	for (int i = 0; i <n; i++)
	{
		sum += TinhLuongNVSX(sx[i]);
	}
	for (int i = 0; i <m; i++)
	{
		sum += TinhLuongNVVP(vp[i]);
	}
	return sum;
}
void SapXepSX(NVSX sx[], int n) {
	int i, j;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (sx[j].t.nam > sx[j + 1].t.nam)
				swap(sx[j], sx[j + 1]);
			else if (sx[j].t.nam == sx[j + 1].t.nam)
			{
				if (sx[j].t.thang > sx[j + 1].t.thang)
					swap(sx[j], sx[j + 1]);
				if (sx[j].t.thang == sx[j + 1].t.thang)
				{
					if (sx[j].t.ngay > sx[j + 1].t.ngay)
						swap(sx[j], sx[j + 1]);
				}
			}

		}
	}

	XuatNVSX(sx, n);
}
void SapXepVP(NVVP vp[], int n) {
	int i, j;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (vp[j].t.nam > vp[j + 1].t.nam)
				swap(vp[j], vp[j + 1]);
			else if (vp[j].t.nam == vp[j + 1].t.nam)
			{
				if (vp[j].t.thang > vp[j + 1].t.thang)
					swap(vp[j], vp[j + 1]);
				if (vp[j].t.thang == vp[j + 1].t.thang)
				{
					if (vp[j].t.ngay > vp[j + 1].t.ngay)
						swap(vp[j], vp[j + 1]);
				}
			}

		}
	}

	XuatNVVP(vp, n);
}
void NgayGanNhatNVSX(NVSX sx[], int n) {

	long a[1000]; int k = 0; DATE t1;
	t1.ngay = 23; t1.thang = 1; t1.nam = 2018;
	long tam = KhoangCach(sx[0].t, t1);
	for (int j = 1; j < n - 1; j++)
	{

		if (KhoangCach(sx[j].t, t1) < tam)
			k = j;
	}
	cout << "\nngay gan nhat cua NVSX la \n";
	cout << "\nTen: " << sx[k].HoTen;
	cout << "\nNgay sinh: ";
	Xuat(sx[k].t, k);
	cout << "\nLuong can ban: " << sx[k].LuongCB;
	cout << "\nSo san pham: " << sx[k].SoSP;
	cout << endl;
	cout << "----------";
}
void NgayGanNhatNVVP(NVVP vp[], int m) {

	long a[1000]; int k = 0; DATE t1;
	t1.ngay = 23; t1.thang = 1; t1.nam = 2018;
	long tam = KhoangCach(vp[0].t, t1);
	for (int j = 1; j < m - 1; j++)
	{

		if (KhoangCach(vp[j].t, t1) < tam)
			k = j;
	}
	cout << "\nngay gan nhat cua NVVP la \n";
	cout << "\nTen: " << vp[k].HoTen;
	cout << "\nNgay sinh: ";
	Xuat(vp[k].t, k);
	cout << "\nSo ngay lam viec: " << vp->SoNgayLV;
}
int main()
{
	int n, m;
	NVSX sx[1000];
	NVVP vp[1000];
	NhapNVSX(sx,n);
	NhapNVVP(vp, m);
	XuatNVSX(sx,n);
	XuatNVVP(vp,m);
	cout << "\nTong so luong la: ";
	int a = TongLuong(sx,vp,n,m);
	cout <<endl<< a;
	cout << "\nSap xep: ";
	SapXepSX(sx, n);
	SapXepVP(vp, n);
	NgayGanNhatNVSX(sx, n);
	NgayGanNhatNVVP(vp, m);
	system("pause");
	return 0;
}