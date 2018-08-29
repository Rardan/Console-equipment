#ifndef BOW_H_
#define BOW_H_
#include "Item.h"
class Bow :
	public Item
{
	int min_dmg;
	int max_dmg;
public:
	Bow(string = "name", int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);

	Bow& operator=(const Bow &obj);
	friend ostream& operator<<(ostream &ostr, const Bow &obj);
};

#endif