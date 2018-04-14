#include <iostream>
using namespace std;


class vector
{

private:
	float v[1000];
	int n;
public:
	vector();
	void nhapVT();
	void XuatVT();
	vector cong(vector, vector );
	vector hieu(vector, vector );
	vector nhan(vector, vector );
	vector tinhKhoangCach(vector, vector );
	~vector();
};
