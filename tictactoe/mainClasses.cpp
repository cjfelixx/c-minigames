#include <iostream>
#include <optional>

using namespace std;

enum class Status 
{
    Ongoing,
    Draw,
    Winner,
};

enum class Piece
{
    X,
    O,
    EMPTY
};

struct Player 
{
    string name;
    Piece piece;
};

struct WinnerResult
{
    optional<Player> winner;
    Status status;
};

class Board {
    private:
        static const int SIZE = 4;
        Piece board[SIZE][SIZE];
        const string X_COORDINATE_VALUES = "ABCD";
        static const Piece EMPTY_PIECE = Piece::EMPTY;
        static string to_string(Piece p);

    public:
        Board();
        void display();
        bool setPiece(int row, int col, Piece piece);
        optional<pair<int, int>> getCoordinates(string positionIn);
        WinnerResult checkWinner();
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
            cout<<to_string(board[r][c]);
        }
        cout<<endl;
    }
}

bool Board::setPiece(int row, int col, Piece piece)
{    
    if (board[row][col] != Piece::EMPTY)
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

WinnerResult Board::checkWinner()
{
    // Horizontal    
    for (int r = 0; r < SIZE; r++)
    {
        Piece piece = board[r][0];
        if (piece == Piece::EMPTY) continue;
        int count = 0;
        for (int c = 0; c < SIZE; c++)
        {
            if (board[r][c] == piece)
            {
                count++;
                continue;
            }
        }
        if (count == SIZE)
        {
            return {nullopt, Status::Winner};
        }
    }

    // Vertical
    for (int c = 0; c < SIZE; c++)
    {
        Piece piece = board[0][c];
        if (piece == Piece::EMPTY) continue;
        int count = 0;
        for (int r = 0; r < SIZE; r++)
        {
            if (board[r][c] == piece)
            {
                count++;
                continue;
            }

            if (count == SIZE)
            {
                return {nullopt, Status::Winner};
            }
        }
    }

    // Diagonal
    int forwardCount = 0;
    int backwardsCount = 0;
    Piece forwardPiece = board[0][0];
    Piece backwardsPiece = board[0][SIZE-1];
    for (int i =0; i < SIZE; i++)
    {
        if (forwardPiece == Piece::EMPTY) continue;
        if (backwardsPiece == Piece::EMPTY) continue;
        
        if (board[i][i] == forwardPiece)
        {
            forwardCount++;
            continue;
        }
        if (board[SIZE-i-1][SIZE-i-1] == backwardsPiece)
        {
            backwardsCount++;
            continue;
        }
    }

    if (forwardCount == SIZE || backwardsCount == SIZE)
    {
            return {nullopt, Status::Winner};
    }

    return {nullopt, Status::Ongoing};
}

string Board::to_string(Piece p)
{
    switch (p)
    {
        case Piece::X:      return "X";
        case Piece::O:      return "O";
        case Piece::EMPTY:  return "-";
    }
    return "UNKNOWN";
};
