#include "../Figures/King.h"
#include "../Figures/Board.h"


bool King::ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board&)
{
    return true;
}

King::King(const Color& color)
{
    this->color = color;
    count = 0ж
}

void King::SetCount(int count)
{
    this->count = count;
}

int King::GetCount() const 
{
    return count;
}