#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <string>
#include <vector>

struct Exp
{
	virtual void f() {}	// dynamic_cast
};

struct Stat
{
	virtual void f() {}	// dynamic_cast
};

struct NameList
{
	std::vector<std::string> names;
};


#endif
