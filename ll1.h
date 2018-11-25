#ifndef LL1_H
#define LL1_H
#include "def.h"
#include "scaner.h"

class LL1
{
private:
    TScaner* scaner;

public:

    LL1(TScaner *scn);
    void epsilon();
    int analys();
};



#endif // LL1_H
