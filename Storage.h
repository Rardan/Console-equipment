#ifndef STORAGE_H_
#define STORAGE_H_
#include "PreStorage.h"
#include <string>
using namespace std;

class Storage: public PreStorage
{
	string name;
	int capacity;
	int cap_current=0;
	bool isFull;
public:
	Storage(string, int);
	virtual void increase_curr(); //zwi�ksza zape�nienie plecaka
	virtual void decrease_curr(); //zmniejsza zape�nienie plecaka
	virtual void check_full(); //sprawdza czy plecak jest pe�en
	virtual bool getFull(); //zwraca warto�� isFull
};

#endif