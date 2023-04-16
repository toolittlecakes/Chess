 #pragma once
 #include<vector>
 #include<map>
 #include"Figure.h"
 #include"Queen.h"
 #include"Pawn.h"
 #include"Knight.h"
 #include"Rook.h"
 #include"Bishop.h"

#ifndef Board_h
#define Board_h

class Board {
private:
     std::vector<std::vector<int>> board; 
     std::map<std::pair<int,int>, Figure*> positions_of_figures; 

public: 
    Board();
    int CheckBusyOrNot(const std::pair<int, int>& coord);
    void MoveFigure(Figure* figure, const std::pair<int, int>& current_pos, const std::pair<int, int>& new_pos);
    void DisplayBoard();

private:
     void SetInitialPositions();
     void InitialBusyCages();
    
 };

 #endif