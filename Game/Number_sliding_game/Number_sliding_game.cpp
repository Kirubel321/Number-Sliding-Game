// 3X3 Number sliding game by using Doubly linked list
#include <iostream>
#include <ctime>          //For timein the randomizetion of the characters
#include <conio.h>      //console input output header file for getch() and system("cls")
#include <stdlib.h>     // For srand() and rand()   n color
#include <iomanip>    // setfill() function
#include <windows.h>   //For sleep() function     color

using namespace std;

struct PuzzleTile{  //We have defined the puzzleTile structure with four members data, TileNo, Next pointer and previous pointer
	char data;
	int TileNo;
	PuzzleTile* next;
	PuzzleTile* Prev;
}*head=NULL,*tail=NULL;  // And then define the puzzleTile pointer head and Tail set it to NULL.

bool sort;  //We have declare bool sort for checking the while loop
char ArryToCheck[9] = {'1','2','3','4','5','6','7','8',' '};   // We have declare ArryToCheck to check the array in every single move 

//We have declare four function by the name CreateTile, Randomize, PrintTile, Move.

void CreateTile(char arry[]);									// To create the Puzzle Tile
void Randomize(char arry[], int n);                             // To Randomizing the characters in the board
void PrintTile();                                               // To Print the Tile
void Move(char TMove);                                          // To Move the Tile
void welcome();

int main() {
	system("color 0C");
 	welcome();
    cout<<"\t\t\t\t _____________________________________________________\n";
    cout<<"\t\t\t\t |                    1 for play                      |\n";
    cout<<"\t\t\t\t |                    2 for quit                      |\n";
    cout<<"\t\t\t\t |____________________________________________________|\n";

	 int a;
	 cin>>a;
	 system ("cls");
	 if(a==1){
	        cout<<"LODING"<<".";Sleep(100);
	         cout<<".";Sleep(100);
	          cout<<".";Sleep(100);
	           cout<<".";Sleep(100);
	            cout<<".";Sleep(100);
	        cout<<endl;
	        system("cls");
			sort=false;
			char str; 
			char arry[9] = {'1','2','3','4','5','6','7','8',' '};
			Randomize(arry,9);   //Randomizing the characters 
			CreateTile(arry);    //Create Tile by setting the randomized character to the puzzel tile
					do{
							do {
								char TMove;
								PrintTile();  // Print the puzzle tile 
								cout << endl <<"\t\t w = Up, s = Down, a = Left, d = Right" << endl;   //Print the instruction to play the game
								TMove = getch();                      //To take character from keyboard
								Move(TMove);                          //Pass the character to move function
								system("cls");   	                 //Uses to clear the consol in every iteration 
							} while(sort==false);
						cout<<"Press 'R' or 'r' to play again or press any key to quit: ";
						cin>>str;
					}while(str=='R' || str=='r');		
	}
	else{
    cout<<"thank you "<<endl;
    return 0;
	}
	return 0;
}

void welcome(){
    cout<<"\n\n\n";
    cout<<"\t"<<setfill('-')<<setw(62)<<""; Sleep (100);
    cout<<endl<<"\t|                                                             |"; Sleep (100);
    cout<<endl<<"\t|                                            -----------    N |"; Sleep (100);
    cout<<endl<<"\t| N     |-|       |        |            |    |   ----  |    U |"; Sleep (100);
    cout<<endl<<"\t| U     |   |     |        |            |    |   |  |  |    M |"; Sleep (100);
    cout<<endl<<"\t| M     |    |    |        |            |    |   ----  |    B |"; Sleep (100);
    cout<<endl<<"\t| B     |     |   |        |            |    |  --------    E |"; Sleep (100);
    cout<<endl<<"\t| E     |      |  |        |            |    |  |           R |"; Sleep (100);
    cout<<endl<<"\t| R     |       |_|        |____________|    |  |             |"; Sleep (100);
    cout<<endl<<"\t|                                            ----             |"; Sleep (100);
    cout<<endl<<"\t|                 S L I D E R P U Z Z L E S                   |"; Sleep (100);
    cout<<endl<<"\t"<<setw(62)<<""<<setfill('-')<<endl;
    cout<<"\n\n\n";
    system("PAUSE");
    system("cls");
}

void CreateTile(char arry[]){
		PuzzleTile* Tile = new PuzzleTile;
		if(head == NULL)
		{
		head = Tile;
		tail = Tile;
		Tile->data = arry[0];
		Tile->TileNo=1;
		Tile->next=NULL;
		Tile->Prev=NULL;
		}
		PuzzleTile* itemp=head;	
		for(int i=1; i<9; i++)
		{
			while(itemp->next != NULL)
			{
				itemp=itemp->next;
			}
			Tile = new PuzzleTile;
			itemp->next = Tile;
			Tile->data = arry[i];
			Tile->next = NULL;
			Tile->Prev = itemp;
			Tile->TileNo = ((itemp->TileNo)+1);
		}	
		tail=Tile;
}

