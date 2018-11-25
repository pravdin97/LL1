#include <iostream>
#include "def.h"
#include "scaner.h"
#include "ll1.h"

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(0,"");
    //cout << "Hello World!" << endl;

    TScaner scaner;
    scaner.openFile("F:/Projects/qt/lang.txt");

//    TLexem lex;
//    int t = scaner.scaner(lex);
//    while(t != END)
//    {
//        t = scaner.scaner(lex);
//        cout << lex << " " << t << endl;
//        if (t == ERROR)
//            scaner.printError("", lex);
//    }
//    cout << "OK";

    LL1 analys(&scaner);
    analys.analys();
    cout << "OK";
    return 0;
}
