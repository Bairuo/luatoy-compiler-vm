package codegen

import . "luago/compiler/ast"

func cgBlock(fi *funcInfo, node *Block) {
	for _, stat := range node.Stats {
		cgStat(fi, stat)
	}

	if node.RetExps != nil {
		cgRetStat(fi, node.RetExps)
	}
}

func cgRetStat(fi *funcInfo, exps []Exp) {
	nExps := len(exps)
	if nExps == 0 {
		fi.emitReturn(0, 0)
		return
	}

	multRet := isVarargOrFuncCall(exps[nExps-1])
	for i, exp := range exps {
		r := fi.allocReg()
		if i == nExps-1 && multRet {
			cgExp(fi, exp, r, -1)
		} else {
			cgExp(fi, exp, r, 1)
		}
	}
	fi.freeRegs(nExps)
	a := fi.usedRegs
	if multRet {
		fi.emitReturn(a, -1)
	} else {
		fi.emitReturn(a, nExps)
	}
}