void Randomize (char arry[],int n){ 
	int j;
    srand (time(0));   // Initialize random number generator. at the beginning of the program to initialize the random seed. time(0) returns the integer number of seconds from the system clock.
    for(int i=n-1; i>0; i--)
    {
   		j=rand()%(i+1);
   		swap(arry[i],arry[j]);
    }
}
void PrintTile(){
	PuzzleTile* ptemp=head;
	cout<<"\t\t\t";
		for(int i=0; i<3; i++)
		{
			cout<<"  ___________\n";
			cout<<"\t\t\t";
			for(int j=0; j<3; j++)
			{
				cout<<" | "<<ptemp->data;
				ptemp=ptemp->next;
			}
			cout<<" | "<<endl;
			cout<<"\t\t\t";
		}
		cout<<"  ___________\n";
		ptemp = NULL;
}

void Move(char TMove){
	PuzzleTile* temp_1 = head;    //We have defined puzzleTile pointers temp_1 and Temp_2 and set temp_1 to head
	PuzzleTile* temp_2;
			if(TMove == 'w' || TMove == 'W'){
				while(temp_1->data != ' ')   //Keep moving temp_1 to its next tile until it reaches space character.
				{
					temp_1 = temp_1->next;
				}
				if(temp_1->TileNo!=7 && temp_1->TileNo!=8 && temp_1->TileNo!=9)
				{
					temp_2 = temp_1;    //set temp_1 to temp_2
					while(temp_2->TileNo!=(temp_1->TileNo+3)) //Keep moving temp_2 to its next tile until it reaches Temp_1 TileNo + 3. 
					{
						temp_2=temp_2->next;
					}
					temp_1->data = temp_2->data; // Finally set temp_2->data to temp_1->data and space character to temp-2->data.
					temp_2->data = ' ';
				}
				
			}
			else if(TMove == 's' || TMove == 'S'){
				while(temp_1->data != ' ')      //Keep moving temp_1 to its next tile until it reaches space character.
				{
					temp_1=temp_1->next;
				}
				if(temp_1->TileNo!=1 && temp_1->TileNo!=2 && temp_1->TileNo!=3)
				{
					temp_2 = temp_1;
					while(temp_2->TileNo!=(temp_1->TileNo-3))  //Keep moving temp_2 to its previous tile until it reaches Temp_1 TileNo - 3. 
					{
						temp_2=temp_2->Prev;
					}
					temp_1->data = temp_2->data;      // Finally set temp_2->data to temp_1->data and space character to temp-2->data.
					temp_2->data = ' ';
				}
			}
			else if(TMove == 'a' || TMove == 'A'){
				while(temp_1->data != ' ')   //Keep moving temp_1 to its next tile until it reaches space character.
				{
					temp_1=temp_1->next;
				}
				if(temp_1->TileNo!=3 && temp_1->TileNo!=6 && temp_1->TileNo!=9)
				{
					temp_2 = temp_1;
					while(temp_2->TileNo!=(temp_1->TileNo+1))  //Keep moving temp_2 to its next tile until it reaches Temp_1 TileNo + 1. 
					{
						temp_2=temp_2->next;
					}
					temp_1->data = temp_2->data;     // Finally set temp_2->data to temp_1->data and space character to temp-2->data.
					temp_2->data = ' ';
				}
			}
			else if(TMove == 'd' || TMove == 'D'){
				while(temp_1->data != ' ')   //Keep moving temp_1 to its next tile until it reaches space character.
				{
					temp_1=temp_1->next;
				}
				if(temp_1->TileNo!=1 && temp_1->TileNo!=4 && temp_1->TileNo!=7)
				{
					temp_2 = temp_1;
					while(temp_2->TileNo!=(temp_1->TileNo-1))    //Keep moving temp_2 to its previous tile until it reaches Temp_1 TileNo - 1. 
					{
						temp_2=temp_2->Prev;
					}
					temp_1->data = temp_2->data;        // Finally set temp_2->data to temp_1->data and space character to temp-2->data.
					temp_2->data = ' ';
				}
			}
			PuzzleTile* temp_check = head;  
			char ArryCheck[9];														
			for(int i=0; i<9; i++)				//In every move the puzzleTile will copied the data to character ArrayCheck array and compare if it is sorted or not 
			{
				ArryCheck[i] = temp_check->data;
				temp_check = temp_check->next;
			}
			if(ArryCheck == ArryToCheck)  //If it is sorted it display and exit from the while loop in the main function
			{
				sort = true;
				cout<<"Welldone! you have sort the numbers";
			}
			else
				sort = false;
}


