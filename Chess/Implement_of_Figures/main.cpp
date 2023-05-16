// Это точно должно быть не в папке Implement_of_Figures
#include <iostream>
#include "raylib.h"
#include <map>
#include "../Figures/King.h"
#include "../Figures/Queen.h"
#include "../Figures/Pawn.h"
#include "../Figures/Knight.h"
#include "../Figures/Rook.h"
#include "../Figures/Bishop.h"
#include "../Figures/Figure.h"
#include "../Figures/Board.h"

const int screenWidth = 800;
const int screenHeight = 800;
const int boardSize = 8;
const int cellSize = 80;


Figure* figure;
std::pair<int, int> current{-1, -1};
std::pair<int, int> new_pos{-1, -1};
int count = 0;

int temp1 = 0;
int temp2 = 0;

int main()
{

    Board board;

    // Это нужно объявлять заранее? Можно же прям в цикле с типом auto
    std::map<std::pair<int, int>, Figure*> positions_of_figures;


    InitWindow(screenWidth, screenHeight, "Chess Board");
    SetTargetFPS(60);

    Texture bPawn = LoadTexture("./Images/Black_pawn.png");
    Texture2D bRook = LoadTexture("./Images/Black_rook.png");
    Texture2D bKnight = LoadTexture("./Images/Black_knight.png");
    Texture2D bBishop = LoadTexture("./Images/Black_bishop.png");
    Texture2D bQueen = LoadTexture("./Images/Black_queen.png");
    Texture2D bKing = LoadTexture("./Images/Black_king.png");

    Texture2D wPawn = LoadTexture("./Images/White_pawn.png");
    Texture2D wRook = LoadTexture("./Images/White_rook.png");
    Texture2D wKnight = LoadTexture("./Images/White_knight.png");
    Texture2D wBishop = LoadTexture("./Images/White_bishop.png");
    Texture2D wQueen = LoadTexture("./Images/White_queen.png");
    Texture2D wKing = LoadTexture("./Images/White_king.png");

    while (!WindowShouldClose())
    {
        // тебе тут нужен get_positions метод, который возвращает константную ссылку на мапу. Если захочешь, то сделаешь копию с помощью
        // auto positions = board.get_positions()
        // А если не захочешь копировать, сделаешь ссылку
        // const auto& positions = board.get_positions()
        positions_of_figures = board.Copy_of_position();

        BeginDrawing();
        ClearBackground(GRAY);

        int boardWidth = boardSize * cellSize;
        int x = (screenWidth - boardWidth) / 2;
        int y = (screenHeight - boardWidth) / 2;

        // Отрисовываем шахматную доску
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                int tileColor = ((i + j) % 2 == 0) ? 0 : 1;
                Color color = (tileColor == 0) ? WHITE : DARKBROWN;
                int xPos = x + j * cellSize;
                int yPos = y + i * cellSize;
                Rectangle rect = {(float)xPos, (float)yPos, cellSize, cellSize };
                DrawRectangleRec(rect, color);
            }
        }

        // Отрисовываем буквы координат
        for (int i = 0; i < boardSize; i++)
        {
            int xPos = x - 3 + cellSize / 2 + i * cellSize;
            int yPosBot = y + 10 + boardWidth;

            char letter = (char)('a' + i);
            DrawText(&letter, xPos, yPosBot, cellSize/2 - 10, BLACK);
        }

        // Отрисовываем цифры координат
        for (int j = 0; j < boardSize; j++)
        {
            int xPosLeft = x - cellSize + cellSize / 2;
            int yPos = y + j * cellSize + cellSize / 2;

            char number = (char)('1' + (boardSize - 1) - j);
            DrawText(&number, xPosLeft, yPos, cellSize/2 - 10, BLACK);
        }

        for(auto it : positions_of_figures)
        {
            if(typeid(*it.second) == typeid(King))
            {
                // У тебя дублирование этого кода во всех if. Надо подумать, как этого избежать
                if(it.second->GetColor() == 1)
                {
                    DrawTexture(wKing,  (it.first.second + 1) * cellSize + 5, abs(8 - it.first.first) * cellSize + 5, RAYWHITE);
                }

                else {
                    DrawTexture(bKing, (it.first.second + 1) * cellSize + 5, abs(8 - it.first.first) * cellSize + 5, RAYWHITE);
                }
            }

            else if(typeid(*it.second) == typeid(Rook))
            {
                if(it.second->GetColor() == 1)
                {
                    DrawTexture(wRook, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }

                else{
                    DrawTexture(bRook, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }
            }

            else if(typeid(*it.second) == typeid(Bishop))
            {
                if(it.second->GetColor() == 1)
                {
                    DrawTexture(wBishop, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }

                else{
                    DrawTexture(bBishop, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }
            }

            else if(typeid(*it.second) == typeid(Queen))
            {
                if(it.second->GetColor() == 1)
                {
                    DrawTexture(wQueen, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }

                else{
                    DrawTexture(bQueen, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }
            }

            if(typeid(*it.second) == typeid(Pawn))
            {
                if(it.second->GetColor() == 1)
                {
                     DrawTexture(wPawn, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }

                else{
                     DrawTexture(bPawn, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }
            }

            else if(typeid(*it.second) == typeid(Knight))
            {
                if(it.second->GetColor() == 1)
                {
                     DrawTexture(wKnight, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }

                else{
                    DrawTexture(bKnight, (it.first.second + 1) * cellSize + 5, ((8 - it.first.first)) * cellSize + 5, RAYWHITE);
                }
            }
        }


        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
           if(current.first == -1 && current.second == -1)
           {

                int current_j = (GetMouseX() / cellSize) - 1;
                int current_i = 7 - abs((GetMouseY() / cellSize) -1);


               figure = board.GetFigure({current_i, current_j});

               if(figure != nullptr)
                {

                    if(count == 1 && figure->GetColor() == -1 || count == 0 && figure->GetColor() == 1)
                    {
                        current.second = current_j;
                        current.first = current_i;
                    }
                }
            }


           else if(new_pos.first == -1 && new_pos.second == -1)
            {
                int new_pos_j = (GetMouseX() / cellSize) - 1;
                int new_pos_i = 7 - abs((GetMouseY() / cellSize) -1);

                if(new_pos_j >= 8 || new_pos_j < 0 || new_pos_i >= 8 || new_pos_i < 0)
                {
                    continue;
                }

                new_pos.first = new_pos_i;
                new_pos.second = new_pos_j;
// Вот это точно нужно вынести в отдельную функци. Это неадекватный уровень вложенности.
                if(board.MoveFigure(figure, figure->GetColor(), current, new_pos))
                {
                    if(count == 1)
                    {
                        if(board.isKingAreMated(FigureColor::White))
                        {
                            CloseWindow();

                            InitWindow(screenWidth, screenHeight, "GOOD GAME");

                            while(!WindowShouldClose())
                            {
                                BeginDrawing();
                                ClearBackground(GRAY);

                                DrawText("Check Mate !", 190, 200, 75, BLACK);
                                DrawText("Black Wins !", 190, 400, 75, BLACK);

                                EndDrawing();
                            }
                            CloseWindow();
                            break;
                        }

                        count = 0;
                    }

                    else
                    {

                        if(board.isKingAreMated(FigureColor::Black))
                        {
                            CloseWindow();

                            InitWindow(screenWidth, screenHeight, "GOOD GAME");

                            while(!WindowShouldClose())
                            {
                                BeginDrawing();
                                ClearBackground(GRAY);

                                DrawText("Check Mate!", 190, 200, 75, WHITE);
                                DrawText("White Wins!", 190, 400, 75, WHITE);
                                EndDrawing();
                            }

                            CloseWindow();
                            break;
                        }
                        count = 1;
                    }



                }

                current = {-1,-1};
                new_pos = {-1,-1};

            }
        }

        EndDrawing();
    }


    CloseWindow();
    return 0;
}
