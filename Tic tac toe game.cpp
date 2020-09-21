 ///Our TIc TAC TOE GAME
#include<bits/stdc++.h>
using namespace std;
char board[9]= {'-','-','-','-','-','-','-','-','-'};
char winner='n';
bool game_run=true;
char player1='X';
char player2='M';
string name1,name2;
bool play_again=false;
void display()
{
    for(int i=1;i<=10;i++)
        cout << "    ";
    cout << board[0] << "|" << board[1] << "|" << board[2] << endl ;
    for(int i=1;i<=10;i++)
        cout << "    ";
    cout << board[3] << "|" << board[4] << "|" << board[5] << endl ;
    for(int i=1;i<=10;i++)
        cout << "    ";
    cout << board[6] << "|" << board[7] << "|" << board[8]<< endl ;

}
//check either winner is in the row
void find_row()
{
    if(board[0]==board[1]&&board[1]==board[2]&&board[2]!='-')
    {
         if(board[0]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout  << " is winner " << endl ;
        game_run=false;
    }
    else if(board[3]==board[4]&&board[4]==board[5]&&board[5]!='-')
    {
         if(board[3]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout  << " is winner " << endl ;
        game_run=false;

    }
    else if(board[6]==board[7]&&board[7]==board[8]&&board[8]!='-')
    {
         if(board[6]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout  << " is winner" << endl ;
        game_run=false;

    }
}
//check the column either winner is on the column
void find_column()
{

    if(board[0]==board[3]&&board[3]==board[6]&&board[6]!='-')
    {
         if(board[0]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout  << " is winner " << endl ;
        game_run=false;
    }
    else if(board[1]==board[4]&&board[4]==board[7]&&board[7]!='-')
    {
         if(board[1]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout  << " is winner " << endl ;
        game_run=false;

    }
    else if(board[2]==board[5]&&board[5]==board[8]&&board[8]!='-')
    {
         if(board[2]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout << " is winner" << endl ;
        game_run=false;

    }
}
//check the diagonal
void find_diagonal()
{

    if(board[0]==board[4]&&board[4]==board[8]&&board[8]!='-')
    {
        if(board[0]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout << " is winner " << endl ;
        game_run=false;
    }
    else if(board[2]==board[4]&&board[4]==board[6]&&board[6]!='-')
    {
         if(board[2]=='X')
        cout << name1 ;
        else
            cout << name2;
        cout  << " is winner " << endl ;
        game_run=false;

    }

}
//if all the dash is full with x or m then it is tie
void is_tie()
{
    if(board[0]!='-'&&board[1]!='-'&&board[2]!='-'&&board[3]!='-'&&board[4]!='-'&&board[5]!='-'&&board[6]!='-'&&board[7]!='-'&&board[8]!='-')
    {
        cout << "Game Tie" << endl ;
        game_run=false;
    }
}
void start_game()
{
    display();
    while(game_run)
    {

        string  position;
         if(player1=='X')
        cout << name1 ;
        else
            cout << name2;
        cout << " 's turns" << endl;
        //now get the correct turn from user
        cout << "Choose a position between 1 to 9: " ;
        cin >> position;
        while(!((position[0]-'0')>=1&&(position[0]-'0')<=9)||position.size()>1)
        {
            cout << "Choose a correct position 1 to 9 : " ;
            cin >> position;
        }
        while(board[position[0]-'0'-1]!='-')
        {
            cout << "You can't go there Choose another 1 to 9 : ";
            cin >> position;
        }
        board[position[0]-'0'-1]=player1;
        system("CLS");
        display();
        swap(player1,player2);
        find_row();
        find_column();
        find_diagonal();
        //if game_run is false then we need not to check the tie
        if(game_run)
            is_tie();


    }

}
int main()
{
    cout << "Enter 1st player name : ";
    cin >> name1;
    cout << "Enter 2nd player name : ";
    cin >> name2;
    cout << endl;
    start_game();
}
