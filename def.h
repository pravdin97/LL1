#ifndef DEF_H
#define DEF_H

#define MAXLEN 30
#define TEXTLEN 10000
#define NUMLEN 10
#define KEYWORDS 10
#define NUMSEMTYPES 2


typedef char TLexem[MAXLEN];

enum en{ID = 1, CONSTINT10, CONSTINT8,
        CONSTINT16, CONSTCHAR,
        PLUS = 11, MINUS, DIV, MULT, PERCENT,
        INCREMENT, DECREMENT,
        SEMICOLON = 20, OPENBRACKET,
        CLOSEBRACKET, OPENBRACE, CLOSEBRACE, COLON, COMMA,
        ASSIGN, SWITCH, CASE, DEFAULT, BREAK,
        CHAR = 50, INT, DOUBLE,
       CLASS = 60, VOID, MAIN, MAINFUNC, ERROR = 100, END = 200};

#define MaxTypeTerminal 200

enum DataType{
    semInt = 1,
    semDouble,
    semFunc,
    semUndefine = 0
};

enum Neterm {
    N_PROGR = 300, N_OPIS, N_ONEOPIS, N_MAIN,
    N_DATA, N_TYPE, N_SPIS, N_PEREM, N_PRODSPIS,
    N_OO, N_OPER, N_SOSTAV, N_PRISV, N_SWITCH,
    N_SWBODY, N_CASES, N_CASE, N_OPERS, N_VYR,
    N_PRODVYR, N_MN, N_PRODMN, N_PREF, N_POSTF,
    N_PRODPOSTF, N_EL, N_INIZ, N_PRODTSW
};

#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

#define max(a, b) a < b ? b : a

#endif // DEF_H
