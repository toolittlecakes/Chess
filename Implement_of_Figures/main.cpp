#include "../Figures/Queen.h"
#include "../Figures/Bishop.h"
#include "../Figures/Board.h"
#include "../Figures/Knight.h"


int main()
{
    Board b;

    Knight k;
    k.SetColor(Color::White);

    Knight k2;
    k2.SetColor(Color::Black);


    b.DisplayBoard();

}