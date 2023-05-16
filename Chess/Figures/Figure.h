// Этот файл бы как-то отделить от остальных. Я бы сделал папку FiguresImpls и поместил все остальные туда. В ней бы создал папку headers и sources, или вообще вместе бы скидал. А то у тебя как будто Implement_of_Figures это вообще отдельная сущность, как Images
// Board и Manager тоже вытащил бы куда-то, потому что они не является фигурой.

#include<iostream>
#include"Board.h"

#ifndef Figure_h
#define Figure_h

class Board;

enum FigureColor {
    Black = -1,
    White = 1
};

class Figure {
protected:
// 5 пробелов отступ ????
     Figure(Figure& q);
     Figure& operator= (const Figure& q);

public:
     Figure();

     Figure(const FigureColor& color);

    // Это точно должно быть Public? Зачем тебе вообще менять цвет фигуры после создания?
     void SetColor(const FigureColor& color);

     FigureColor GetColor() const;


     /**
      * @brief Проверят может ли фигура сделать ход
      *
      * Изначально проверяет может ли фигура пойти в новую координату если бы на доске не было больше фигур
      * А потом еще учитывается фактор других фигур. Кстати эта функция используется в функции MoveFigure класса Board
      * в качестве проверки
      *
      * @param Board& доска
      *
      * @param current_coordinate текущяя координата
      *
      * @param new_pos новая координата
      *
      * @return true если может туда пойти, false в противном случае
     */
    // Не понятно, к чему относится Valid. Я бы переименовал в IsMoveValid
    // Передавать пары интов по ссылке особо не имеет смысла и только запутывается. Можно просто парами передавать. А еще лучше сделать где-нибудь `using Coord = std::pair<int, int>;`, чтобы добавить смысла паре.
    // current, new_pos можно переименовать более похоже друг на друга. Например current, next или from, to
     virtual bool ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b) = 0;

     virtual ~Figure();

protected:
    FigureColor color;
};

#endif
