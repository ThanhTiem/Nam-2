#include "Day.h"
using namespace std;



void Day::Nhap_Date()
{
	cin >> ngay >> thang >> nam;
}

void Day::Xuat_Date()
{
	cout << ngay << "/" << thang << "/" << nam;
}

