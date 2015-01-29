# Nombre archivo: makefile
# Uso: make -f makefile
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
# que utilizan main1 main2 main3 y main4

# Variable que indica el compilador que se va a utilizar
CC=g++
# Variables que indican los directorios en donde se encuentran los archivos
INCLUDE_DIR = ./include
LIB_DIR= ./lib
BIN_DIR= ./bin
OBJ_DIR= ./obj
SRC_DIR= ./src

# Variable que enumera los objetos que se incluyen en la libreria

OBJECT_MODULES_LIB= $(OBJ_DIR)/cliente.o $(OBJ_DIR)/banco.o $(OBJ_DIR)/cuenta.o $(OBJ_DIR)/fecha.o $(OBJ_DIR)/hora.o $(OBJ_DIR)/movimiento.o 

#-----------------------------EJECUTABLES-----------------------------------------

$(BIN_DIR)/all:$(BIN_DIR)/main1 $(BIN_DIR)/main2 $(BIN_DIR)/main3 $(BIN_DIR)/main4 

#----------------------------------OBJETOS---------------------------------------------------

$(BIN_DIR)/main1: $(OBJ_DIR)/main1.o $(LIB_DIR)/libfinanzas.a
	@echo creando main1....
	@$(CC) -o $@  -L$(LIB_DIR) $(OBJ_DIR)/main1.o -lfinanzas

$(BIN_DIR)/main2: $(OBJ_DIR)/main2.o $(LIB_DIR)/libfinanzas.a
	@echo creando main2....
	@$(CC) -o $@  -L$(LIB_DIR) $(OBJ_DIR)/main2.o -lfinanzas

$(BIN_DIR)/main3: $(OBJ_DIR)/main3.o $(LIB_DIR)/libfinanzas.a
	@echo creando main3....
	@$(CC)  -o $@  -L$(LIB_DIR) $(OBJ_DIR)/main3.o -lfinanzas

$(BIN_DIR)/main4: $(OBJ_DIR)/main4.o $(LIB_DIR)/libfinanzas.a
	@echo creando main4....
	@$(CC) -o $@  -L$(LIB_DIR) $(OBJ_DIR)/main4.o -lfinanzas


#--------------------------------------------------------------------------------

$(OBJ_DIR)/main1.o:$(SRC_DIR)/main1.cpp	
	@$(CC) -c -I$(INCLUDE_DIR) -o $@ $<

$(OBJ_DIR)/main2.o: $(SRC_DIR)/main2.cpp 	
	@$(CC) -c -I$(INCLUDE_DIR) -o $@ $<

$(OBJ_DIR)/main3.o: $(SRC_DIR)/main3.cpp 	
	@$(CC) -c -I$(INCLUDE_DIR) -o $@ $<

$(OBJ_DIR)/main4.o: $(SRC_DIR)/main4.cpp 	
	@$(CC) -c -I$(INCLUDE_DIR) -o $@ $<


#---------------------LIBRERIA-----------------------------------------------

$(LIB_DIR)/libfinanzas.a: $(OBJECT_MODULES_LIB) $(INCLUDE_DIR)/finanzas.h
	@echo creando biblioteca....
	@ar -rvs  $(LIB_DIR)/libfinanzas.a  $^

#--------------------OBJETOS DE LA LIBRERIA-----------------------------
$(OBJ_DIR)/cliente.o: $(SRC_DIR)/cliente.cpp $(INCLUDE_DIR)/cliente.h
	@echo creando cliente.o.....
	@$(CC) -c -o $@ -I $(INCLUDE_DIR) $<

$(OBJ_DIR)/hora.o: $(SRC_DIR)/hora.cpp  $(INCLUDE_DIR)/hora.h 
	@echo creando hora.o....
	@$(CC) -c  -o $@ -I $(INCLUDE_DIR)  $<

$(OBJ_DIR)/fecha.o: $(SRC_DIR)/fecha.cpp $(INCLUDE_DIR)/hora.h $(INCLUDE_DIR)/fecha.h
	@echo creando fecha.o.....
	@$(CC) -c -o $@ -I $(INCLUDE_DIR)  $<

$(OBJ_DIR)/movimiento.o: $(SRC_DIR)/movimiento.cpp  $(INCLUDE_DIR)/movimiento.h
	@echo creando movimiento.o....
	@$(CC) -c  -o $@ -I $(INCLUDE_DIR)  $<

$(OBJ_DIR)/cuenta.o: $(SRC_DIR)/cuenta.cpp $(INCLUDE_DIR)/cuenta.h
	@echo creando cuenta.o.....
	@$(CC) -c -o $@ -I $(INCLUDE_DIR)  $<

$(OBJ_DIR)/banco.o: $(SRC_DIR)/banco.cpp  $(INCLUDE_DIR)/banco.h 
	@echo creando banco.o....
	@$(CC) -c  -o $@ -I $(INCLUDE_DIR)  $<

# --------------------limpieza de los objetos y libreria-----------
clean:
	@echo Borrando ficheros objeto ,librería...
	@rm $(OBJ_DIR)/*.o $(LIB_DIR)/*

#-----------------limpieza de ejecutables-----------------------
mrproper:clean
	@echo y ejecutables.....
	@rm $(BIN_DIR)/* 
	
