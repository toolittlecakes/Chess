#include "../Figures/Board.h"

Board::Board()
:board(8, std::vector<int>(8,0))
{
    SetInitialPositions();
    InitialBusyCages();
}

void Board::SetInitialPositions()
{
     for(int i = 1; i < 2; i++)
     {
        for(int j = 0; j < 8; j++)
        {
            Pawn temp;
            temp.SetColor(Color::White);
            positions_of_figures.insert({{i,j}, &temp});

            Pawn temp2;
            temp2.SetColor(Color::Black);
            positions_of_figures.insert({{i+5, j}, &temp2});
        }
     }

     // Rook
     Rook r1;
     r1.SetColor(Color::White);
     positions_of_figures.insert({{0,0}, &r1});

     Rook r2;
     r2.SetColor(Color::White);
     positions_of_figures.insert({{0,7}, &r2});

     Rook r3;
     r3.SetColor(Color::Black);
     positions_of_figures.insert({{7,0}, &r3});

     Rook r4;
     r4.SetColor(Color::Black);
     positions_of_figures.insert({{7,7}, &r4});

     // Knight
     Knight k1;
     k1.SetColor(Color::White);
     positions_of_figures.insert({{0,1}, &k1});

     Knight k2;
     k2.SetColor(Color::Black);
     positions_of_figures.insert({{7,1}, &k2});

     Knight k3;
     k3.SetColor(Color::White);
     positions_of_figures.insert({{0,6}, &k3});

     Knight k4;
     k4.SetColor(Color::Black);
     positions_of_figures.insert({{7,6}, &k4});

     // Bishop
     Bishop b1;
     b1.SetColor(Color::White);
     positions_of_figures.insert({{0,2}, &b1});

     Bishop b2;
     b2.SetColor(Color::Black);
     positions_of_figures.insert({{7,2}, &b2});

     Bishop b3;
     b3.SetColor(Color::White);
     positions_of_figures.insert({{0,5}, &b3});

     Bishop b4;
     b4.SetColor(Color::Black);
     positions_of_figures.insert({{7,5}, &b4});

     // Queen 
     Queen q1;
     q1.SetColor(Color::White);
     positions_of_figures.insert({{0,3}, &q1});

     Queen q2;
     q2.SetColor(Color::Black);
     positions_of_figures.insert({{7,3}, &q2});


     // King
    //  King ki1;
    //  positions_of_figrues.insert({{0,4}, ki1});

    //  King ki2;
    //  positions_of_figrues.insert({{7,4}, ki2});  
} 

void Board::InitialBusyCages()
{

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = 1;
            board[i+6][j] = -1;
        }   
    }
}

int Board::CheckBusyOrNot(const std::pair<int, int>& coord)
{
    return board[coord.first][coord.second];
}


void Board::MoveFigure(Figure* f, const std::pair<int, int>& current, const std::pair<int, int>& new_pos)
{
    auto it = positions_of_figures.find(current);

    if(it == positions_of_figures.end()){return ;}

    if(!f->ValidOrNot(current, new_pos, *this)) {return ;}

    board[current.first][current.second] = 0;

    if(f->GetColor() == -1)
    {
        if(board[new_pos.first][new_pos.second] == 1)
        {
            positions_of_figures.erase(new_pos);
        }

        board[new_pos.first][new_pos.second] = -1;
    } 
    else if(f->GetColor() == 1) 
    {
        if(board[new_pos.first][new_pos.second] == -1)
        {
            positions_of_figures.erase(new_pos);
        }
        board[new_pos.first][new_pos.second] = 1;
    }

    positions_of_figures.insert({new_pos, it->second});
    positions_of_figures.erase(it->first);

  //  std::cout << positions_of_figures.size();
}


void Board::DisplayBoard()
{
    for(int i = board.size()-1; i >= 0; i--)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            std::cout << board[i][j] << "\t";    
        }
        std::cout << "\n\n" ;
    }

    std::cout << positions_of_figures.size();
}