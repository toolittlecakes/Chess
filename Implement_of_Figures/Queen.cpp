#include"../Figures/Queen.h"
#include "../Figures/Board.h"


bool Queen::ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b)
{
     if(abs(current.first - new_pos.first) == abs(current.second - new_pos.second))
     {
        return true;
     }

     if(current.first == new_pos.first && current.second != new_pos.second)
     {
        return true;
     }

     if(current.first != new_pos.first && current.second == new_pos.second)
     {
        return true;
     }

     return false;
}
