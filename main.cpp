#include "TXLib.h"

//Область создание функций
void drawSky(COLORREF color)
{
//RGB(162, 247, 251)
    txSetColor(color);
    txSetFillColor(color);
    txRectangle(0, 0, 800, 600);
}

void drawSun(int x, int y)
{
    txSetColor(RGB(255, 155, 106));
    txSetFillColor(RGB(252, 252, 16));
    txCircle(x, y, 50);
}

void drawLand(COLORREF color)
{
//RGB(140, 255, 140)
    txSetColor(TX_GREEN);
    txSetFillColor(color);
    txRectangle(0, 400, 800, 600);
}

void drawHouse(COLORREF colorWindow)
{
    //крыша
    txSetColor(TX_BROWN);
    txSetFillColor(RGB(128, 0, 0));
    POINT star[3] = {{280, 250}, {410, 120}, {550, 250}};
    txPolygon (star, 3);

    //стена
    txSetColor(TX_RED);
    txSetFillColor(RGB(215, 215, 0));
    txRectangle(280, 250, 550, 500);

//RGB(217, 240, 247)
    //окно
    txSetColor(TX_RED);
    txSetFillColor(colorWindow);
    txRectangle(310, 300, 400, 400);

    //дверь
    txSetColor(TX_RED);
    txSetFillColor(RGB(128, 0, 0));
    txRectangle(430, 330, 520, 500);
    //txCircle();


}

void drawCloud(int x, int y)
{
//80, 70
    txSetColor(RGB(106, 181, 255));
    txSetFillColor(RGB(106, 181, 255));
    txEllipse (x+80-80, y, x+210-80, 140);
    txEllipse (x+170-80, 80, x+300-80, 150);
    txEllipse (x+250-80, 70, x+380-80, 140);
}

void drawMan(int x, int xLegs, int xHands)
{
//x=660
    txSetColor(TX_GRAY);
    txSetFillColor(TX_GRAY);
    txCircle(x, 430, 20);               //Голова
    txSetColor(TX_GRAY, 7);
    txLine(x, 450, x, 520);           //Тело
    txLine(x, 465, x-35+xHands, 490);           //Левая рука
    txLine(x, 465, x+30-xHands, 490);           //Правая рука
    txLine(x, 520, x-20+xLegs, 560);           //Левая нога
    txLine(x, 520, x+20-xLegs, 560);           //Правая нога
}

void drawTree(int x, int y)
{
//x=110 y=485
//Ствол
    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle(x+110-110, y+310-485, x+125-110, y+485-485);
//Крона
    txSetColor(RGB(0, 100, 0));
    txSetFillColor(RGB(0, 255, 0));
    txEllipse (x+80-110, y+190-485, x+150-110, y+420-485);
}

void drawGrib(double razm)
{

    txSetColor(TX_BLACK);
    txSetFillColor(RGB(185, 122, 87));
    txEllipse (610, 460, 640*razm, 510*razm);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txEllipse(600, 430, 660*razm, 470*razm);

}

void drawBeer(int x, int y)
{
 //x=500 y=270
    txSetColor(TX_BLACK);
    txSetFillColor(RGB(145, 72, 0));
    txEllipse (x+370-500, y+215-270, x+470-500, y+350-270);
    txEllipse (x+425-500, y+155-270, x+450-500, y+195-270);
    txEllipse (x+425-500, y+340-270, x+475-500, y+370-270);
    txEllipse (x+450-500, y+240-270, x+500-500, y+270-270);
    txEllipse (x+390-500, y+175-270, x+450-500, y+245-270);
    txEllipse (x+395-500, y+155-270, x+420-500, y+195-270);
    txEllipse (x+365-500, y+340-270, x+415-500, y+370-270);
    txEllipse (x+340-500, y+240-270, x+390-500, y+270-270);
}

