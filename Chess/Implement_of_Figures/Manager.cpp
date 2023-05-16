#include "../Figures/Manager.h"

// figure -> figure_name. figure у тебя отвечает за Figure
bool Manager(const std::string& figure, const FigureColor& color,  const std::string& current, const std::string& new_position,  Board& board)
{
    Figure* ptr_figure = nullptr;
    std::pair<int, int> _current;
    std::pair<int, int> _newPosition;

    if(current.size() == 2)
    {
        // Магические константы в коде - плохо. Нужно вынести их в глобальные const переменные внутри этого файла (и либо сделать ее static, чтобы снаружи нельзя было использовать, либо поместить в безымянный неймспейс). И я не понял, что это за числа. Откуда 97 на шахматной доске
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
        // вот эти проверки лучше сделать сначала. Подход называется early return. Сначала ты делаешь куча ифов, которые детектят очевидные ошибки, а потом уже пишешь основной код функции без отступов
        // if (current.size() != 2) return false
        // if (current[0] < 97 || current[0] > 104 || current[1] < 48 || current[1] > 57)
        // if (new_position...
        //
        // _current.first = current[1] - 49;
        // _current.second = current[0] - 97;
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


// имена тоже можно вынести в константны. А еще лучше сделать Enum
    if(figure == "Q")
    {
        // Я не понял, почему у тебя создается новая фигура
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

// может быть лучше сделать эту функцию manager функцией Check
    board.MoveFigure(ptr_figure, color, _current, _newPosition);
    return true;
}
