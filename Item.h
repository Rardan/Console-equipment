#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <iomanip>
using namespace std;

class Item
{
	string name;
	int id;
	int price;
	int weight;
	int durability;
public:
	Item(string = "name", int = 0, int = 0, int = 0, int = 0);
	
	int getID(); //zwraca wartoœæ id

	friend ostream& operator<<(ostream &ostr, const Item &obj);
	Item& operator=(const Item &obj);
};

#endif