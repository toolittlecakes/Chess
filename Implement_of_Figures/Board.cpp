#include "../Figures/Board.h"
#include<vector>
#include<map>

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

            positions_of_figures.insert({{i,j}, new Pawn(Color::White)});

            Pawn temp2(Color::Black);
            positions_of_figures.insert({{i+5, j}, new Pawn(Color::Black)});
        }
     }

     // Rook
     positions_of_figures.insert({{0,0}, new Rook(Color::White)});

     Rook r2(Color::White);
     positions_of_figures.insert({{0,7}, new Rook(Color::White)});

     Rook r3(Color::Black);
     positions_of_figures.insert({{7,0}, new Rook(Color::Black)});

     Rook r4(Color::Black);
     positions_of_figures.insert({{7,7}, new Rook(Color::Black)});

     // Knight
     positions_of_figures.insert({{0,1}, new Knight(Color::White)});

     positions_of_figures.insert({{7,1}, new Knight(Color::Black)});

     positions_of_figures.insert({{0,6}, new Knight(Color::White)});

     positions_of_figures.insert({{7,6}, new Knight(Color::Black)});

     // Bishop
     positions_of_figures.insert({{0,2}, new Bishop(Color::White)});

     positions_of_figures.insert({{7,2}, new Bishop(Color::Black)});

     positions_of_figures.insert({{0,5}, new Bishop(Color::White)});

     positions_of_figures.insert({{7,5}, new Bishop(Color::Black)});

     // Queen 
     positions_of_figures.insert({{0,3}, new Queen(Color::White)});

     positions_of_figures.insert({{7,3}, new Queen(Color::Black)});


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
}


void Board::DisplayBoard()
{
    for(int i = board.size()-1; i >= 0; i--)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            auto it = positions_of_figures.find({i,j});

            if(it == positions_of_figures.end())
            { 
                std::cout << board[i][j] << "\t"; 
            }

           else if(typeid(*it->second) == typeid(Rook))
            {
                std::cout << 'R' << "\t"; 
            } 

            else if (typeid(*it->second) == typeid(Pawn))
            {
                std::cout << 'P' << "\t"; 
            }

            else if(typeid(*it->second) == typeid(Queen))
            {
                std::cout << 'Q' << "\t"; 
            }

            else if(typeid(*it->second) == typeid(Bishop))
            {
                std::cout << 'B' << "\t"; 
            }

            else if(typeid(*it->second) == typeid(Knight))
            {
                std::cout << "Kn" << "\t"; 
            } 
        }
        std::cout << "\n\n" ;
    }
}