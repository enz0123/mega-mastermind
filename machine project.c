/****************************************************************************** 
 
This is to certify that this project is my own work, based on my personal 
efforts in studying and applying the concepts learned.  I have constructed  
the functions and their respective algorithms and corresponding code by  
myself.  The program was run, tested, and debugged by my own efforts.  I  
further certify that I have not copied in part or whole or otherwise  
plagiarized the work of other students and/or persons. 
 
Joaquin Lorenzo T. Sitoy - 12273449 - S12A
 
 ******************************************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<unistd.h>

int fRandom()
{
    return (rand() % (6-1+1)) +1;
}

int fNextRound()
{
	int round,checkChar;
	printf("Input (1) to move to the next round.");
	
	do
	{
		checkChar=scanf(" %d",&round);
		fflush(stdin);
		
		if(checkChar!=1 || round!=1)
		printf("\n\nInvalid input. Please try again.\n\n");
		
	}while(round!=1||checkChar!=1);
	
	return round;
}

char fNumtoChar(int num)
{
    switch (num)
    {
        case 1: return 'B'; break;
        case 2: return 'O'; break;
        case 3: return 'G'; break;
        case 4: return 'P'; break;
        case 5: return 'Y'; break;
        case 6: return 'R'; break;
    }
    return num;
}

int introScreen()
{
    int pick,checkChar;
    do
    {
    printf("Welcome to Mega Mastermind!\n\n");
    printf("Press (1) to display instructions.\n");
    printf("Press (2) to start game.\n");
    printf("Press (3) to quit.\n");
    
    

    checkChar=scanf(" %d",&pick);
    fflush(stdin);
    if((pick!=1&&pick!=2&&pick!=3)||checkChar!=1)
    printf("\nInvalid Input. Please try again.\n\n");
    
    } while(pick<1||pick>3||checkChar!=1);

    switch(pick)
    {
        case 1: printf("\n\nInstructions\n\n"); break; /*put instructions here and option to start game or quit*/
        case 2: break;
        case 3: exit(0);break;
    }
    
    return pick;
}

int fGamesPlayed()
{
    int games,checkChar;
    printf("\n\nSelect number of games to be played (must be even, must be from 2 to 10): ");

    do
    {
    checkChar=scanf("%d",&games);
    fflush(stdin);
    if(games<2||games>10||games%2==1||checkChar!=1)
    printf("\n\nInvalid Input. Please try again.\n\n");
    }while(games<2||games>10||games%2==1||checkChar!=1);
    
    system("cls");
    return games;

}

void fCheckGuess(int peg1,int peg2,int peg3,int peg4, int AIpeg1, int AIpeg2, int AIpeg3, int AIpeg4)
{
    printf("\nResult: ");
    
    if(peg1==AIpeg1)
    printf("B ");
    else if(peg1==AIpeg2 || peg1==AIpeg3 || peg1==AIpeg4)
    printf("W ");

    if(peg2==AIpeg2)
    printf("B ");
    else if(peg2==AIpeg1 || peg2==AIpeg3 || peg2==AIpeg4)
    printf("W ");

    if(peg3==AIpeg3)
    printf("B ");
    else if(peg3==AIpeg2 || peg3==AIpeg1 || peg3==AIpeg4)
    printf("W ");

    if(peg4==AIpeg4)
    printf("B ");
    else if(peg4==AIpeg2 || peg4==AIpeg3 || peg4==AIpeg1)
    printf("W ");

}

