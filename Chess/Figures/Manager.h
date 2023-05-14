#include "Board.h"
#include "Figure.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"


bool Manager(const std::string& figure, const FigureColor& color, const std::string& current, const std::string& new_position,  Board& board);