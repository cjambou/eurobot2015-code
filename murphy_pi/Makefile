#This sample makefile has been setup for a project which contains the following files: main.h, ap-main.c, ap-main.h, ap-gen.c, ap-gen.h   Edit as necessary for your project

#Change output_file_name.a below to your desired executible filename

#Set all your object files (the object files of all the .c files in your project, e.g. main.o my_sub_functions.o )
OBJ = main.o Coord.o MAE_MURPHY.o Mission_Claps.o Mission_Distrib.o Mission_Zone_Ennemie.o Element_Robot.o Master.o Mission_Depot_Tour_Depart.o Mission.o Period.o Gestionnaire_Mission.o  Mission_Chiage_Balle.o  Mission_Depot_Tour_Estrade.o  Mission_Zone_centrale.o  Protocole_COM.o

#Set any dependant header files so that if they are edited they cause a complete re-compile (e.g. main.h some_subfunctions.h some_definitions_file.h ), or leave blank
DEPS = main.h Coord.h MAE_MURPHY.h Mission_Claps.h Mission_Distrib.h Mission_Zone_Ennemie.h Element_Robot.h Master.h Mission_Depot_Tour_Depart.h Mission.h Period.h Gestionnaire_Mission.h  Mission_Chiage_Balle.h  Mission_Depot_Tour_Estrade.h  Mission_Zone_centrale.h  Protocole_COM.h 

#Any special libraries you are using in your project (e.g. -lbcm2835 -lrt `pkg-config --libs gtk+-3.0` ), or leave blank
LIBS = -lrt -lwiringPi -lpthread -lm

#Set any compiler flags you want to use (e.g. -I/usr/include/somefolder `pkg-config --cflags gtk+-3.0` ), or leave blank
CFLAGS = -lrt

#Set the compiler you are using ( gcc for C or g++ for C++ )
CC = g++

#Set the filename extensiton of your C files (e.g. .c or .cpp )
EXTENSION = .cpp

#define a rule that applies to all files ending in the .o suffix, which says that the .o file depends upon the .c version of the file and all the .h files included in the DEPS macro.  Compile each object file
%.o: %$(EXTENSION) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Combine them into the output file
#Set your desired exe output file name here
game.a: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

#Cleanup
.PHONY: clean

clean:
	rm -f *.o *~ core *~ 
