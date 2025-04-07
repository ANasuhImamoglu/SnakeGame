#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#include <stdlib.h>
struct information
{
    int point;
    char name[25];
    int target;

}player[50];
//oyuncu dizisi kullanýmý ??


int map[80][23]={0};
int startScreen[80][23]={0};
int tailX[500];
int tailY[500];



int foodx,foody;
randomfood()
{
    srand(time(NULL));
    foodx=24+rand()%75;
    foody=6+rand()%18;

}

void main()
{
        FILE *fp;
        char text[25];
        fp=fopen("yilanoyunu.txt","a+");

        fprintf(fp,"oyuncu\t\tpuani\t\thedefi\n");
        fprintf(fp,"----------    -----------     ----------\n");



int a,b,playerNumber;


    system("color 2f");




    printf("oyuncu sayisini giriniz:");
    scanf("%d",&playerNumber);


for(a=0;a<playerNumber;a++){

    giris(0,0,79,15,3);
    printEnter();

    gotoxy(36,5);printf("###################//YILAN OYUNU\\###################");
    gotoxy(57,8);printf("Oyun yon tuslari ile calisir...");
    gotoxy(57,9);printf("Yilan her yemi yediginde puana 10 eklenir.");

    gotoxy(25,8);printf("oyuncu adi giriniz:");
    scanf("%s",&player[a].name);

    gotoxy(25,9);printf("hedefinizi giriniz:");
    scanf("%d",&player[a].target);
    gotoxy(25,10);printf("BASARILAR:)");
    sleep(2);
    system("cls");



    randomfood();
    area(0,0,79,22,1);
    printScreen();
    int snakex=55,snakey=15;
    int movey=0,movex=0;
    int control=0;
    unsigned char direciton;



     gotoxy(100,4);printf("HEDEF=>> %d",player[a].target);

	 do
    {
        if(kbhit())
        {
            direction=getch();
            if(direction3==224)
            {
                direction=getch();
                switch(direction)
                {
                    case 72:movey=-1; movex=0;
                        break;
                    case 80:movey=1; movex=0;
                        break;
                    case 77: movex=1; movey=0;
                        break;
                    case 75: movex=-1; movey=0;
                }
            }
        }

        snakex=snakex+movex;
        snakey=snakey+movey;

        if(snakex==99)
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",player[a].point*10);
                getch();
                control=1;
            }

        if(snakey==26)
           {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",player[a].point*10);
                getch();
                control=1;
            }
         if(snakaex==20)
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",player[a].point*10);
                getch();
                control=1;
            }
         if(snakey==4)
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",player[a].point*10);
                getch();
                control=1;
            }

        tailX[0]=snakex;
        tailY[0]=snakey;
        int i;


        for(i=1;i<=player[a].point;i++)
        {
            if((yilanx==tailX[i] && taily==tailY[i]))
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",player[a].point*10);
                getch();
                control=1;
            }


        }

        gotoxy(snakex,snakey);printf("%c",254);

        for(i=0;i<=player[a].point;i++)
        {
            gotoxy(tailX[i],tailY[i]);printf("%c",254);

        }


        if(snakex==foodx && snakey==foody)
        {
            randomfood();
            player[a].point++;
            gotoxy(100,5);printf("PUAN=>> %d",player[a].point*10);
        }

        gotoxy(foodx,foody);printf("%c",232);

         Sleep(50);

        gotoxy(snakex,snakey);printf(" ");


        for(i=0;i<=player[a].point;i++)
        {
            gotoxy(tailX[i],tailY[i]);printf(" ");

        }


        for(i=player[a].point;i>0;i--)
        {
            tailX[i]=tailX[i-1];
            tailY[i]=tailY[i-1];
        }


    }
while (control==0);



        fprintf(fp,"%s\t\t",player[a].name);
        fprintf(fp,"%d\t\t",player[a].point*10);
        fprintf(fp,"%d\t\t\n",player[a].target);

        sleep(1);
        system("cls");
    }
fclose(fp);
}






void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

void area(int vertical1, int horizon1, int vertical2, int horizon2,int lap)
{
    int i;
    for(i=vertical1; i<=vertical2;i++)
    {
        map[i][horizon1] = lap;

        map[i][horizon2] = lap;

    }
    for(i=horizon1; i<=horizon2;i++)
    {
        map[vertical1][i] = lap;

        map[vertical2][i] = lap;

    }
}

void printScreen()
{
    int x,y;
    for(x=0;x<80;x++)
    {


        for(y=0;y<23;y++)
        {
        gotoxy(x+20,y+4);

            if(map[x][y]==1)
            {
                printf("%c",219);
            }

            else if(map[x][y]==2)
            {
                printf("%c",176);
            }
            else if(map[x][y]==3)
                printf("%c",88);


        }
    }
}

void enter(int vertic1, int horizony1, int vertic2, int horizony2,int lineType)
{
    int i;
    for(i=vertic1; i<=vertic2;i++)
    {
        enter[i][horizony1] = lineType;

        enter[i][yaty2] = lineType;

    }
    for(i=horizony1; i<=horizony2;i++)
    {
        enter[vertic1][i] = lineType;

        enter[vertic2][i] = lineType;

    }
}
void printEnter()
{
    int x,y;
    for(x=0;x<80;x++)
    {


        for(y=0;y<23;y++)
        {
        gotoxy(x+20,y+4);

            if(enter[x][y]==1)
            {
                printf("%c",219);
            }

            else if(enter[x][y]==2)
            {
                printf("%c",176);
            }
            else if(enter[x][y]==3)
                printf("%c",88);


        }
    }

}
