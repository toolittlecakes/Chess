#include"../Figures/Queen.h"
#include "../Figures/Board.h"


bool Queen::ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b)
{
     // self check 
     if(new_pos == current){return false;}

     // is busy by the figure of the same color 
     if(b.CheckBusyOrNot(new_pos) == color) {return false;}


    if(abs(current.first - new_pos.first) != abs(current.second - new_pos.second) || (current.first != new_pos.first) || (current.second != new_pos.second))
    {
        return false;
    }


     // is the valid path
     if(current.first < new_pos.first && current.second < new_pos.second)
     {
         for(int i = current.first, j = current.second; i < new_pos.first && j < new_pos.second; i++, j++)
         {
            if(!b.CheckBusyOrNot(std::make_pair(i,j)))
            {
               return false;
            }
         }
     }

     else if(current.first < new_pos.first && current.second > new_pos.second)
     {
         for(int i = current.first, j = current.second; i > new_pos.first && j < new_pos.second; i++, j--)
         {
            if(!b.CheckBusyOrNot(std::make_pair(i,j)))
            {
               return false;
            }
         }
     }

     else if(current.first > new_pos.first && current.second < new_pos.second)
     {
         for(int i = current.first, j = current.second; i < new_pos.first && j > new_pos.second; i--, j++)
         {
            if(!b.CheckBusyOrNot(std::make_pair(i,j)))
            {
               return false;
            }
         }
     }


     else if(current.first > new_pos.first && current.second > new_pos.second)
     {
         for(int i = current.first, j = current.second; i > new_pos.first && j > new_pos.second; i--, j--)
         {
            if(!b.CheckBusyOrNot(std::make_pair(i,j)))
            {
               return false;
            }
         }
     }


     else if (current.first == new_pos.first){

         for(int j = current.second; j != new_pos.second;)
         {
             if(j > new_pos.second)
             {
                 if(!b.CheckBusyOrNot(std::make_pair(current.first,j)))
                 {
                   return false;
                 }
                 j--;
             }

             if(j < new_pos.second)
             {
                 if(!b.CheckBusyOrNot(std::make_pair(current.first,j)))
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
                 if(!b.CheckBusyOrNot(std::make_pair(i,current.second)))
                 {
                   return false;
                 }
                 i--;
             }

             if(i < new_pos.second)
             {
                 if(!b.CheckBusyOrNot(std::make_pair(i,current.second)))
                 {
                   return false;
                 }
                 i++;
             }
         }   
     }

     return true;
}

Queen::Queen(const Color& color)
{
     this->color = color;
}