int humanCodeMaker()
{
    /* 1. B for blue
       2. O for orange
       3. G for Green
       4. P for Purple
       5. Y for Yellow
       6. R for Red*/

    int peg1,peg2,peg3,peg4,gameNo,score,checkChar;
    int AIpeg1,AIpeg2,AIpeg3,AIpeg4;

    printf("\nPick 4 pegs (no duplicate pegs)\n1 for B\n2 for O\n3 for G\n4 for P\n5 for Y\n6 for R\n\n");

    do
    {

    checkChar=scanf("%d %d %d %d",&peg1,&peg2,&peg3,&peg4);
    fflush(stdin);

   if(peg1<1 || peg1>6 || peg2<1 || peg2>6 || peg3<1 || peg3>6 || peg4<1 || peg4>6 || peg1==peg2 || peg1==peg3 || peg1==peg4 || peg2==peg3 || peg2==peg4 || peg3==peg4 || checkChar != 4) 
   printf("Invalid Input. Please try again\n");

    } while(peg1<1 || peg1>6 || peg2<1 || peg2>6 || peg3<1 || peg3>6 || peg4<1 || peg4>6 || peg1==peg2 || peg1==peg3 || peg1==peg4 || peg2==peg3 || peg2==peg4 || peg3==peg4 || checkChar != 4);

    printf("\nYour peg order is: %c %c %c %c\n",fNumtoChar(peg1),fNumtoChar(peg2),fNumtoChar(peg3),fNumtoChar(peg4));

    for(gameNo = 1;gameNo<=10 && !(AIpeg1==peg1 && AIpeg2==peg2 && AIpeg3==peg3 && AIpeg4==peg4); gameNo++)
    {
        printf("\n\nAI guess no. %d: ",gameNo); /* guesses can still be duplicate*/
        
        sleep(1);
        sleep(1);

		
		
        AIpeg1=fRandom();

        do
        {
            AIpeg2=fRandom();
        } while (AIpeg2==AIpeg1);
        
        do
        {
            AIpeg3=fRandom();
        } while (AIpeg3==AIpeg2||AIpeg3==AIpeg1);
        
        do
        {
            AIpeg4=fRandom();   
        } while (AIpeg4==AIpeg1||AIpeg4==AIpeg2||AIpeg4==AIpeg3);

        printf("%c %c %c %c",fNumtoChar(AIpeg1),fNumtoChar(AIpeg2),fNumtoChar(AIpeg3),fNumtoChar(AIpeg4));

        fCheckGuess(peg1,peg2,peg3,peg4,AIpeg1,AIpeg2,AIpeg3,AIpeg4);

    }
    if(AIpeg1==peg1 && AIpeg2==peg2 && AIpeg3==peg3 && AIpeg4==peg4)
    {
        score=gameNo-1;
    }
    else
    {
        score=gameNo;
    }
    printf("\n\nHuman Player gets %d point/s.\n",score);  
    
    sleep(1);
    sleep(1);

    return score;
}

void displayCorrect(char peg1, char peg2, char peg3, char peg4, char AIpeg1, char AIpeg2, char AIpeg3, char AIpeg4)
{
    printf("\nResult: ");

    if(peg1==AIpeg1)
    printf("B ");
    else if(peg1==AIpeg2 || peg1==AIpeg3 || peg1==AIpeg4)
    printf("W ");

    if(peg2==AIpeg2)
    printf("B ");
    else if(peg2==AIpeg1 || peg2==AIpeg3 || peg2==AIpeg4)
    printf("W ");

    if(peg3==AIpeg3)
    printf("B ");
    else if(peg3==AIpeg2 || peg3==AIpeg1 || peg3==AIpeg4)
    printf("W ");

    if(peg4==AIpeg4)
    printf("B ");
    else if(peg4==AIpeg2 || peg4==AIpeg3 || peg4==AIpeg1)
    printf("W ");


}

