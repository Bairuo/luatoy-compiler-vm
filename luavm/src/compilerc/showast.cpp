#include "block.h"
#include "exp.h"
#include "stat.h"
#include <iostream>
#include <string>

using namespace std;

void showast(Block *block, const string &ident);
void showast(Exp *exp, const string &ident);
void showast(Stat *stat, const string &ident);

const string IDENT = "  ";

void showast(Block *block, const string &ident) {
	if(block == nullptr)return;

	cout << ident + "Block" << endl;

	for(auto it = block->stats.rbegin(); it != block->stats.rend(); it++){
		showast(*it, IDENT + ident);
	}

	for(auto it = block->retExps.begin(); it != block->retExps.end(); it++){
		showast(*it, IDENT + ident);
	}
}

void showast(Exp *exp, const string &ident) {

	if(dynamic_cast<IntegerExp*>(exp) != nullptr){
		auto t = dynamic_cast<IntegerExp*>(exp);

		cout << ident + "IntegerExp: " << t->val << endl;
	}
	else if(dynamic_cast<FloatExp*>(exp) != nullptr){
		auto t = dynamic_cast<FloatExp*>(exp);

		cout << ident + "FloatExp: " << t->val << endl;
	}
	else if(dynamic_cast<TrueExp*>(exp) != nullptr){
		cout << ident + "TrueExp" << endl;
	}
	else if(dynamic_cast<FalseExp*>(exp) != nullptr){
		cout << ident + "FalseExp" << endl;
	}
	else if(dynamic_cast<StringExp*>(exp) != nullptr){
		auto t = dynamic_cast<StringExp*>(exp);

		cout << ident + "StringExp: " << t->str << endl;
	}
	else if(dynamic_cast<NameExp*>(exp) != nullptr){
		auto t = dynamic_cast<NameExp*>(exp);

		cout << ident + "NameExp: " << t->name << endl;
	}
	else if(dynamic_cast<UnopExp*>(exp) != nullptr){
		cout << ident + "UnopExp" << endl;

		auto t = dynamic_cast<UnopExp*>(exp);

		showast(t->exp, IDENT + ident);
	}
	else if(dynamic_cast<BinopExp*>(exp) != nullptr){
		cout << ident + "BinopExp" << endl;

		auto t = dynamic_cast<BinopExp*>(exp);

		showast(t->exp1, IDENT + ident);
		showast(t->exp2, IDENT + ident);
	}
	else if(dynamic_cast<ParensExp*>(exp) != nullptr){
		cout << ident + "ParensExp" << endl;

		auto t = dynamic_cast<ParensExp*>(exp);

		showast(t->exp, IDENT + ident);
	}
	else if(dynamic_cast<FuncCallExp*>(exp) != nullptr){
		cout << ident + "FuncCallExp" << endl;

		auto t = dynamic_cast<FuncCallExp*>(exp);

		showast(t->prefixExp, IDENT + ident);
		showast(t->nameExp, IDENT + ident);

		if(t->args.size() > 0){
			cout << ident + "args" << endl;
			for(auto it = t->args.rbegin(); it != t->args.rend(); it++){
				showast(*it, IDENT + ident);
			}
		}
	}
	else if(dynamic_cast<FuncDefExp*>(exp) != nullptr){
		cout << ident + "FuncDefExp" << endl;

		auto t = dynamic_cast<FuncDefExp*>(exp);

		if(t->parlist.size() > 0){
			cout << ident + "parlist" << endl;
			cout << ident;
			for(auto it = t->parlist.rbegin(); it != t->parlist.rend(); it++){
				cout << *it << " ";
			}
			cout << endl;
		}


		showast(t->block, IDENT + ident);
	}
	else if(dynamic_cast<TableConstructorExp*>(exp) != nullptr){
		cout << ident + "TableConstructorExp" << endl;

		auto t = dynamic_cast<TableConstructorExp*>(exp);

		if(t->fieldExps.size() > 0){
			cout << ident + "fieldExps" << endl;
			for(auto it = t->fieldExps.rbegin(); it != t->fieldExps.rend(); it++){
				showast(*it, IDENT + ident);
			}
		}
	}
	else if(dynamic_cast<FieldExp*>(exp) != nullptr){
		cout << ident + "FieldExp" << endl;

		auto t = dynamic_cast<FieldExp*>(exp);

		showast(t->keyExp, IDENT + ident);
		showast(t->valExp, IDENT + ident);
	}

}


