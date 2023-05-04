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
            positions_of_figures.insert({{i+5, j}, new Pawn(Color::Black)});
        }
     }

     // Rook
     positions_of_figures.insert({{0,0}, new Rook(Color::White)});
     positions_of_figures.insert({{0,7}, new Rook(Color::White)});
     positions_of_figures.insert({{7,0}, new Rook(Color::Black)});
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


Figure* Board::GetFigure(const std::pair<int, int>& coord)
{
    auto it = positions_of_figures.find(coord);

    if(it == positions_of_figures.end())
    {
        return nullptr;
    }

    else {
        return it->second;
    }
}


void Board::MoveFigure(Figure* f, Color& color, const std::pair<int, int>& current, const std::pair<int, int>& new_pos)
{
    if(isKingUnderCheck(color) == true){}

    if(!Check(f, current, new_pos)){return ;}

    if(typeid(*f) == typeid(Pawn) || typeid(f) == typeid(Rook))
    {
        SpecialCases(f, current, new_pos);
        return ;
    }

    auto it = positions_of_figures.find(current);

    if(board[new_pos.first][new_pos.second] != 0)
    {
        positions_of_figures.erase(new_pos);
    } 

    board[current.first][current.second] = 0;
    board[new_pos.first][new_pos.second] = f->GetColor();
    positions_of_figures.insert({new_pos, f});
    positions_of_figures.erase(it->first); 

    if(isKingUnderCheck(color) == true) {
        positions_of_figures.erase({new_pos, f});
        positions_of_figures.insert({current, f});
        board
        return ;
    }
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


inline bool Board::Check(Figure* f, Color& color, const std::pair<int, int>& current, const std::pair<int, int>& new_pos)
{
    auto it = positions_of_figures.find(current);

    if(it == positions_of_figures.end()){return false;}
    if(it->second->GetColor() != color) {return false;}
    if(!f->ValidOrNot(current, new_pos, *this)) {return false;}

    return true;
}


void Board::SpecialCases(Figure* f, const std::pair<int, int>& current, const std::pair<int, int>& new_pos)
{
    if(typeid(*f) == typeid(Pawn))
    {
        if(board[new_pos.first][new_pos.second] == 0 && abs(new_pos.first - current.first) == abs(new_pos.second - current.second))
        {
            if(f->GetColor() == 1)
            {
                positions_of_figures.erase({new_pos.first - 1, new_pos.second});
                board[new_pos.first-1][new_pos.second] = 0;
            } 

            else if(f->GetColor() == -1) 
            {
                positions_of_figures.erase({new_pos.first + 1, new_pos.second});
                board[new_pos.first + 1][new_pos.second] = 0;
            }
        }

        if(board[new_pos.first][new_pos.second] != 0)
        {
            positions_of_figures.erase(new_pos);
        } 

        board[current.first][current.second] = 0;
        board[new_pos.first][new_pos.second] = f->GetColor();

        auto it = positions_of_figures.find(current);
        Pawn* temp = dynamic_cast<Pawn*>(it->second); 
        Pawn* ptr = new Pawn(it->second->GetColor());
        ptr->SetCount(temp->GetCount()+1);

        positions_of_figures.insert({new_pos, ptr});
        positions_of_figures.erase(it->first);
    }

    if(typeid(*f) == typeid(Rook))
    {

        if(board[new_pos.first][new_pos.second] != 0)
        {
            positions_of_figures.erase(new_pos);
        } 

        board[current.first][current.second] = 0;
        board[new_pos.first][new_pos.second] = f->GetColor();

        auto it = positions_of_figures.find(current);
        Rook* temp = dynamic_cast<Rook*>(it->second); 
        Rook* ptr = new Rook(it->second->GetColor());
        ptr->SetCount(temp->GetCount()+1);

        positions_of_figures.insert({new_pos, ptr});
        positions_of_figures.erase(it->first);
    }
}

bool Board::isKingUnderCheck(Color& color) {

    std::pair<int, int> king_pos;

    for(auto it : positions_of_figures)
    {
        if(it.second->GetColor() == color && typeid(it->second) == typeid(King))
        {
            king_pos = it.first;
            break;
        }
    } 

    for(auto it : positions_of_figures)
    {
        if(it.second != typeid(King) && it.second->GetColor() != color)
        {
            if(it.second->ValidOrNot() == true)
            {
                return true;
            }
        }
    }

    return false;
}


