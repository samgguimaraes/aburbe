#pragma once
#include <cmath>
#include "UBlock.h"

ResAmount UBlock::res(int index)
{
	index = index % maxSlots;
	if (index < 0)
		index += maxSlots;

	return content[index];
}

float UBlock::totalSize()
{
	float total = 0.0f;
	for (ResAmount ra : content)
	{
		total += ra.amount;
	}
	return total;
}

float UBlock::availableSize()
{
	return maxSize - totalSize();
}

int UBlock::findRes(const Res *res)
{
	int i = -1;
	for (i = 0; i < maxSlots; i++)
		if (content[i].res == res)
			break;
	if (i >= maxSlots) i = -1;
	return i;
}

int UBlock::findSmaller()
{
	int mi = -1;
	float min = INFINITY;
	for (int i = 0; i < maxSlots; i++)
	{
		if (content[i].amount < min)
		{
			mi = i;
			min = content[i].amount;
		}
	}

	return mi;
}

float UBlock::addRes(const Res *res, float amount) { return addRes(res, amount, false); }
float UBlock::addRes(const Res *res, float amount, bool force)
{
	float overflow = amount - availableSize();
	overflow = std::fmax(overflow, 0.0f);
	amount -= overflow;

	int res_pos = findRes(res);
	if (res_pos >= 0)
	{
		content[res_pos].amount += amount;
	}
	else
	{
		res_pos = findSmaller();

		if (content[res_pos].amount < FLT_EPSILON || force)
			content[res_pos] = ResAmount(res, amount);
	}

	return overflow;
}

float UBlock::removeRes(const Res *res, float amount)
{
	int res_pos = findRes(res);
	if (res_pos < 0)
		return 0.0f;

	amount = std::fmin(content[res_pos].amount, amount);

	content[res_pos].amount -= amount;
	
	return amount;
}
