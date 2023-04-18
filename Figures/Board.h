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

    /**
     *  @brief Будет осуществлять ход  
     * 
     *  
     *  Будет производиться 2 проверки :
     *  1) есть ли вообще фигура на этой коорддинате
     *  2) может ли эта фигура пойти на новую координату 
     * 
     * 
     * @param Figure*
     * 
     * @param std::pair<int, int> current получает начальную координату 
     * 
     * @param std::pair<int, int> new_coordinate новая координата  
    */
    void MoveFigure(Figure* figure, const std::pair<int, int>& current_pos, const std::pair<int, int>& new_pos);


    // отображает экран в виде 1, 0, -1; 
    void DisplayBoard();

private:
    /**
    *  @brief функция(SetInitialPositions) "инициализатор" доски
    * 
    * Она вызывается в конструкторе при создании обькта. В нем создаются все наши фигуры и соответсвующие координаты каждой фигуры 
    * зыписывается в наш map(position_of_figures)
    */
    void SetInitialPositions();


     /**
      * @brief Эта функция тоже "инициализотор"
      * 
      * Она же инициализирует наш board вектор, т.е там где расположена белая фигуры там он ставит 1 там где пусто он ставит 0, 
      * ну и -1 там где черная фигура. Я решил так сделать, чтобы  облегчит процесс проверки каждой фигуры на валидность ходa, т.е
      * если типа перед пешкой(белой) стоит -1 то нельзя туда идти; 
     */
     void InitialBusyCages();
 };

 #endif