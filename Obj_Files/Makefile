TARGET = Myproject
CC = g++

PREF_SRC = ./Implement_of_Figures/
PREF_Headers = ./Obj_Files/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_Headers)%.o, $(SRC))

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_Headers)%.o : $(PREF_SRC)%.cpp
	$(CC) -c $< -o $@

clean : 
	rm $(TARGET) $(PREF_Headers)*.o
