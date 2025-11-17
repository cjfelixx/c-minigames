#include <iostream>
#include <optional>

using namespace std;

class Board {
    private:
        static const int SIZE = 4;
        char board[SIZE][SIZE];
        const string X_COORDINATE_VALUES = "ABCD";
        static const char EMPTY_PIECE = '-';

    public:
        Board();
        void display();
        bool setPiece(int row, int col, char piece);
        optional<pair<int, int>> getCoordinates(string positionIn);
        bool checkWinner(char piece);
};

Board::Board()
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            board[r][c] = EMPTY_PIECE;
        }
    }
}

void Board::display()
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            cout<<board[r][c];
        }
        
        cout<<endl;
    }
}

bool Board::setPiece(int row, int col, char piece)
{    
    if (board[row][col] != EMPTY_PIECE)
    {
        cout<<"Position already placed."<<endl;
        return false;
    }

    board[row][col] = piece;
    return true;
}

optional<pair<int, int>> Board::getCoordinates(string positionIn)
{
    if (string(X_COORDINATE_VALUES).find(positionIn[0]) == string::npos)
    {
        cout<<"Not a valid X position"<<endl;;
        return nullopt;
    }

    if (!isdigit(positionIn[1]))
    {
        cout<<"Not a valid Y position"<<endl;
        return nullopt;
    }

    int x = (positionIn[0] - 'A');
    int y = positionIn[1] - '0' - 1;

    if ((x < 0 || x > SIZE) || (y < 0 || y > SIZE))
    {
        cout<<"Coordinates must be within bounds of a 4 by 4 grid."<<endl;
        return nullopt;
    }

    return pair{x, y};
}


bool Board::checkWinner(char piece)
{
    // Horizontal
    for (int r = 0; r < SIZE; r++)
    {
        int count = 0;
        for (int c = 0; c < SIZE; c++)
        {
            if (board[r][c] == piece)
            {
                count++;
            }
        }
        if (count == SIZE)
        {
            return true;
        }
    }
    // Vertical

    for (int c = 0; c < SIZE; c++)
    {
        int count = 0;
        for (int r = 0; r < SIZE; r++)
        {
            if (board[r][c] == piece)
            {
                count++;
            }

            if (count == SIZE)
            {
                return true;
            }
        }
    }
    // Diagonal
    int forwardCount = 0;
    int backwardsCount = 0;

    for (int i =0; i < SIZE; i++)
    {
        if (board[i][i] == piece)
        {
            forwardCount++;
        }
        if (board[SIZE-i-1][SIZE-i-1] == piece)
        {
            backwardsCount++;
        }
    }

    if (forwardCount == SIZE || backwardsCount == SIZE)
    {
        return true;
    }

    return false;
}

class Player {
    private:
        string name;
        char piece;

    public:
        Player(string nameIn, char pieceIn)
        {
            name = nameIn;
            piece = pieceIn;
        }

        string getName()
        {
            return name;
        }

        char getPiece()
        {
            return piece;
        }
};
