#ifndef PRESTORAGE_H_
#define PRESTORAGE_H_
class PreStorage
{
public:
	virtual void check_full() = 0;
	virtual void increase_curr() = 0;
	virtual void decrease_curr() = 0;
	virtual bool getFull() = 0;
};

#endif