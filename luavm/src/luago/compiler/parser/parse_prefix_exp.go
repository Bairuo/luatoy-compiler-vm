package parser

import . "luago/compiler/ast"
import . "luago/compiler/lexer"

func parsePrefixExp(lexer *Lexer) Exp {
	var exp Exp
	if lexer.LookAhead() == TOKEN_IDENTIFIER {
		line, name := lexer.NextIdentifier() // Name
		exp = &NameExp{line, name}
	} else { // '(' exp ')'
		exp = parseParensExp(lexer)
	}
	return _finishPrefixExp(lexer, exp)
}

func _finishPrefixExp(lexer *Lexer, exp Exp) Exp {
	for {
		switch lexer.LookAhead() {
		case TOKEN_SEP_LBRACK:
			lexer.NextToken()                       // '['
			keyExp := parseExp(lexer)               // exp
			lexer.NextTokenOfKind(TOKEN_SEP_RBRACK) // ']'
			exp = &TableAccessExp{lexer.Line(), exp, keyExp}
		case TOKEN_SEP_DOT:
			lexer.NextToken()                    // '.'
			line, name := lexer.NextIdentifier() // Name
			keyExp := &StringExp{line, name}
			exp = &TableAccessExp{line, exp, keyExp}
		case TOKEN_SEP_COLON,
			TOKEN_SEP_LPAREN, TOKEN_SEP_LCURLY, TOKEN_STRING:
			exp = _finishFuncCallExp(lexer, exp) // [':' Name] args
		default:
			return exp
		}
	}
	return exp
}

func parseParensExp(lexer *Lexer) Exp {
	lexer.NextTokenOfKind(TOKEN_SEP_LPAREN) // '('
	exp := parseExp(lexer)                  // exp
	lexer.NextTokenOfKind(TOKEN_SEP_RPAREN) // ')'

	switch exp.(type) {
	case *VarargExp, *FuncCallExp, *NameExp, *TableAccessExp:
		return &ParensExp{exp}
	}
	return exp
}

func _finishFuncCallExp(lexer *Lexer, prefixExp Exp) *FuncCallExp {
	nameExp := _parseNameExp(lexer) // [':' Name]
	line := lexer.Line()
	args := _parseArgs(lexer) // args
	lastLine := lexer.Line()
	return &FuncCallExp{line, lastLine, prefixExp, nameExp, args}
}
