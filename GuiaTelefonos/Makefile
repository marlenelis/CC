# FICHERO Makefile
# USO  make
# Autor: Marlene Vásquez
# Fecha  Enero 2013 
#---------------------------------------------------------------------
CXX = g++
CXXFLAGS = -Wall -g  -I$(INC) -c

#___________________Generación de los ejecutables y documentación___________


all: usoGuia

#___________________Generación de documentación_____________________________


# ***********************************************************************
#               	Compilación de módulos 
# ***********************************************************************

#___________________Ejecutables______________________________________________

usoGuia:  usoGuia.o 
	@$(CXX)   $^ -o $@

#___________________Objetos Ejecutables_______________________________________


usoGuia.o : usoGuiaTelefonos.cpp guiaTelefonos.h diccionario.h
	@$(CXX) $(CXXFLAGS) $< -o $@
	

#______________________________________________________________________________


	
# ***********************************************************************
#               	Limpieza 
# ***********************************************************************

clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~  ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/* 