void koleso(int x0, int y0, float a, int r)
{
    float a1 = a;
    float a2 = a+120;
    float a3 = a+240;
    int x1, y1;
    int x2, y2;
    int x3, y3;

    txSetColor (TX_WHITE, 6);
    txSetFillColor (TX_BLACK);
    txCircle (x0, y0, r);

    x1 = x0+r*cos(a1*3.14/180);
    y1 = y0+r*sin(a1*3.14/180);
    x2 = x0+r*cos(a2*3.14/180);
    y2 = y0+r*sin(a2*3.14/180);
    x3 = x0+r*cos(a3*3.14/180);
    y3 = y0+r*sin(a3*3.14/180);

    txLine(x0, y0, x1, y1);
    txLine(x0, y0, x2, y2);
    txLine(x0, y0, x3, y3);

    a1+=2;
    a2+=2;
    a3+=2;
}

int main()
{
txCreateWindow (800, 600);

    int xSun = -100;
    int ySun = -100;
    int xCloud = 80;
    int xMan = 660;
    int xManLegs = 0;
    int xManHands = 0;
    double razGrib = 1;

    float a = 0;
    int xKolesa = 100;


    while (xSun<50)
    {

        txBegin();
        drawSky(RGB(162, 247, 251));
        drawSun(xSun, ySun);
        drawCloud(xCloud, 70);
        drawLand(RGB(140, 255, 140));
        drawHouse(RGB(217, 240, 247));
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        drawMan(xMan, xManLegs, xManHands);
        txEnd();
        xSun += 5;
        ySun += 3;
        xMan -= 4;
        xManLegs = xManLegs + 10;
        xManHands = xManHands + 10;
        txSleep(50);

        txBegin();
        drawSky(RGB(162, 247, 251));
        drawSun(xSun, ySun);
        drawCloud(xCloud, 70);
        drawLand(RGB(140, 255, 140));
        drawHouse(RGB(217, 240, 247));
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        drawMan(xMan, xManLegs, xManHands);
        txEnd();
        xSun = xSun + 5;
        ySun = ySun + 3;
        xMan = xMan - 4;
        xManLegs = xManLegs - 10;
        xManHands = xManHands - 10;
        txSleep(50);
    }
    while (xSun<1000)
    {

        txBegin();
        drawSky(RGB(162, 247, 251));
        drawSun(xSun, ySun);
        drawCloud(xCloud, 70);
        drawLand(RGB(140, 255, 140));
        drawHouse(RGB(217, 240, 247));
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        //drawMan(xMan, xManLegs, xManHands);
        txEnd();
        xSun += 5;
        ySun += 3;
        xMan -= 4;
        xManLegs = xManLegs + 10;
        xManHands = xManHands + 10;
        txSleep(50);

        txBegin();
        drawSky(RGB(162, 247, 251));
        drawSun(xSun, ySun);
        drawCloud(xCloud, 70);
        drawLand(RGB(140, 255, 140));
        drawHouse(RGB(217, 240, 247));
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        //drawMan(xMan, xManLegs, xManHands);
        txEnd();
        xSun = xSun + 5;
        ySun = ySun + 3;
        xMan = xMan - 4;
        xManLegs = xManLegs - 10;
        xManHands = xManHands - 10;
        txSleep(50);
    }



    while (xCloud<1000)
    {
        txBegin();
        drawSky(RGB(64, 0, 128));

        drawCloud(xCloud, 70);
        drawLand(RGB(0, 64, 0));

        drawHouse(TX_YELLOW);
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        drawGrib(30);

        //koleso(xKolesa, 400, a, 50);
        //koleso(xKolesa+100, 425, a, 25);

        drawBeer(500, 470);


        drawMan(xMan, xManLegs, xManHands);


        txEnd();

        xCloud = xCloud + 1;
        xMan -= 4;
        a+=2;
        //xKolesa += 5;
        //razGrib = razGrib + 0.0005;
        txSleep(10);
    }


txTextCursor (false);
return 0;
}

