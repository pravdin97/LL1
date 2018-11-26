#include "ll1.h"

LL1::LL1(TScaner *scn)
{
    scaner = scn;
}


int m[5000], z = 0;

void LL1::epsilon() {
    z--;
}

int LL1::analys() {
    int t, fl = 1, i, uk1, ttt;
    TLexem l, lll;
    char sss[30];
    m[z] = N_PROGR;
    t = scaner->scaner(l);
    while (fl) {
        if (m[z] <= MaxTypeTerminal)
        {
            if (m[z] == t)
            {
                //верхушка совпадает с отсканир терминалом
                if (t == END) fl = 0;
                else {
                    t = scaner->scaner(l);
                    z--;
                }
            }
            else {
                scaner->printError("Неверный символ", l);
                return -1;
            }
        }
        else {
            switch (m[z])
            {
            case N_PROGR:
                m[z++] = END;
                m[z++] = CLOSEBRACE;
                m[z++] = N_OPIS;
                m[z++] = OPENBRACE;
                m[z++] = MAIN;
                m[z++] = CLASS;
                break;

            case N_OPIS:
                if (t == CLOSEBRACE)
//                    epsilon();
                    ;
                else
                {
                    m[z++] = N_OPIS;
                    m[z++] = N_ONEOPIS;
                }
                break;

            case N_ONEOPIS:
                if (t == VOID)
                    m[z++] = N_MAIN;
                else
                    m[z++] = N_DATA;
                break;

            case N_MAIN:
                m[z++] = CLOSEBRACE;
                m[z++] = N_OO;
                m[z++] = OPENBRACE;
                m[z++] = CLOSEBRACKET;
                m[z++] = OPENBRACKET;
                m[z++] = MAINFUNC;
                m[z++] = VOID;
                break;

            case N_DATA:
                m[z++] = SEMICOLON;
                m[z++] = N_SPIS;
                if (t == INT)
                    m[z++] = INT;
                else if (t == DOUBLE)
                    m[z++] = DOUBLE;
                break;

            case N_SPIS:
                m[z++] = N_PRODSPIS;
                m[z++] = N_PEREM;
                break;

            case N_PRODSPIS:
                if (t == COMMA) {
                    m[z++] = N_PRODSPIS;
                    m[z++] = N_PEREM;
                    m[z++] = COMMA;
                }
                else if (t == SEMICOLON)
//                    epsilon();
                    ;
                break;
            case N_PEREM:
                m[z++] = N_INIZ;
                m[z++] = ID;
                break;

            case N_INIZ:
                if (t == ASSIGN)
                {
                    m[z++] = N_VYR;
                    m[z++] = ASSIGN;
                }
                else if (t == COMMA || t == SEMICOLON)
//                    epsilon();
                    ;
                break;

            case N_OO:
                if (t == INT || t == DOUBLE)
                {
                    m[z++] = N_OO;
                    m[z++] = N_DATA;
                }
                else if (t == ID || t == OPENBRACE ||
                         t == SWITCH || t == SEMICOLON)
                {
                    m[z++] = N_OO;
                    m[z++] = N_OPER;
                }
                else if (t == CLOSEBRACE)
//                    epsilon();
                    ;
                break;

            case N_OPER:
                switch(t) {
                case ID:
                    m[z++] = SEMICOLON;
                    m[z++] = N_PRISV;
                    break;

                case OPENBRACE:
                    m[z++] = N_SOSTAV;
                    break;

                case SWITCH:
                    m[z++] = N_SWITCH;
                    break;

                case SEMICOLON:
                    //epsilon();
                    break;

                case BREAK:
                    m[z++] = SEMICOLON;
                    m[z++] = BREAK;
                    break;
                }
                break;

            case N_SOSTAV:
                m[z++] = CLOSEBRACE;
                m[z++] = N_OO;
                m[z++] = OPENBRACE;
                break;

            case N_PRISV:
                m[z++] = N_VYR;
                m[z++] = ASSIGN;
                m[z++] = ID;
                break;

            case N_SWITCH:
                m[z++] = N_SWBODY;
                m[z++] = CLOSEBRACKET;
                m[z++] = N_VYR;
                m[z++] = OPENBRACKET;
                m[z++] = SWITCH;
                break;

            case N_SWBODY:
                //??? много вариантов
                m[z++] = N_PRODTSW;
                m[z++] = N_CASES;
                m[z++] = OPENBRACE;
                break;

            case N_PRODTSW:
                if (t == CLOSEBRACE)
                    m[z++] = CLOSEBRACE;
                else {
                    m[z++] = CLOSEBRACE;
                    m[z++] = N_OPERS;
                    m[z++] = COLON;
                    m[z++] = DEFAULT;
                }
                break;

            case N_CASES:
                if (t == CASE)
                {
                    m[z++] = N_CASES;
                    m[z++] = N_CASE;
                }
                else if (t == DEFAULT || t == CLOSEBRACE)
                    //epsilon();
                    ;
                break;

            case N_CASE:
                m[z++] = N_OPERS;
                m[z++] = COLON;
                m[z++] = CONSTINT10; //??? какую константу сюда
                m[z++] = CASE;
                break;

            case N_OPERS:
                if (t == CASE || t == CLOSEBRACE || t == DEFAULT)
                    ;
                else {
                    m[z++] = N_OPERS;
                    m[z++] = N_OPER;
                }
                break;

            case N_VYR:
                m[z++] = N_PRODVYR;
                m[z++] = N_MN;
                break;

            case N_PRODVYR:
                if (t == SEMICOLON)
//                    epsilon();
                    ;
                else {
                    m[z++] = N_MN;

                    if (t == PLUS)
                        m[z++] = PLUS;
                    else if (t == MINUS)
                        m[z++] = MINUS;
                }
                break;

            case N_MN:
                m[z++] = N_PRODMN;
                m[z++] = N_PREF;
                break;

            case N_PRODMN:
                if (t == PLUS || t == MINUS || t == SEMICOLON
                        || t == CLOSEBRACKET)
                    //epsilon();
                    ;
                else {
                    m[z++] = N_PREF;

                    if (t == MULT)
                        m[z++] = MULT;
                    else if (t == DIV)
                        m[z++] = DIV;
                    else if (t == PERCENT)
                        m[z++] = PERCENT;
                }
                break;

            case N_PREF:
                m[z++] = N_POSTF;

                switch(t) {
                case INCREMENT:
                    m[z++] = INCREMENT;
                    break;
                case DECREMENT:
                    m[z++] = DECREMENT;
                    break;
                case PLUS:
                    m[z++] = PLUS;
                    break;
                case MINUS:
                    m[z++] = MINUS;
                    break;
                }
                break;

            case N_POSTF:
                m[z++] = N_PRODPOSTF;
                m[z++] = N_EL;
                break;

            case N_PRODPOSTF:
                if (t == INCREMENT)
                    m[z++] = INCREMENT;
                else if (t == DECREMENT)
                    m[z++] = DECREMENT;
//                else epsilon();
                break;

            case N_EL:
//                if (t == ID)
//                    m[z++] = ID;
//                else if (t == CONSTINT8)
//                    m[z++] = CONSTINT8;
//                else if (t == CONSTINT10)
//                    m[z++] = CONSTINT10;
//                else if (t == CONSTINT16)
//                    m[z++] = CONSTINT16;
//                else if (t == OPENBRACKET){
//                    m[z++] = CLOSEBRACKET;
//                    m[z++] = N_VYR;
//                    m[z++] = OPENBRACKET;
                switch(t) {
                case CONSTINT8:
                    m[z++] = CONSTINT8;
                    break;
                case CONSTINT10:
                    m[z++] = CONSTINT10;
                    break;
                case CONSTINT16:
                    m[z++] = CONSTINT16;
                    break;
                case OPENBRACKET:
                    m[z++] = CLOSEBRACKET;
                    m[z++] = N_VYR;
                    m[z++] = OPENBRACKET;
                    break;
                default: m[z++] = ID;

                }
                break;

            }
            z--;
        }

    }
    return 1;
}
