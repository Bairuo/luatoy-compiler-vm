#ifndef EXP_H_
#define EXP_H_

#include "interface.h"
#include "block.h"
#include <string>
#include <vector>

struct ExpList : public Exp
{
	std::vector<Exp *> exps;
};

struct NilExp : public Exp
{
	int line;
};

struct TrueExp : public Exp
{
	int line;
};

struct FalseExp : public Exp
{
	int line;
};

struct VarargExp : public Exp
{
	int line;
};

// Numeral
struct IntegerExp : public Exp
{
	int line;
	int val;

	IntegerExp() = default;
	IntegerExp(int line, int val) : line(line), val(val) {}
};

struct FloatExp : public Exp
{
	int line;
	float val;
};

// LiteralString
struct StringExp : public Exp
{
	int line;
	std::string str;

	StringExp() = default;
	StringExp(int line, const std::string &str) : line(line), str(str) {}
};

// unop exp
struct UnopExp : public Exp
{
	int line;
	int op;
	Exp *exp;
};

// exp1 op exp2
struct BinopExp : public Exp
{
	int line;
	int op;
	Exp *exp1;
	Exp *exp2;
};

struct ConcatExp : public Exp
{
	int line;
	std::vector<Exp*> exps;
};


struct FieldExp : public Exp
{
	Exp *keyExp;
	Exp *valExp;
};

// tableconstructor ::= ‘{’ [fieldlist] ‘}’
// fieldlist ::= field {fieldsep field} [fieldsep]
// field ::= ‘[’ exp ‘]’ ‘=’ exp | Name ‘=’ exp | exp
// fieldsep ::= ‘,’ | ‘;’
struct TableConstructorExp : public Exp
{
	int line;
	int lastline;
	std::vector<Exp*> fieldExps;

	//std::list<Exp*> keyExps;
	//std::list<Exp*> valExps;
};

// functiondef ::= function funcbody
// funcbody ::= ‘(’ [parlist] ‘)’ block end
// parlist ::= namelist [‘,’ ‘...’] | ‘...’
// namelist ::= Name {‘,’ Name}
struct FuncDefExp : public Exp
{
	int line;
	int lastline;
	std::vector<std::string> parlist;
	bool isVararg;
	Block *block;
};


struct NameExp : public Exp
{
	int line;
	std::string name;

	NameExp();
	NameExp(int line, const std::string &name) : line(line), name(name) {}
};

struct ParensExp : public Exp
{
	Exp *exp;
};

struct TableAccessExp : public Exp
{
	int lastLine;
	Exp *prefixExp = nullptr;
	Exp *keyExp = nullptr;
};

struct FuncCallExp : public Exp
{
	int line;
	int lastline;
	Exp *prefixExp;
	StringExp *nameExp;
	std::vector<Exp*> args;
};

#endif
