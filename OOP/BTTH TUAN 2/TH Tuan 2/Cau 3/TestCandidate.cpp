#include "TestCandidate.h"
using namespace std;


TestCandidate::TestCandidate()
{
}

void TestCandidate::NhapSL()
{
	cout << "\nNhap so luong thi sinh: ";
	cin >> sl;
	for (int i = 0; i < sl; i++) 
	{
		cout << "\nNhap thi sinh thu " << i + 1 << ": ";
		ts[i].Nhap_Candidate();
	}
}
void TestCandidate::TongDiem()
{
	cout << "\nThi sinh co diem >1 la: ";
	for (int i = 0; i < sl; i++)
	{
		float x = ts[i].DKChonDiem();
		if (x > 1)
			ts[i].Xuat_Candidate();
	}
}
TestCandidate::~TestCandidate()
{
}
