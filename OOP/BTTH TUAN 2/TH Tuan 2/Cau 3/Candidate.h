#pragma once
#include "Day.h"
using namespace std;

class Candidate
{
private: 

	char ten[50];
	int ma;
	float toan, van, anh;
	Day NgaySinh;
public:

	void Nhap_Candidate();
	void Xuat_Candidate();
	float DKChonDiem();
	
};

