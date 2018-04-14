#include "Candidate.h"





void Candidate::Nhap_Candidate()
{
	
	cout << "\nNhap Ten: ";
	cin.ignore();
	cin.getline(ten, 50);
	
	cout << "\nNhap ma so: "; cin >> ma;
	cout << "\nNhap Ngay sinh: "; 
	NgaySinh.Nhap_Date();
	cout << "\nNhap Diem toan: "; cin >> toan;
	cout << "\nNhap Diem van: "; cin >> van;
	cout << "\nNhap Diem anh: "; cin >> anh;
}

void Candidate::Xuat_Candidate()
{
	cout << "\nMa so: " << ma;
	cout << "\nTen: " << ten;
	cout << "\nNgay sinh: ";
	NgaySinh.Xuat_Date();
	cout << "\nDiem toan: " << toan;
	cout << "\nDiem van: " << van;
	cout << "\nDiem anh: " << anh;
	cout << endl;
}

float Candidate::DKChonDiem()
{
	return (toan + van + anh);
}

