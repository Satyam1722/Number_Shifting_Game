#include<stdio.h>
#include<string.h>
#include<conio.h>
int blank[2];
int level;

void home()
{
    int a[4][4]=
    {
        {
            1,2,3,4
        },
        {
            5,6,7,8
        },
        {
            9,10,11,12
        },
        {
            13,14,15,0
        }
    };

    printf("\t\t\t RULE OF THIS GAME\n");
    printf("1.You can move only 1 step at a time by arrow key\n");
    printf("Move Up      :by Up arrow key\n");
    printf("Move Down    :by Down arrow key\n");
    printf("Move Left    :by left arrow key\n");
    printf("Move Right   :by Right arrow key\n");
    printf("\n2.You can move number at empty position only\n");
    printf("\n3.for each valid move : your total number of move will decresed by 1\n");

    if(level==1)
        printf("\n4.Winning situation : number in a 3*3 matrix should be in order from 1 to 15\n");
    else
        printf("\n4.Winning situation : number in a 4*4 matrix should be in order from 1 to 15\n");

    printf("\n\n\t\tWinning Situation : \n");


    if(level==1)
        {
            printf("\n----------------\n");

            for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                        {
                            if(i==2&&j==2)
                                printf("| %-2c ",' ');
                            else
                                printf("| %-2d ",a[i][j]-i);

                        }
                    printf("|\n");
                }
            printf("----------------\n");

        }
    else
        {
            printf("\n---------------------\n");

            for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                        {
                            if(i==3&&j==3)
                                printf("| %-2c ",' ');
                            else
                                printf("| %-2d ",a[i][j]);

                        }
                    printf("|\n");
                }
            printf("---------------------\n");
        }


    printf("\n5.You can exit the game at any time by pressing 'E' or 'e'\n");
    printf("So Try to win in minimum no of move\n");
    printf("\n\tHappy Gaming , Good Luck\n\n");
    system("pause");

}
int check(int a[4][4])
{
    int i,j,count=1;
    int b[4][4]=
    {
        {
            1,2,3,4
        },
        {
            5,6,7,8
        },
        {
            9,10,11,12
        },
        {
            13,14,15,0
        }
    };


    if(level==1){
         for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
                {
                    if(a[i][j]!=b[i][j])
                        return 0;
                    if(i==2&&j==2)
                        return 1;

                }
        }
    }
    else{
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
                {
                    if(a[i][j]!=b[i][j])
                        return 0;

                }
        }
    }

    return 1;

}

void display(int a[4][4])
{
    int i,j;
    printf("\n");

    if(level==1)
        {
            printf("\n----------------\n");
            for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                        {
                            if(i==blank[0]&&j==blank[1])
                                printf("| %-2c ",' ');
                            else
                                printf("| %-2d ",a[i][j]);

                        }
                    printf("|\n");
                }
            printf("----------------\n");
        }
    else
        {
            printf("\n---------------------\n");
            for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                        {
                            if(i==blank[0]&&j==blank[1])
                                printf("| %-2c ",' ');
                            else
                                printf("| %-2d ",a[i][j]);

                        }
                    printf("|\n");
                }
            printf("---------------------\n");
        }
}

void move(int a[4][4])
{
    char c;
    fflush(stdin);
    getch();
    c=getch();


    if(c=='e'|| c=='E')
        exit(0);
    if(c==77)
        {
            if(blank[1]-1<0)
                {
                    printf("Enter Valid Move!\n");
                    move(a);
                    return ;
                }
            a[blank[0]][blank[1]]=a[blank[0]][blank[1]-1];
            blank[1]--;
            a[blank[0]][blank[1]]=0;
        }
    if(c==80)
        {
            if(blank[0]-1<0)
                {
                    printf("Enter Valid Move!\n");
                    move(a);
                    return;
                }
            a[blank[0]][blank[1]]=a[blank[0]-1][blank[1]];
            blank[0]--;
            a[blank[0]][blank[1]]=0;
        }
    if(c==75)
        {
            if((blank[1]+1>3 && level==2) || (blank[1]+1>2 && level==1))
                {
                    printf("Enter Valid Move!\n");
                    move(a);
                    return;
                }
            a[blank[0]][blank[1]]=a[blank[0]][blank[1]+1];
            blank[1]++;
            a[blank[0]][blank[1]]=0;
        }
    if(c==72)
        {
            if((blank[0]+1>3 && level==2)||(blank[0]+1>2 && level==1))
                {
                    printf("Enter Valid Move!\n");
                    move(a);
                    return;
                }
            a[blank[0]][blank[1]]=a[blank[0]+1][blank[1]];
            blank[0]++;
            a[blank[0]][blank[1]]=0;
        }

}
int main()
{
    system("cls");
    int a[4][4]= {0},flag=0,moves=400;
    int f[16]= {0};
    char name[20];
    printf("enter Player Name :: \n");
    fgets(name,20,stdin);
    name[strlen(name)-1]='\0';
    srand(time(0));

    do
        {
            printf("\n\nenter level : \n\n");
            printf("1. 3*3 matrix game\n");
            printf("2. 4*4 matrix game\n");
            scanf("%d",&level);
            printf("\n\n");
            blank[0]=2;
            blank[1]=2;
            if(level==1)
                {
                      blank[0]=2;
                      blank[1]=2;
                    for(int i=0; i<3; i++)
                        {
                            for(int j=0; j<3; j++)
                                {
                                    if(i==2&&j==2)
                                        {
                                            flag=1;
                                            break;
                                        }
                                    while(a[i][j]==0)
                                        {
                                            int n=rand()%8+1;
                                            if(f[n]==0)
                                                {
                                                    f[n]++;
                                                    a[i][j]=n;
                                                }
                                        }
                                }
                            if(flag)
                                break;
                        }
                }
            else if(level==2)
                {
                       blank[0]=3;
                       blank[1]=3;
                    for(int i=0; i<4; i++)
                        {
                            for(int j=0; j<4; j++)
                                {
                                    if(i==3&&j==3)
                                        {
                                            flag=1;
                                            break;
                                        }
                                    while(a[i][j]==0)
                                        {
                                            int n=rand()%15+1;
                                            if(f[n]==0)
                                                {
                                                    f[n]++;
                                                    a[i][j]=n;
                                                }
                                        }
                                }
                            if(flag)
                                break;
                        }
                }
            else
                printf("Enter Valid level\n");
        }while(level!=1&&level!=2);



    home();

    while(1)
        {
            system("cls");
            printf("\n\nHello %s , Move remaining : %d\n\n",name,moves);
            display(a);
            move(a);
            moves--;

            if(check(a))
                {
                    printf("Congratulation  %s ! You Won",name);
                    exit(0);
                }
        }


    return 0 ;
}
