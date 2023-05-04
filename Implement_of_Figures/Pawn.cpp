#include "../Figures/Pawn.h"
#include "../Figures/Board.h"


bool Pawn::ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b)
{
    if(color == -1)
    {
        if(current.first == 6 && new_pos.first == 4 && new_pos.second == current.second){
             if(b.CheckBusyOrNot({5, current.second}) == 0 && b.CheckBusyOrNot({4, new_pos.second}) == 0)
             {
                return true;
             }
        }

        if(current.first - 1 == new_pos.first && current.second == new_pos.second)
        {
            if(b.CheckBusyOrNot(new_pos) == 0)
            {
                return true;
            }
        }


        if(current.first == 3 && new_pos.first == 2 && abs(new_pos.second - current.second) == 1)
        {   
            auto it = b.GetFigure({3, new_pos.second});

            if(typeid(*it) == typeid(Pawn))
            {
                Pawn* ptr = dynamic_cast<Pawn*>(it);

                if(ptr->GetCount() == 1 && ptr->GetColor() == 1)
                {
                    return true;
                }
            }
        }


        if(abs(current.second - new_pos.second) == 1 && current.first - new_pos.first == 1){

            if(b.CheckBusyOrNot(new_pos) == 1)
            {
                return true;
            }
        }
    }

    if(color == 1)
    {
        if(current.first == 1 && new_pos.first == 3 && new_pos.second == current.second)
        {
             if(b.CheckBusyOrNot({3, current.second}) == 0 && b.CheckBusyOrNot({2, new_pos.second}) == 0)
             {
                return true;
             }
        }

        if(current.first == 4 && new_pos.first == 5 && abs(new_pos.second - current.second) == 1)
        {   
            auto it = b.GetFigure({4, new_pos.second});

            if(typeid(*it) == typeid(Pawn))
            {
                Pawn* ptr = dynamic_cast<Pawn*>(it);

                if(ptr->GetCount() == 1 && ptr->GetColor() == -1)
                {
                    return true;
                }
            }
        }

        if(abs(current.second - new_pos.second) == 1 && current.first - new_pos.first == -1){

            if(b.CheckBusyOrNot(new_pos) == -1)
            {
                return true;
            }
        }

        if(current.first + 1 == new_pos.first && current.second == new_pos.second)
        {
            if(b.CheckBusyOrNot(new_pos) == 0)
            {
                return true;
            }
        }
    }

    return false;
}

Pawn::Pawn(const Color& color)
{
     this->color = color;
     this->count = 0;
}

void Pawn::SetCount(int count)
{
    this->count = count;
}

int Pawn::GetCount() const 
{
    return count;
}