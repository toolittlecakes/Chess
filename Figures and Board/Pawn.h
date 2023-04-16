#include "Figure.h"
#include"Board.h"


#ifndef Pawn_h
#define Pawn_h
class Pawn : public Figure {
public:
    bool ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b) override;
};

#endif
