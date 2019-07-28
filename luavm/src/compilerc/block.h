#ifndef BLOCK_H_
#define BLOCK_H_

#include "interface.h"
#include <vector>

struct Block
{
	int lastline;
	std::vector<Stat*> stats;
	std::vector<Exp*> retExps;
};

#endif
