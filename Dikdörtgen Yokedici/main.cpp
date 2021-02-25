#include <iostream>
#include <cstdlib>
#include <graphics.h>

using namespace std;

int x1coord[110];
int x2coord[110];
int ycoord[5];

int destroyedX[5][22], l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0;

void ddortgen();
int carpkontrol(int &x1, int &y1, int &r);
int oyunbasla();
void ilksahne();
void gameOver(int s);

int main()
{
	initwindow(800,600, "dikdörtgen yokedici", 250, 50);

    ilksahne();

    return 0;
}

void ilksahne()
{
	cleardevice();
	setcolor(WHITE);
    outtextxy(350,285," _____    _____ ");
    outtextxy(350,305,"|          |  |          |");
    outtextxy(350,320,"| <---    |  |    ---> |");
	outtextxy(350,335,"|_____|  |_____|");

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	outtextxy(275, 500, "istedigin tusa bas ve basla");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
	outtextxy(200, 200, "DIKDÖRTGEN YOKEDICI");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);


    settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
    outtextxy(600, 530, "HAZIRLAYAN");
    outtextxy(600, 550, "Oguzhan Celik");

    getch();
    cleardevice();
    ddortgen();

    oyunbasla();
}
void gameOver(int s)
{
	cleardevice();
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	outtextxy(250,200,"    * * * * *    * * * * *    *        *   * * * * *");
    outtextxy(250,210,"   *               *         *    * *  * *   *        ");
    outtextxy(250,220,"  *   * * *     * * * * *    *   *   *   * * *    ");
    outtextxy(250,230," *   *    *    *         *    *        *   *        ");
    outtextxy(250,240,"* * *   *    *         *    *        *   * * * * *");
    outtextxy(250,270,"    * * * * *   *    *   * * * * *     * * * * *         ");
    outtextxy(250,280,"   *        *    *   *    *               *        *      ");
    outtextxy(250,290,"  *        *     *  *    * * *         *  *  *          ");
    outtextxy(250,300," *        *      * *    *              *        *       ");
    outtextxy(250,310,"* * * * *       *      * * * * *    *           *      ");

    char q[10];
	itoa(s,q, 10);

	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(350, 400, "Puan: ");
    outtextxy(400, 400, q);

    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(250, 500, "Tekrar oynamak için bosluk tusuna basiniz");

	int c = getch();

    if(c == 32) // boþuk tuþu
    {
    	cleardevice();
    	ilksahne();
	}
}
void ddortgen()
{
	int clr[5] = {BLUE, GREEN, RED, BROWN, WHITE};
	int i, j, x = 10, y = 20 ;

	for ( i = 0 ; i < 5 ; i++ )
	{
		for ( j = 0 ; j < 22 ; j++ )
		{
			setcolor(clr[i]);
			rectangle ( x, y, x + 31, y + 9 ) ;

			x1coord[j] = x;
			x2coord[j] = x+31;

			x += 35 ;
		}
		ycoord[i] = y;
		x = 10 ;
		y +=  20 ;
	}
}

