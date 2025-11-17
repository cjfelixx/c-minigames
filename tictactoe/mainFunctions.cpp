#include "mainClasses.cpp"

void move(Board& board, Player& player);

void move(Board& board, Player& player)
{
    string position;
    while (true)
    {
        cout<< player.getName() + ", choose a position: ";
        cin>>position;
        auto coordinates = board.getCoordinates(position);
        if (!coordinates)
        {
            cout<<"Invalid";
            continue;
        }
        auto [r, c] = *coordinates;
        if (!board.setPiece(r, c, player.getPiece()))
        {
            continue;
        }
        break;
    }
}