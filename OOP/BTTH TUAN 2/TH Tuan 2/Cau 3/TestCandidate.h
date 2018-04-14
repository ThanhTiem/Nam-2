#pragma once
#include "Candidate.h"
#include "Day.h"
using namespace std;
class TestCandidate
{
private: 
	Candidate ts[10000];
	int sl;
public:
	TestCandidate();
	void NhapSL();
	void TongDiem();
	~TestCandidate();
};

