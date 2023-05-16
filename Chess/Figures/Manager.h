#include "Board.h"
#include "Figure.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"


// Это вообще не понятно что такое. Названия существительные обычно испольуются для классов. А тут вроде это просто функция. Что она делает и зачем - не понятно
bool Manager(const std::string& figure, const FigureColor& color, const std::string& current, const std::string& new_position,  Board& board);
