#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

int main () 
{
    int en,boy,yem,i,j,u,k,m,hamle;
    char yon, temp, anything[10];
    srand(time(NULL));
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
    printf("\n\t\t\t\t\tWelcome to the snake game. We will have so much funn :)");
    do{
	printf("\n\nPlease enter the width and height of the game field you would like to play in:  ");
    scanf("%d%d",&en,&boy);
    int alan[100][100];
    int yilan[3][100];
    printf("Please enter the number of baits: ");
    scanf("%d", &yem);
    while(yem>en*boy-1) //yem alýndý
    {
        printf("The number of baits is too much for field. Please enter a smaller value: ");
        scanf("%d", &yem);
    }
    for (i=0; i<=en+1; i++) //bu iki for matrise kenar konurken kullanildi
    {
        alan[i][0]=58;
        alan[i][boy+1]=58;
    }
    for (j=0; j<=boy+1; j++)
    {
        alan[0][j]=126;
        alan[en+1][j]=126;
    }
    for (i=1; i<en+1; i++)
    {
        for(j=1; j<boy+1; j++)
        {
            {
                alan[i][j]=32; //oyun alanýnýn içerisine boþluk koydum
            }
        }
    }
    for(i=0; i<100; i++)
    {
        yilan[2][i]=32;  //yilan matrisine boþluk koydum
    }
    for (k=1; k<=yem; k++)  //Yemleri koyan dongu
    {
        i=rand() %en + 1;
        j=rand() %boy + 1;
        if (alan[i][j]!=48)
        {
            alan[i][j]=48;
        }
        else
        {
            k=k-1;
        }
    }
    while(alan[i][j]==48) 
    {
        i=rand() %en + 1;
        j=rand() %boy + 1;
    }
    alan[i][j]=1; //yilani ilk koyan dongu
	yilan[0][0]=i;
    yilan[1][0]=j; 
	yilan[2][0]=1;//ilk yerini matrise ekledim
    
    for (i=0; i<en+2; i++)  //ilk kez yazdirma for u
    {
    	printf("\t\t\t\t\t");
        for (j=0; j<boy+2; j++)
        {
            if(alan[i][j]!=1)
            {
            	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x01);
                printf("%c  ", alan[i][j]);
            }
            else
            {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
                printf("%d  ", alan[i][j]);
            }
        }
        printf("\n");
    }

    u=1;
    m=1;
    hamle=0;
    temp=alan[yilan[0][0]][yilan[1][0]];
	while(temp!=126 && temp!=58 && yem>0)
    {
    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
        printf("\n Enter the way you would like to go: ( W for up, S for down, D for right and A for left): ");
        hamle=hamle+1;
        scanf( " %c", &yon);
        switch(yon)
        {
		 case  'W': //yukari
            if(m!=u)
            {
            	yilan[2][u]=m;
                u=m; //yemek yemeden tekrar girmemesi için
            }
            for(i=u; 0<i; i--)
            {
                yilan[0][i]=yilan[0][i-1];
                yilan[1][i]=yilan[1][i-1]; // yýlaný kaydýrma foru
            }
            yilan[0][0]=yilan[0][0]-1; //yilanýn baþýnýn yeni konumu (sadece i deðeri deðiþir, j yi ellemedim o yüzden)
           break;
        case 'S': //asagý
            if(m!=u)
            {
            	yilan[2][u]=m;
                u=m;//yemek yemeden tekrar girmemesi için             
            }
            for(i=u; 0<i; i--)
            {
                yilan[0][i]=yilan[0][i-1];
                yilan[1][i]=yilan[1][i-1]; // yýlaný kaydýrma foru
            }
            yilan[0][0]=yilan[0][0]+1; //yilanýn baþýnýn yeni konumu (iadece i deðeri deðiþir, j yi ellemedim o yüzden)
           break;
        case 'A'://sag
            if(m!=u)
            {
            	yilan[2][u]=m;
                u=m; //yemek yemeden tekrar girmemesi için
	         }
            for(i=u; 0<i; i--)
            {
                yilan[0][i]=yilan[0][i-1];
                yilan[1][i]=yilan[1][i-1]; // yýlaný kaydýrma foru
            }
            yilan[1][0]=yilan[1][0]+1; //yilanýn baþýnýn yeni konumu (iadece i deðeri deðiþir, j yi ellemedim o yüzden)
            break;
        case 'D'://sol
            if(m!=u)
            {
            	yilan[2][u]=m;
                u=m; //yemek yemeden tekrar girmemesi için
            }
            for(i=u; 0<i; i--)
            {
                yilan[0][i]=yilan[0][i-1];
                yilan[1][i]=yilan[1][i-1]; // yýlaný kaydýrma foru
            }
            yilan[1][0]=yilan[1][0]-1; //yilanýn baþýnýn yeni konumu (iadece i deðeri deðiþir, j yi ellemedim o yüzden)
            break;
        default :
        	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
            printf("Undefined input! Please try again (You might be using lower case. Please check the CapsLock button. )\n");
            hamle=hamle-1;
        }
            for(i=u; i>=0; i--)
            {
                if(i==0)
                {
                    temp=alan[yilan[0][0]][yilan[1][0]];  //gidilen yer kontrol noktasý
                }
                alan[yilan[0][i]][yilan[1][i]]=yilan[2][i];	//elemanlarý alan[][] matrisine yerleþtirme foru
            }
        if(temp==48) //yilanýn gideceði yere bakar
        {
            m=m+1;
            yem=yem-1;
        }
        else
        {
            if(temp !=32 && temp!= 1) //temp !=1 yaptým çünkü yýlan tek birimken ayný doðrultuda yön deðiþtiremiyordu, sadece 1 de buna dþkkat etmek yeterliydi çünkü zaten yýlan boyu 1 den büyük olunca geri gitmesi kuyruðuna basmak olur.
            {
                yem=yem-200;
            }
        }
        system("cls");
        printf("\n\n\n\n\n");
        if(yem<0)//bu if her hamle sonrasi tahtayi yazdýrmaktadýr, içerisindeki if ise oyunun bitip bitmediðini kontrol etmekte ve ona göre yýlaný yok etmektedir, açýklama yaparken if i dýþarý koyma sebebbinin her döngüde kýyas yapmamak adýna olduðunu söyle
        {
            for (i=0; i<en+2; i++)
            {
            	printf("\t\t\t\t\t\t\t");
                for (j=0; j<boy+2; j++)
                {
                    if (32 >alan[i][j])
                    {
                    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x40);
                        printf("*  ");
                    }
                    else
                    {
                    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
                        printf("%c  ", alan[i][j]);
                        
                    }
                }
                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x07	);
                printf("\n");
            }
        }
        else
        {
            for (i=0; i<en+2; i++)
            {
            	printf("\t\t\t\t\t\t\t");
                for (j=0; j<boy+2; j++)
                {
                    if (32 >alan[i][j])
                    {
                        if (alan[i][j]>=10) //kaymayý önleme if i
                        {
                        	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
                            printf("%d ",alan[i][j]);
                        }
                        else
                        {
                        	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
                            printf("%d  ",alan[i][j]);
                        }
                    }
                    else
                    {
                    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x01);
                        printf("%c  ", alan[i][j]);
                    }
                }
                printf("\n");
            }
        }
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
        printf("\nMoves: %d\n", hamle);
    }
    if(yem==0)
    {
    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
        printf("\n\t\t\t\t\t!!!Congratulations, YOU WON!!!\n\n");
    }
    else
    {
    	yem=yem+200;
    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
        if(temp==126 || temp==58)
        {
            printf("The snake just hit a wall, you lost :( )\n");
            printf("Uneaten baits: %d\n", yem);
        }
        else
        {
            printf("The snake just crossed on itself, you lost :( )\n");
            printf("Uneaten baits: %d\n", yem);
        }
    }
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0D);
    printf("Total score(lenght of the snake): %d\n", m);
    printf("Total moves: %d\n", hamle);
    printf("It was fun to play with you. See you soon. :):) :) (Enter R to play again Enter a different thing to exit): ");
    scanf(" %s", &anything);
}
while (strcmp(anything, "R") == 0);
    
    return 0;
}
