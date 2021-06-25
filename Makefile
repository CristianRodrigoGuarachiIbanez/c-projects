CC ="g++"
PROJECT = img
SRC = imgArrayRecover.cpp
SRC = directoryFilesCollector.cpp
export DISPLAY =: 0.0

LIBS = `pkg-config opencv4 --cflags  --libs`

$(PROJECT) : $(SRC)
	$(CC) $(SRC) -o $(PROJECT) $(LIBS) 
