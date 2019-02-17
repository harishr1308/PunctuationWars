#include<time.h>
#include<iostream.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
char spaceship[61];
char yn;

void time2(float a);
void newgame();
char alien[5][60];

int heart=3;

int r;

int k=29;
int l=30;
int m=31;

char rankey;


void time(float a)
{
clock_t n1,n2;
n1=clock();
n2=clock();
for (;(n2-n1)/CLK_TCK<a;)
n2=clock();
}

void time2(float a)
{

clock_t n1,n2;
n1=clock();
n2=clock();
for (;(n2-n1)/CLK_TCK<a;)
	{

	if (getch()==rankey)
		{
		cout<<"You escaped!"<<endl;
		time(0.5);
		break;
		}
	else if (getch()!=rankey)
		{
		heart=heart-1;
		cout<<"You did! You did get hit!"<<endl;
		if (heart>0)
			{
			cout<<"Continue Playing."<<endl;
			}
		else
			{
			cout<<"Game over."<<endl;
			cout<<"Start again (Y/N) ?"<<endl;
			cin>>yn;
         if (yn=='Y'||yn=='y') newgame();
			}
		time(0.5);
      
		break;
		}
	n2=clock();
	}
}




void initialize()
{
for (int j=0; j<5; j++)
	{
	for (int k=0; k<60; k+=6)
		{
		alien[j][k]=' ';
		alien[j][k+1]='?';
		alien[j][k+2]='?';
		alien[j][k+3]='?';
		alien[j][k+4]=' ';
		alien[j][k+5]=' ';

		}
	}
spaceship[29]='/';
spaceship[30]='_';
spaceship[31]='\\';
}

void printalien()
{
for (int i=0; i<5; i++)
	{
	for (int j=0; j<60; j++)
		{
		cout<<alien[i][j];
		}
	cout<<endl;
	}
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
}

void printspaceship()
{
for (int i=0; i<61; i++)
	{
	cout<<spaceship[i];
	}
}

void alienlaser()
{
int rando=random(62);
int z=rando;
int rando2=random(26);
rankey=char(rando2+97);
::r=rando;
if (alien[0][r]==' ') goto C;
if (k==z||l==z||m==z)
	{
	cout<<"You got hit!"<<endl;
	time(1);

	cout<<"Press "<<rankey<<" twice!"<<endl;
   getch();
	time2(3);

	}
C:
}

void spaceshiplaser()
{
int i=::l;
int chk=0;
for (int j=4; j>=0; j--)
	{
	if (alien[j][i]=='?')
		{
		chk=j;
		break;
		}
	}
alien[chk][l]=' ';

}

void play()
{
//char move;
while (heart!=0)
	{
	B:
	getch();
 int kbhit(void);
  //	cin>>move;
		switch(getch())
		{
	//if (move=='a'||move=='A')
	  case 'a': case 'A':
		  {
		l--; k--; m--;
		for (int i=0; i<61; i++)
			{
			spaceship[i]=' ';
			}
		spaceship[k]='/';
		spaceship[l]='_';
		spaceship[m]='\\';
		clrscr();
		printalien();
      printspaceship();
		alienlaser();
		break;
		}

		case 'd': case 'D':
	//else if (move=='d'||move=='D')
		{
		l++; k++; m++;
		for (int i=0; i<61; i++)
			{
			spaceship[i]=' ';
			}
		spaceship[k]='/';
		spaceship[l]='_';
		spaceship[m]='\\';
		clrscr();
		printalien();
		printspaceship();
		alienlaser();    break;
		}

		case 'w': case 'W':
	//else if (move=='w'||move=='W')
	  {

		spaceshiplaser();
		clrscr();
		printalien();
		printspaceship();
		alienlaser();           break;
		}

		
	default :
		{
		
		goto B;
		}
  }
	if (k==0||l==0||m==0)
		{
		k=58;
		l=59;
		m=60;
		goto B;
		}
	if (k==60||m==60||l==60)
		{
		k=0;
		l=1;
		m=2;
		goto B;
		}
	}

}


void newgame()
{
initialize();
printalien();
printspaceship();
play();

}

void controls()
{
clrscr();
cout<<"these are the following controls to play the game"<<endl;
cout<<"to move the human spaceship :- "<<endl;
time(1);
cout<<"                                 a - left"<<endl;
time(1);
cout<<"                                 d - right"<<endl;
time(1);
cout<<"                                 w - fire laser"<<endl;
time(3);
}

void main()
{
int choice;
A:
clrscr();
cout<<"Welcome to Punctuation Wars!"<<endl;
cout<<"Choice:"<<endl;
cout<<"1. New Game.\n2. Instructions\n3.Exit."<<endl;
cin>>choice;
switch(choice)
	{
	case 1:
		{
		clrscr();
		newgame();
		break;
		}
	case 2:
		{
		cout<<" "<<endl;
		controls();
		
		goto A;
		
		}
	case 3:
		{
		exit(0);
		break;
		}
	default:
		{
		break;
		}
	}
}