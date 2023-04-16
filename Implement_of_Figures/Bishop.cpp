#include "../Figures/Bishop.h"
#include "../Figures/Board.h"

bool Bishop::ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b)
{ 
     // self check 
     if(new_pos == current){return false;}


      // valid position or not
     if(abs(current.first - new_pos.first) != abs(current.second - new_pos.second)) {return false;}


      // is busy by the figure of the same color 
     if(b.CheckBusyOrNot(new_pos) == color) {return false;}



     // is the valid path
     if(current.first < new_pos.first && current.second < new_pos.second)
     {
         for(int i = current.first, j = current.second; i < new_pos.first && j < new_pos.second; i++, j++)
         {
            if(!b.CheckBusyOrNot({i,j}))
            {
               return false;
            }
         }
     }

     else if(current.first < new_pos.first && current.second > new_pos.second)
     {
         for(int i = current.first, j = current.second; i > new_pos.first && j < new_pos.second; i++, j--)
         {
            if(!b.CheckBusyOrNot({i,j}))
            {
               return false;
            }
         }
     }

     else if(current.first > new_pos.first && current.second < new_pos.second)
     {
         for(int i = current.first, j = current.second; i < new_pos.first && j > new_pos.second; i--, j++)
         {
            if(!b.CheckBusyOrNot({i,j}))
            {
               return false;
            }
         }
     }


     else if(current.first > new_pos.first && current.second > new_pos.second)
     {
         for(int i = current.first, j = current.second; i > new_pos.first && j > new_pos.second; i--, j--)
         {
            if(!b.CheckBusyOrNot({i,j}))
            {
               return false;
            }
         }
     }

     return true;
}