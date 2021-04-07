// aburbe.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "aburbe.h"
#include "src\resources.h"
#include "src\UBlock.h"

using namespace std;

int main()
{
	UBlock ub = UBlock();
	ub.addRes(water, 100);
	ub.addRes(dirt, 300);
	ub.addRes(sand, 200);
	ub.addRes(sand, 20);
	ub.addRes(limestone, 50);
	ub.addRes(coal, 5000);
	ub.removeRes(coal, 1000);
	ub.addRes(air, 5000);

	
	for (int i = 0; i < UBlock::maxSlots; i++)
	{
		ResAmount r = ub.res(i);
		cout << r.res->name << " " << r.amount << endl;
	}
	cout << "Total: " << ub.totalSize() << endl;
	return 0;
}
