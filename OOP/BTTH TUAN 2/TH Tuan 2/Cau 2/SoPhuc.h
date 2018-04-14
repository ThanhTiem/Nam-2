#pragma once
#include <iostream>
using namespace std;
class SoPhuc
{
private:
	int thuc;
	int ao;
public:
	SoPhuc(void);
	SoPhuc(int, int);
	SoPhuc(int);
	SoPhuc(const SoPhuc &);
	void Xuat();
	SoPhuc Cong(SoPhuc);
	SoPhuc Tru(SoPhuc);
	SoPhuc Nhan(SoPhuc);
	SoPhuc Chia(SoPhuc);
	~SoPhuc();
};

