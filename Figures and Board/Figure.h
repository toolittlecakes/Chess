#include<iostream> 
#include"Board.h"

#ifndef Figure_h
#define Figure_h

class Board;

enum Color {
    Black = -1,
    White = 1
};

class Figure {
protected:
     Figure(Figure& q);
     Figure& operator= (const Figure& q);
     Figure(const std::pair<int, int>& pair);

public:
     Figure();

     void SetColor(const Color& color);

     Color GetColor() const;

     virtual bool ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b) = 0;

     virtual ~Figure();

protected:
    Color color;
};

#endif