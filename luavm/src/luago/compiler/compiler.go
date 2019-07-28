package compiler

import "luago/binchunk"
import "luago/compiler/codegen"
import "luago/compiler/parser"

import "fmt"
import "os"
import "encoding/json"

func Compile(chunk, chunkName string) *binchunk.Prototype {

	f, _ := os.Create("/home/bairuo/luavm/tool/ast")
	defer f.Close()

	fmt.Fprint(f, "无法生成语法树：词法或语法分析出错")

	d2, _ := os.Create("/home/bairuo/luavm/tool/varinfo")
	defer d2.Close()

	fmt.Fprint(d2, "无法获得符号表：代码生成出错")

	ast := parser.Parse(chunk, chunkName)

	b, err := json.Marshal(ast)

	if err != nil {
		panic(err)
	}

	d, _ := os.Create("/home/bairuo/luavm/tool/ast")
	defer d.Close()

	fmt.Fprint(d, string(b))

	return codegen.GenProto(ast)
}
