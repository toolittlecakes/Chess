#include "../Figures/Queen.h"
#include "../Figures/Bishop.h"
#include "../Figures/Board.h"
#include "../Figures/Knight.h"


int main()
{
    Board b;
  
    b.MoveFigure(new Pawn(Color::White), {1, 0}, {3, 0});

    b.MoveFigure(new Pawn(Color::Black), {6,1}, {4, 1});

    b.MoveFigure(new Pawn(Color::White), {3,0}, {4,1});

    b.DisplayBoard();

}