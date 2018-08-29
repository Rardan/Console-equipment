#include "Sword.h"



Sword::Sword(string name, int id, int price, int weight, int durability, int damage)
	: Item(name, id, price, weight, durability), damage(damage)
{}

Sword &Sword::operator=(const Sword &obj)
{
	static_cast<Item&>(*this) = static_cast<const Item&>(obj);
	damage = obj.damage;
	return *this;
}

ostream& operator<<(ostream &ostr, const Sword &obj)
{
	ostr << static_cast<const Item&>(obj);
	ostr << setw(8) << obj.damage;
	return ostr;
}