package codegen

import . "luago/binchunk"
import . "luago/compiler/ast"

import "fmt"
import "os"
import "strconv"

var f *os.File

func GenProto(chunk *Block) *Prototype {
	fd := &FuncDefExp{IsVararg: true, Block: chunk}

	fi := newFuncInfo(nil, fd)
	fi.addLocVar("_ENV")

	cgFuncDefExp(fi, fd, 0)

	f, _ = os.Create("/home/bairuo/luavm/tool/varinfo")
	defer f.Close()

	showVar(fi)

	return toProto(fi.subFuncs[0])
}

func showVar(fi *funcInfo) {

	fmt.Fprint(f, "[function]]\n")
	fmt.Fprint(f, "upvalues\n")
	for name, _ := range fi.upvalues {
		fmt.Fprint(f, "	name: "+name+"\n")
	}

	fmt.Fprint(f, "locals\n")
	for _, varinfo := range fi.locVars {
		fmt.Fprint(f, "	name: "+varinfo.name+", scopeLv: "+strconv.Itoa(varinfo.scopeLv)+", slot: "+strconv.Itoa(varinfo.slot)+"\n")
	}

	fmt.Fprint(f, "constants\n")
	for key, _ := range fi.constants {
		if name, ok := key.(string); ok {
			fmt.Fprint(f, "	name: "+name+"\n")
		}

	}

	fmt.Fprint(f, "\n")

	for _, subfi := range fi.subFuncs {
		showVar(subfi)
	}
}
