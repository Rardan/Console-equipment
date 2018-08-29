#include "Storage.h"



Storage::Storage(string name, int capacity)
	:name(name), capacity(capacity) {}

void Storage::check_full()
{
	if (cap_current == capacity)
	{
		isFull = true;
	}
	else
	{
		isFull = false;
	}
}

void Storage::increase_curr()
{
	cap_current++;
}

void Storage::decrease_curr()
{
	cap_current--;

}

bool Storage::getFull()
{
	return isFull;
}