int AICodeMaker()
{
    int AIint1,AIint2,AIint3,AIint4,score,checkChar;        /*done1**/
    char AIpeg1,AIpeg2,AIpeg3,AIpeg4;
    char peg1,peg2,peg3,peg4;
    int gameNo;

    AIint1=fRandom();
    
    do
    {
	AIint2=fRandom();
	} while(AIint2==AIint1);
    
    do
    {
	AIint3=fRandom();
	} while(AIint3==AIint2 || AIint3==AIint1);
    
    do
    { 
	AIint4=fRandom();
	} while(AIint4==AIint3 || AIint4==AIint2 || AIint4==AIint1);
   
	printf("\n%d %d %d %d\n\n",AIint1,AIint2,AIint3,AIint4); /*test*/

    AIpeg1=fNumtoChar(AIint1);
    AIpeg2=fNumtoChar(AIint2);
    AIpeg3=fNumtoChar(AIint3);
    AIpeg4=fNumtoChar(AIint4);          /*done2*/
    
    printf("\n\n%c %c %c %c\n\n",AIpeg1,AIpeg2,AIpeg3,AIpeg4); /*test*/
    
    printf("Choose 4 pegs for your guess (B - Blue, O - Orange, G - Green, P - Purple, Y - Yellow, R - Red)\n");

    for(gameNo=1;gameNo<=10 && !(AIpeg1==peg1 && AIpeg2==peg2 && AIpeg3==peg3 && AIpeg4==peg4)  ; gameNo++)
    {
    printf("\nTurn %d. Guess the pegs: ",gameNo);
    do
    {
       checkChar=scanf(" %c %c %c %c",&peg1,&peg2,&peg3,&peg4);
       fflush(stdin);

       peg1=toupper(peg1);
       peg2=toupper(peg2);
       peg3=toupper(peg3);
       peg4=toupper(peg4);

       if((peg1==peg2||peg1==peg3||peg1==peg4||peg2==peg3||peg2==peg4||peg3==peg4) || (peg1!='B' && peg1!='O' && peg1!='G' && peg1!='P' && peg1!='Y' && peg1!='R') || (peg2!='B' && peg2!='O' && peg2!='G' && peg2!='P' && peg2!='Y' && peg2!='R') || (peg3!='B' && peg3!='O' && peg3!='G' && peg3!='P' && peg3!='Y' && peg3!='R') || (peg4!='B' && peg4!='O' && peg4!='G' && peg4!='P' && peg4!='Y' && peg4!='R')||checkChar!=4)
       printf("\nInvalid Input. Please try again.\n");

    } while ((peg1==peg2||peg1==peg3||peg1==peg4||peg2==peg3||peg2==peg4||peg3==peg4)||(peg1!='B' && peg1!='O' && peg1!='G' && peg1!='P' && peg1!='Y' && peg1!='R') || (peg2!='B' && peg2!='O' && peg2!='G' && peg2!='P' && peg2!='Y' && peg2!='R') || (peg3!='B' && peg3!='O' && peg3!='G' && peg3!='P' && peg3!='Y' && peg3!='R') || (peg4!='B' && peg4!='O' && peg4!='G' && peg4!='P' && peg4!='Y' && peg4!='R')||checkChar!=4);
    
    displayCorrect(peg1,peg2,peg3,peg4,AIpeg1,AIpeg2,AIpeg3,AIpeg4);

    }

    if(AIpeg1==peg1 && AIpeg2==peg2 && AIpeg3==peg3 && AIpeg4==peg4)
    {
    	printf("\n\nYou guessed correctly!\n\n");
        score=gameNo-1;
    }
    else
    {
    	printf("\n\nAI's code was %c %c %c %c.\n\n",peg1,peg2,peg3,peg4);
        score=gameNo;
    }
    printf("\n\nAI gets %d point/s.\n",score);  
    
    sleep(1);
    sleep(1);
    sleep(1);

    return score;
}

int main()
{
    srand(time(NULL));
    int intro,gamesPlayed,gameNo,turn,round;
    int PlayerScore,AIScore;

    PlayerScore=0;
    AIScore=0;
    turn = 1;

    do
    {
        intro=introScreen(); 
    }while(intro==1);
   
    gamesPlayed=fGamesPlayed();

    for(gameNo=1;gameNo<=gamesPlayed;gameNo++)
    {
        if(turn==1)
        {
        	printf("\n\nGame No. %d\n\n",gameNo);
            PlayerScore=PlayerScore+humanCodeMaker();

			system("cls");
            printf("\n\nPlayer's Score  : %d",PlayerScore);
            printf("\nComputer's Score: %d\n\n",AIScore);
			
			round=fNextRound();
			round-=1;
            
            turn=0;
            system("cls");
        }
        else
        {
        	printf("\n\nGame No. %d\n\n",gameNo);
            AIScore=AIScore+AICodeMaker(); 

			system("cls");
            printf("\n\nPlayer's Score  : %d",PlayerScore);
            printf("\nComputer's Score: %d\n\n",AIScore);
            
            round=fNextRound();
			round-=1;
            
            turn=1;
            system("cls");
        }
        
    }

	printf("\n\nGame Over!");
	
    if(PlayerScore>AIScore)
    printf("\n\nCongratulations! You've Won.");
    else if(PlayerScore==AIScore)
    printf("\n\nIt's a tie!.");
    else
    printf("\n\nYou've lost :(");

    return 0;
}