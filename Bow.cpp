#include "Bow.h"



Bow::Bow(string name, int id, int price, int weight, int durability, int min_dmg, int max_dmg)
	: Item(name, id, price, weight, durability), min_dmg(min_dmg), max_dmg(max_dmg)
{}

Bow &Bow::operator=(const Bow &obj)
{
	static_cast<Item&>(*this) = static_cast<const Item&>(obj);
	min_dmg = obj.min_dmg;
	max_dmg = obj.max_dmg;
	return *this;
}

ostream& operator<<(ostream &ostr, const Bow &obj)
{
	ostr << static_cast<const Item&>(obj);
	ostr << setw(8) << obj.min_dmg << " - " << setw(8) << obj.max_dmg;
	return ostr;
}