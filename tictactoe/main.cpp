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
    
    while (true) 
    {            
        move(board, playerX);
        board.display();

        if (board.checkWinner(playerX.getPiece()))
        {
            winner = playerX.getName();
            break;
        }

        move(board, playerO);
        board.display();
        if (board.checkWinner(playerO.getPiece()))
        {
            winner = playerO.getName();
            break;
        }
    }

    cout<<"Winner: "<<winner<<endl;
    return 0;
}

