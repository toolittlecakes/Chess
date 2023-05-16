#pragma once
#include <vector>
#include <map>
#include "Figure.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"


// если ты делаешь эти штуки, то нужно убрать pragma once. И их нужно ставить в самом верху. Тут и вов сех остальных файлах
#ifndef Board_h
#define Board_h

class Board {
private:
    //  А зачем тебе хранить board интов, если у тебя есть мапа в которой по {i, j} ты получаешь фигуру и можешь узнать ее цвет? Зачем дублировать информацию? Мб просто сделать функцию getColor(i, j), которая будет из мапы фигур это доставать?

     std::vector<std::vector<int>> board;

    //  Тут бы smart pointers использовать.
     std::map<std::pair<int,int>, Figure*> positions_of_figures;

public:
    Board();

    Figure* GetFigure(const std::pair<int, int>& coord);

    int CheckBusyOrNot(const std::pair<int, int>& coord);

    /**
     *  @brief Будет осуществлять ход
     *
     *
     *  Будет производиться 2 проверки :
     *  1) есть ли вообще фигура на этой коорддинате
     *  2) может ли эта фигура пойти на новую координату
    */
    bool MoveFigure(Figure* figure, const FigureColor& color, const std::pair<int, int>& current_pos, const std::pair<int, int>& new_pos);


    // отображает экран с фигурами;
    // Это какой-то странный нэйминг. Есть PascalCase, camelCase, snake_case, у тебя тут какой-то франкенштейн. И я не понял что тут делается. Copy? но при этом коммент - отображает экран с фигурами
    std::map<std::pair<int, int>, Figure*> Copy_of_position();

// Приватные методы можно вынести вниз, чтобы логика чтения была от общего к частному:
// Поля
// конструкторы
// публичный интерфейс
// приватные с реализацией всяких хелпер функций

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

     /**
      * @brief Эта функция "Делает несколько проверок"
      *
      * Проверяет вообще нормальные ли были переданы координаты, правильная ли фигура была взята,
      * и исходя из положения доски определаят валидность хода
     */
     inline bool Check(Figure* f, const FigureColor& color, const std::pair<int, int>& current, const std::pair<int, int>& new_pos);

    /**
     * @brief Особые случаи
     * В случаях когда был сделан ход пешкой или ладьей, или королем процесс хода чуток отличается от других поэтому
     * и реализуется эта функция
    */
// тут явно не хватает глагола в названии функции, как и в других ниже. Не понятно, что за спэшл кейс, если не вчитываться в аргументы.
    bool SpecialCasesPawn(Figure* f, const FigureColor& color, const std::pair<int, int>& current, const std::pair<int, int>& new_pos);



    void SpecialCasesRookAndKing(Figure* f, const FigureColor& color, const std::pair<int, int>& current, const std::pair<int, int>& new_pos);

    /**
     * @brief Функция для проверки состояния короля
     *
     *
     * @return true если король находиться под шахом, и false в обратном случае
    */

    bool isKingUnderCheck(const FigureColor& color, const std::pair<int, int>& pos = {-1,-1});


    /**
     * @brief Функция для проверки нато находится ли под матом король
     *
     *
     * @return true если король находиться под шахом, и false в обратном случае
    */

public:
    bool isKingAreMated(const FigureColor& color);

    // bool is_short, а то не понятно, какое значение long, а какое short
    bool Castling(const FigureColor& color, int long_or_short_castling);
 };

 #endif