void showast(Stat *stat, const string &ident) {

	if(dynamic_cast<LocalVarDeclStat*>(stat) != nullptr){
		cout << ident + "LocalVarDeclStat" << endl;

		auto t = dynamic_cast<LocalVarDeclStat*>(stat);

		cout << ident + "namelist:" << endl;
		for(auto it = t->nameList.begin(); it != t->nameList.end(); it++){
			cout << IDENT + ident + *it << endl;
		}

		cout << ident + "explist:" << endl;
		for(auto it = t->expList.begin(); it != t->expList.end(); it++){
			showast(*it, IDENT + ident);
		}
	}
	else if(dynamic_cast<AssignStat*>(stat) != nullptr){
		cout << ident + "AssignStat" << endl;

		auto t = dynamic_cast<AssignStat*>(stat);

		cout << ident + "varlist(exp):" << endl;
		for(auto it = t->varList.begin(); it != t->varList.end(); it++){
			showast(*it, IDENT + ident);
		}

		cout << ident + "explist:" << endl;
		for(auto it = t->expList.begin(); it != t->expList.end(); it++){
			showast(*it, IDENT + ident);
		}
	}
	else if(dynamic_cast<FuncCallStat*>(stat) != nullptr){
		cout << ident + "FuncCallStat" << endl;

		auto t = dynamic_cast<FuncCallStat*>(stat);

		showast(t->funcCallEXp, IDENT + ident);
	}
	else if(dynamic_cast<IfStat*>(stat) != nullptr){
		cout << ident + "IfStat" << endl;

		auto t = dynamic_cast<IfStat*>(stat);

		cout << ident + "exps:" << endl;
		for(auto it = t->exps.begin(); it != t->exps.end(); it++){
			showast(*it, IDENT + ident);
		}

		cout << ident + "blocks:" << endl;
		for(auto it = t->blocks.begin(); it != t->blocks.end(); it++){
			showast(*it, IDENT + ident);
		}
	}
	else if(dynamic_cast<WhileStat*>(stat) != nullptr){
		cout << ident + "WhileStat" << endl;

		auto t = dynamic_cast<WhileStat*>(stat);

		showast(t->exp, IDENT + ident);
		showast(t->block, IDENT + ident);
	}
	else if(dynamic_cast<RepeatStat*>(stat) != nullptr){
		cout << ident + "RepeatStat" << endl;

		auto t = dynamic_cast<RepeatStat*>(stat);

		showast(t->block, IDENT + ident);
		showast(t->exp, IDENT + ident);
	}
	else if(dynamic_cast<BreakStat*>(stat) != nullptr){
		cout << ident + "BreakStat" << endl;
	}
	else if(dynamic_cast<LocalFuncDefStat*>(stat) != nullptr){
		cout << ident + "LocalFuncDefStat" << endl;

		auto t = dynamic_cast<LocalFuncDefStat*>(stat);

		showast(t->nameExp, IDENT + ident);
		showast(t->defExp, IDENT + ident);
	}
	else if(dynamic_cast<ForNumStat*>(stat) != nullptr){
		cout << ident + "ForNumStat" << endl;

		auto t = dynamic_cast<ForNumStat*>(stat);

		cout << ident + "initExp" << endl;
		showast(t->initExp, IDENT + ident);
		cout << ident + "limitEXp" << endl;
		showast(t->limitEXp, IDENT + ident);
		cout << ident + "stepExp" << endl;
		showast(t->stepExp, IDENT + ident);

		cout << ident + "Block:" << endl;
		showast(t->block, IDENT + ident);
	}
	else if(dynamic_cast<ForInStat*>(stat) != nullptr){
		cout << ident + "ForInStat" << endl;

		auto t = dynamic_cast<ForInStat*>(stat);

		cout << ident + "nameList:" << endl;
		for(auto it = t->nameList.begin(); it != t->nameList.end(); it++){
			cout << " " << *it << endl;
		}

		cout << ident + "expList:" << endl;
		for(auto it = t->expList.begin(); it != t->expList.end(); it++){
			showast(*it, IDENT + ident);
		}

		cout << ident + "Block:" << endl;
		showast(t->block, IDENT + ident);
	}
}