#include<stdio.h> //rand(), kbhit()
// #include<conio.h>
#include<stdlib.h>

int x, y, gameOver, score, flag, fruitX, fruitY;

void draw(int n1, int n2)

{
    int i, j;
    system("cls"); 
    for(i=0; i<n1; i++)
    {
        for(j=0; j<n2; j++)
        {
            if((i==0)||(i==n1-1)||j==0||j==n2-1)
            {
                printf("#");
            }
            else 
            {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitX && j == fruitY)
                    printf("*");
                else
                    printf(" ");
            }    
        
        }
        printf("\n");
    }
    printf("\n");
}

void setup(int n1, int n2)
{
    gameOver = 0; score = 0;
    x = n1/2; y = n2/2;
    label1:
    fruitX = rand()%n1;
    if(rand()%n1==0) {goto label1;}
    
    label2:
    fruitY = rand()%n2;
    if(rand()%n2==0) {goto label2;}
}

void input()
{
    char input;
	
    scanf("%c", &input);
    {
        flag = 0;
        switch(input)
        {
            case 'w':
            flag = 1; break;
            case 's':
            flag = 2; break;
            case 'a':
            flag = 3; break;
            case 'd':
            flag = 4; break;
            case 'x':
            gameOver = 1; break;
        }
        

    }
}

void logic(int flag, int n1, int n2)
{
    switch(flag)
    {
        case 1:
        x--; break;
        case 2:
        x++; break;
        case 3:
        y--; break;
        case 4:
        y++; break;
    }
    if(x<=0||x>=n1-1||y<=0||y>=n2-1) {gameOver = 1;}
        
        if(x==fruitX && y==fruitY)
        {
            score+=10;
            label1:
            fruitX = rand()%n1;
            if(fruitX==0) {goto label1;}
            label2:
            fruitY = rand()%n2;
            if(fruitY==0) {goto label2;}
            
        }
    
}

int main()
{   
    int n1=20, n2=20;
    //printf("enter square grid side length:"); scanf("%d%d", &n1, &n2);
    setup(n1, n2);

    while(!gameOver)
    {
        draw(n1, n2);
        
        printf("Score:%d", score);
        printf("\n");

        input();
        logic(flag, n1, n2);


    }
    printf("Final Score:%d",score);
    return 0;
}