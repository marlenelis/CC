# FICHERO Makefile
# USO  make
#-------------------------Directorios--------------------------------
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DAT = datos
#--------------------------------------------------------------------
CXX = g++

#-----------------------------------------------------
CXXFLAGS = -Wall -g  -I$(INC) -c
# _________________________Objetos para la biblioteca__________________

OBJECT_LIB = $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformacion.o  $(OBJ)/Transformaciones.o $(OBJ)/procesar.o

#*************************Generación de los ejecutables y documentación**********************

$(BIN)/all:$(BIN)/transformar $(BIN)/revelar  $(BIN)/ocultar $(BIN)/generar $(BIN)/componer documentacion

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************

#_________________________Ejecutables________________________________________
$(BIN)/ocultar:  $(OBJ)/ocultar.o $(LIB)/libimagen.a
	@$(CXX)   $^ -L$(LIB) -limagen -o $@
	
$(BIN)/revelar:  $(OBJ)/revelar.o $(LIB)/libimagen.a
	@$(CXX)   $^ -L$(LIB) -limagen -o $@
	
$(BIN)/transformar:  $(OBJ)/transformar.o $(LIB)/libimagen.a
	@$(CXX)   $^ -L$(LIB) -limagen -o $@
	
$(BIN)/generar:  $(OBJ)/generar.o $(LIB)/libimagen.a
	@$(CXX)   $^ -L$(LIB) -limagen -o $@

$(BIN)/componer:  $(OBJ)/componer.o $(LIB)/libimagen.a
	@$(CXX)   $^ -L$(LIB) -limagen -o $@

#___________________________Objetos Ejecutables________________________________
$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp 
	@$(CXX) $(CXXFLAGS) $< -o $@
	
$(OBJ)/revelar.o : $(SRC)/revelar.cpp 
	@$(CXX) $(CXXFLAGS) $< -o $@
	
$(OBJ)/transformar.o : $(SRC)/transformar.cpp 
	@$(CXX) $(CXXFLAGS) $< -o $@
	
$(OBJ)/generar.o : $(SRC)/generar.cpp 
	@$(CXX) $(CXXFLAGS) $< -o $@
	
$(OBJ)/componer.o : $(SRC)/componer.cpp 
	@$(CXX) $(CXXFLAGS) $< -o $@
#---------------------Biblioteca-----------------------------------------------

$(LIB)/libimagen.a: $(OBJECT_LIB)
	ar -rvs $(LIB)/libimagen.a  $^

#______________________________________________________________________________

$(OBJ)/procesar.o : $(SRC)/procesar.cpp $(INC)/procesar.h
	@$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/Transformaciones.o : $(SRC)/Transformaciones.cpp $(INC)/Transformaciones.h
	@$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/transformacion.o : $(SRC)/transformacion.cpp $(INC)/transformacion.h $(INC)/transformacion1.h $(INC)/transformacion2.h
	@$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/transformacion1.o : $(SRC)/transformacion1.cpp $(INC)/transformacion1.h
	@$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/transformacion2.o : $(SRC)/transformacion2.cpp $(INC)/transformacion2.h
	@$(CXX) $(CXXFLAGS) $< -o $@
	

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h
	@$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	@$(CXX) $(CXXFLAGS) $< -o $@

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ $(LIB)/* ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/* $(DAT)/*
