#include "../Figures/Manager.h"


bool Manager(const std::string& figure, const FigureColor& color,  const std::string& current, const std::string& new_position,  Board& board)
{
    Figure* ptr_figure = nullptr;
    std::pair<int, int> _current;
    std::pair<int, int> _newPosition;

    if(current.size() == 2)
    {
        if(current[0] < 97 || current[0] > 104 || current[1] < 48 || current[1] > 57)
        {   
            return false;
        }

        else 
        {
            _current.first = current[1] - 49;
            _current.second = current[0] - 97;
        }
    } 

    else 
    {
        return false;
    }


    if(new_position.size() == 2)
    {
        if(new_position[0] < 97 || new_position[0] > 104 || new_position[1] < 48 || new_position[1] > 57)
        {   
            return false;
        }

        else 
        {
            _newPosition.first = new_position[1] - 49;
            _newPosition.second = new_position[0] - 97;
        }
    } 

    else 
    {
        return false;
    }


     if(color != board.CheckBusyOrNot(_current))
     {
        return false ;
     }


    if(figure == "Q")
    {
        ptr_figure = new Queen(color);
    }

    if(figure == "B")
    {
        ptr_figure = new Bishop(color);
    }

    if(figure == "Kn")
    {
        ptr_figure = new Knight(color);
    }

    if(figure == "P")
    {
        ptr_figure = new Pawn(color);
    }

    if(figure == "K")
    {
        ptr_figure = new King(color);
    }

    if(figure == "R")
    {
        ptr_figure = new Rook(color);
    }


    if(ptr_figure == nullptr)
    {
        return false;
    }

    board.MoveFigure(ptr_figure, color, _current, _newPosition);
    return true;
}