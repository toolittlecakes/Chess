#include "Figure.h"
#include"Board.h"


#ifndef Rook_h
#define Rook_h
class Rook : public Figure {
public:
    bool ValidOrNot(const std::pair<int, int>& current, const std::pair<int, int>& new_pos, Board& b) override;
    Rook(const Color& color);
};

#endif
