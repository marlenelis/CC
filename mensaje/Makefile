
SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


#---------------------Ejecutables y documentación---------------------

$(BIN)/all:$(BIN)/ocultar $(BIN)/revelar documentacion
#-----------------------------------------------------

# ************ Generación de documentación ******************
documentacion:
	@doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

#-----------------------OBJETOS--------------------------------

$(OBJ)/codificar.o : $(SRC)/codificar.cpp $(INC)/codificar.h 
	@$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	@$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

#-------------------------------------------------------------------

$(OBJ)/ocultar.o : $(SRC)/mainO.cpp  $(INC)/imagenES.h $(INC)/codificar.h
	@$(CXX) $(CPPFLAGS) $(SRC)/mainO.cpp -o $(OBJ)/ocultar.o

$(OBJ)/revelar.o : $(SRC)/mainR.cpp  $(INC)/imagenES.h $(INC)/codificar.h 
	@$(CXX) $(CPPFLAGS) $(SRC)/mainR.cpp -o $(OBJ)/revelar.o
	
#-----------------------------Generación de Ejecutables -----------------------------------------------

$(BIN)/ocultar:  $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	@$(CXX) -o $(BIN)/ocultar  $(OBJ)/ocultar.o  $(OBJ)/codificar.o $(OBJ)/imagenES.o
	
$(BIN)/revelar: $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o 
	@$(CXX) -o $(BIN)/revelar  $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	
#----------------------------------------------------------------------




# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
