#include "mainFunctions.cpp"

int main()
{
    string playerXName;
    string playerOName;
    string winner;

    cout<<"Player X, Enter your name: "<<endl;
    cin>>playerXName;
    Player playerX = Player{playerXName, Piece::X};


    cout<<"Player O, Enter your name: "<<endl;
    cin>>playerOName;
    Player playerO = Player{playerOName, Piece::O};

    Board board;
    
    while (true) 
    {            
        move(board, playerX);
        board.display();

        if (WinnerResult result = board.checkWinner(); result.status == Status::Winner)
        {
            winner = playerX.name;
            break;
        }

        move(board, playerO);
        board.display();
        if (WinnerResult result = board.checkWinner(); result.status == Status::Winner)
        {
            winner = playerO.name;
            break;
        }
    }

    cout<<"Winner: "<<winner<<endl;
    return 0;
}

