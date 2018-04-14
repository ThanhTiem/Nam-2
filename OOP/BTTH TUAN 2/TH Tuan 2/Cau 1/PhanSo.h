#pragma once
#include <iostream>
using namespace std;

class PhanSo
{
private:
	int tu, mau;
public:
	PhanSo(void); //Mac dinh
	PhanSo(int, int); // 2 Tham so 
	PhanSo(int); //1 tham so
	PhanSo(const PhanSo &); //sao chep
	~PhanSo();
	int UCLN(int , int );
	PhanSo RutGon();
	void Xuat();
	PhanSo Tong(PhanSo);
	PhanSo Hieu(PhanSo);
	PhanSo Tich(PhanSo);
	PhanSo Thuong(PhanSo);

};

