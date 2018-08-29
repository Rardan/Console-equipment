#include "Shield.h"



Shield::Shield(string name, int id, int price, int weight, int durability, int defence)
	: Item(name, id, price, weight, durability), defence(defence)
{
}

Shield &Shield::operator=(const Shield &obj)
{
	static_cast<Item&>(*this) = static_cast<const Item&>(obj);
	defence = obj.defence;
	return *this;
}

ostream& operator<<(ostream &ostr, const Shield &obj)
{
	ostr << static_cast<const Item&>(obj);
	ostr << setw(8) << obj.defence;
	return ostr;
}