#include "TXLib.h"

void Background() //фон
{
    txSetColor(TX_LIGHTCYAN);
    txSetFillColor(TX_LIGHTCYAN);
    txRectangle(0, 0, 800, 600);

}



int main()
    {
    txCreateWindow (800, 600);


    Background();


    txTextCursor (false);
    return 0;
    }

