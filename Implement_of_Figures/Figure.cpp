#include<iostream> 
#include "../Figures/Figure.h"
#include "../Figures/Board.h"

Color Figure::GetColor() const
{
    return color;
}

void Figure::SetColor(const Color& color)
{
    this->color = color;
}

Figure::Figure()
{
     
}

Figure::~Figure()
{

}