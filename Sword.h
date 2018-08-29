#ifndef SWORD_H_
#define SWORD_H_
#include "Item.h"
class Sword :
	public Item
{
	int damage;
public:
	Sword(string = "name", int = 0, int = 0, int = 0, int = 0, int = 0);

	Sword& operator=(const Sword &obj);
	friend ostream& operator<<(ostream &ostr, const Sword &obj);
};

#endif