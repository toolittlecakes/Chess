#include "../Figures/Rook.h"
#include "../Figures/Board.h"


bool Rook::ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b)
{

     if (current.first == new_pos.first){

         for(int j = current.second; j != new_pos.second;)
         {
             if(j > new_pos.second)
             {
                 if(!b.CheckBusyOrNot({current.first,j}))
                 {
                   return false;
                 }
                 j--;
             }

             if(j < new_pos.second)
             {
                 if(!b.CheckBusyOrNot({current.first,j}))
                 {
                   return false;
                 }
                 j++;
             }
         }   
     }

     else if (current.second == new_pos.second){

         for(int i = current.first; i != new_pos.first;)
         {
             if(i > new_pos.first)
             {
                 if(!b.CheckBusyOrNot({i,current.second}))
                 {
                   return false;
                 }
                 i--;
             }

             if(i < new_pos.second)
             {
                 if(!b.CheckBusyOrNot({i,current.second}))
                 {
                   return false;
                 }
                 i++;
             }
         }   
     }

     return true;
}

Rook::Rook(const Color& color)
{
     this->color = color;
}