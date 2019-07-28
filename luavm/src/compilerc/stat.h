#ifndef STAT_H_
#define STAT_H_

#include "interface.h"
#include "block.h"
#include "exp.h"
#include <string>
#include <vector>

struct StatList : public Stat
{
	std::vector<Stat*> stats;
};

struct EmptyStat : public Stat
{
	
};

struct BreakStat : public Stat
{
	int line;
};

struct LabelStat : public Stat
{
	std::string name;
};

struct GotoStat : public Stat
{
	std::string name;
};

struct DoStat : public Stat
{
	Block *block;
};

struct FuncCallStat : public Stat
{
	FuncCallExp *funcCallEXp;
};

struct IfStat : public Stat
{
	std::vector<Exp*> exps;
	std::vector<Block*> blocks;
};

struct WhileStat : public Stat
{
	Exp *exp;
	Block *block;
};

struct RepeatStat : public Stat
{
	Block *block;
	Exp *exp;
};

struct ForNumStat : public Stat
{
	int lineOfFor;
	int lineOfDo;
	std::string varName;
	Exp *initExp;
	Exp *limitEXp;
	Exp *stepExp;
	Block *block;
};

struct ForInStat : public Stat
{
	int lineOfDo;
	std::vector<std::string> nameList;
	std::vector<Exp*> expList;
	Block *block;
};

struct AssignStat : public Stat
{
	int lastLine;
	std::vector<Exp*> varList;
	std::vector<Exp*> expList;
};

struct LocalVarDeclStat : public Stat
{
	int lastLine;
	std::vector<std::string> nameList;
	std::vector<Exp*> expList;
};

struct LocalFuncDefStat : public Stat
{
	//std::string name;
	Exp *nameExp;
	FuncDefExp *defExp;
};

#endif