int carpkontrol(int &x1, int &y1, int &r)
{
	int tmpX=-1;

	for(int i = 0; i < 22; i++) // dikdörtgene deðen dairenin koordinatý
	{
		if(x1 > x1coord[21]) //daire en saða deðdiðinde
		{
			tmpX = x1coord[21];
			break;

		}
		if(x1 > x1coord[i])
		{
			if(x1 < x2coord[i])
			{
				tmpX = x1coord[i];
				break;
			}
		}
		if(x1 < x2coord[0]) // en soldaki kutu için
		{
			tmpX = x1coord[0];
			break;
		}
	}

	if(y1-r<=ycoord[0]) // 1. dikdörtgen sýrasý
	{

		for(int i = 0; i <22;i++)
		{
			if(destroyedX[0][i] == tmpX)
				return 0;
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[0], tmpX+31, ycoord[0]+9); // dikdötgen yoketmek


		destroyedX[0][l1] = tmpX;
		l1++;

		return 1;
	}
	else if(y1-r<=ycoord[1] && y1-r >= ycoord[0]) // 2. dikdörtgen sýrasý
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[1][i] == tmpX)
				return 0;
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[1], tmpX+31, ycoord[1]+9); // dikdötgen yoketmek


		destroyedX[1][l2] = tmpX;
		l2++;

		return 1;
	}
	else if(y1-r<=ycoord[2] && y1-r >= ycoord[1]) // 3. dikdörtgen sýrasý
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[2][i] == tmpX)
				return 0;
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[2], tmpX+31, ycoord[2]+9); // dikdötgen yoketmek


		destroyedX[2][l3] = tmpX;
		l3++;

		return 1;
	}
	else if(y1-r<=ycoord[3] && y1-r >= ycoord[2]) // 4. dikdörtgen sýrasý
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[3][i] == tmpX)
				return 0;
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[3], tmpX+31, ycoord[3]+9); // dikdötgen yoketmek


		destroyedX[3][l4] = tmpX;
		l4++;

		return 1;
	}
	else if(y1-r<=ycoord[4] && y1-r >= ycoord[3]) // 5. dikdörtgen sýrasý
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[4][i] == tmpX)
				return 0;
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[4], tmpX+31, ycoord[4]+9); // dikdötgen yoketmek

		destroyedX[4][l5] = tmpX;
		l5++;

		return 1;
	}
	else
	{
		return 0;
	}
}

int oyunbasla() // ana iskelet
{
	int m = 5, n = 5, tmp = 0,
		x = 0, y = 450,
    	x1 = 50, y1 = 420, r = 10;
    char c;

    //line(x,y,x+100,y);
    setcolor(WHITE);
	rectangle(x,y,x+100,y+4);
	setcolor(RED);
    circle(x1,y1,r);

    while(true)
    {
    	delay(30);
		setcolor(BLACK);
		circle(x1,y1,r);

    	if(kbhit())
      	{
	  	 	c = getch();
           	if(c == KEY_LEFT) //sola hareket
           	{
           	  	if(x > 30)
              	{
			    	delay(20);
                 	setcolor(BLACK);
                 	//line(x,y,x+100,y);
                    rectangle(x,y,x+100,y+4);

                 	setcolor(WHITE);
                 	x -= 35;
              		rectangle(x,y,x+100,y+4);
                	//line(x,y,x+100,y);
              	}
           	}

		    if(c == KEY_RIGHT) // saða hareket
            {
                if(x < getmaxx()-125)
				{

                	delay(20);
                    setcolor(BLACK);
                    //line(x,y,x+100,y);
                    rectangle(x,y,x+100,y+4);

					setcolor(WHITE);
                    x += 35;
                    //line(x,y,x+100,y);
                    rectangle(x,y,x+100,y+4);
                }
			}
		}

		if(x1 >= getmaxx()-r) // daire sað tarafta
			m = -5;
		if(x1 <= r) // daire sol tarafta
			m = 5;
		if(y1 <= r) // daire üstte
			n = 5;
		if(y1 >= y-r && (x1 >=x && x1 <= x+100)) // daire hareketli panele çarpmasý
		{
			n = -5;
		}

		/////////  Game Over ///////////
		if(y1 >= y)
		{
			cleardevice();
			gameOver(tmp);
			return 0;
		}

		x1 += m;
		y1 += n;

		///////////// daireyi yeniden çizme ////////////
		setcolor(LIGHTGRAY);
		circle(x1,y1,r);

		///////////////////////// çarýþma kontrolü ////////////////////////////////////
		int lol = carpkontrol(x1,y1,r);

		if(lol == 1)
        {
           	n=5;
        	tmp++;

        	// skor alma ve yazdýrma
			char q[10];
			itoa(tmp,q, 10);
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			setcolor(WHITE);
			outtextxy(100,500,q);
			outtextxy(2, 500,"anlik skor  = ");
		}
 	}
}
