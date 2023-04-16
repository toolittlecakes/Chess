#include "../Figures/Rook.h"
#include "../Figures/Board.h"


bool Rook::ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b)
{

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