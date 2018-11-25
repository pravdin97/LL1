#ifndef SCANER_H
#define SCANER_H
#include "def.h"


class TScaner
{
private:
    char *text;
    int uk;
    int line, pos;

public:
    TScaner();
    void setUk(int uk);
    int getUk();
    int scaner(TLexem lex);
    void openFile(char* path);
    int compare(TLexem lex);
    void printError(char *err, TLexem l);
};

#endif // SCANER_H
