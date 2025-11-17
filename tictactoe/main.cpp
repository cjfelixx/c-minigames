#include "mainFunctions.cpp"

int main()
{
    string playerXName;
    string playerOName;
    string winner;

    cout<<"Player X, Enter your name: "<<endl;
    cin>>playerXName;
    Player playerX = Player(playerXName, 'X');


    cout<<"Player O, Enter your name: "<<endl;
    cin>>playerOName;
    Player playerO = Player(playerOName, 'O');

    Board board;
    
    bool game = true;

    while (game) 
    {            
        move(board, playerX);
        board.display();
        move(board, playerO);
        board.display();
    }
}

