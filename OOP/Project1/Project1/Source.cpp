#include <iostream>
using namespace std;

const int Month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
struct DATE {
	int ngay;
	int thang;
	int nam;
};

void Nhap(DATE t[1000], int i) {
	cout << "\nNhap ngay: ";
	cin >> t[i].ngay;
	do {
		cout << "\nNhap thang: ";
		cin >> t[i].thang;
		if (t[i].thang <= 0 || t[i].thang > 12)
			cout << "\nThang khong hop le! vui long nhap lai.";
	} while (t[i].thang <= 0 || t[i].thang > 12);
	do {
		cout << "\nNhap vao nam: ";
		cin >> t[i].nam;
		if (t[i].nam <= 0)
			cout << "\nNam nhap khong hop le! vui long nhap lai.";
	} while (t[i].nam <= 0);
}
void Xuat(DATE t[1000], int i) {

	cout << t[i].ngay << " / " << t[i].thang << " / " << t[i].nam;
}
int Check_Nhuan(int nam) {
	return((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) ? 1 : 0;
}
void CheckDay(DATE t)
{
	int x;
	do
	{
		switch (t.thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			x = 31;
			break;
		case 4: case 6: case 9: case 11:
			x = 30;
			break;
		case 2:
			if ((t.nam % 4 == 0 && t.nam % 100 != 0) || (t.nam % 400 == 0))
				x = 29;
			else
				x = 28;
			break;
		default: x = 0;
		}
		if (x == 0 || t.ngay <= 0 || t.ngay > x)
			cout << "\nngay khong hop le! vui long nhap lai. " << endl;
	} while (x == 0 || t.ngay <= 0 || t.ngay > x);
}

int SoNgayCuaThang(int th, int nm) {
	if (th == 2) return(28 + Check_Nhuan(nm));
	return Month[th + 1];
}

long TongNgay(DATE t) {
	long Tong = 0;
	int i;
	for (i = 0; i < t.nam; i++) {
		Tong += 365 + Check_Nhuan(i);
	}
	for (i = 0; i < t.thang; i++) {
		Tong += SoNgayCuaThang(i, t.nam);
	}
	Tong += t.ngay;
	return Tong;
}
long KhoangCach(DATE t1, DATE t2) {
	return abs((TongNgay(t1) - TongNgay(t2)));
}
int main() {
	DATE t[1000];
	int n;
	cout << "\nNhap vao n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap vao thoi gian thu " << i + 1 << ": ";
		Nhap(t, i);
	}
	for (int i = 0; i < n; i++) {
		cout << "\n thoi gian thu " << i + 1 << ": ";
		Xuat(t, i);
	}
	int i, j;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (t[j].nam > t[j + 1].nam)
				swap(t[j], t[j + 1]);
			else if (t[j].nam == t[j + 1].nam)
			{
				if (t[j].thang > t[j + 1].thang)
					swap(t[j], t[j + 1]);
				if (t[j].thang == t[j + 1].thang)
				{
					if (t[j].ngay > t[j + 1].ngay)
						swap(t[j], t[j + 1]);
				}
			}

		}
	}
	
	for (int i = 0; i < n; i++) {
		if (Check_Nhuan(t[i].nam) == 1){
			cout << "\n thoi gian co nam nhuan la ";
			Xuat(t, i);
		}
	}
	cout << "\nThoi gian sap xep tang dan la: ";
	for (int i = 0; i < n; i++) {
		cout << "\n thoi gian thu " << i + 1 << ": ";
		Xuat(t, i);
	}
	long a[1000]; int k = 0;
	long tam = KhoangCach(t[0], t[1]);
		for (int j = 0; j < n-1; j++)
	{
			
			if (KhoangCach(t[j], t[j + 1]) < tam)
				k=j;
	}
	cout << "\n 2 ngay gan nhat la \n";
	Xuat(t,k);
	cout << endl;
	Xuat(t, k+1);

	system("pause");
	return 0;
}