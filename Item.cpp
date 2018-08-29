#include "Item.h"




Item::Item(string name, int id, int price, int weight, int durability)
	:name(name), id(id), price(price), weight(weight), durability(durability)
{
}


int Item::getID()
{
	return id;
}

Item &Item::operator=(const Item& obj)
{
	name = obj.name;
	id = obj.id;
	price = obj.price;
	weight = obj.weight;
	durability = obj.durability;
	return *this;
}

ostream& operator<<(ostream &ostr, const Item& obj)
{
	ostr << setw(9) << obj.name << " ";
	ostr << setw(5) << obj.price << " ";
	ostr << setw(5) << obj.weight << " ";
	ostr << setw(15) << obj.durability << " ";
	return ostr;
}