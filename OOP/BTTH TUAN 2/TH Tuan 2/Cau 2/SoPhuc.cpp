#include "SoPhuc.h"



SoPhuc::SoPhuc()
{
	thuc = 0;
	ao = 0;
}

SoPhuc::SoPhuc(int t, int a)
{
	thuc = t;
	ao = a;
}
SoPhuc::SoPhuc(const SoPhuc &sp)
{
	thuc = sp.thuc;
	ao = sp.ao;
}
void SoPhuc::Xuat()
{
	if (thuc!=0 && ao == 0)
		cout << thuc;
	if (thuc == 0 && ao != 0)
		cout << ao << "i";
	if (thuc != 0 && ao != 0)
		cout << thuc << " + " << ao << "i";
}
SoPhuc SoPhuc::Cong(SoPhuc sp)
{
	return SoPhuc(thuc + sp.thuc, ao + sp.ao);
}
SoPhuc SoPhuc::Tru(SoPhuc sp)
{
	return SoPhuc(thuc - sp.thuc, ao - sp.ao);
}
SoPhuc SoPhuc::Nhan(SoPhuc sp)
{
	return SoPhuc(thuc*ao - sp.thuc*sp.ao, thuc*sp.ao + sp.thuc*ao);
}
SoPhuc SoPhuc::Chia(SoPhuc sp)
{
	return SoPhuc((thuc*sp.thuc + ao*sp.ao) / (sp.thuc*sp.thuc + sp.ao*sp.ao), (sp.thuc*ao - thuc*sp.ao) / (sp.thuc*sp.thuc + sp.ao*sp.ao));
}
SoPhuc::~SoPhuc()
{
}
