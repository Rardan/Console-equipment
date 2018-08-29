#ifndef SHIELD_H_
#define SHIELD_H_
#include "Item.h"
class Shield :
	public Item
{
	int defence;
public:
	Shield(string = "name", int = 0, int = 0, int = 0, int = 0, int = 0);

	Shield& operator=(const Shield &obj);
	friend ostream& operator<<(ostream &ostr, const Shield &obj);
};

#endif