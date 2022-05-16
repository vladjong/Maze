BD=../build/
QMAKE=$(BD)
CFLAGS=-c# -Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest -I./ -L./
SRC=matrix.cpp cave.cpp pacman.cpp generationMaze.cpp maze.cpp
OBJ=$(addprefix $(BD),$(SRC:.cpp=.o))
EXE=$(QMAKE)Maze.app/Contents/MacOS/Maze
APP=$(QMAKE)Maze.app
APPDIR=$(HOME)/Applications/Maze/
APP_EXE=$(APPDIR)Maze.app/Contents/MacOS/Maze
CC=g++

all: install
	$(APP_EXE)

build: $(BD) $(BD)qmake.pro
	cd $(QMAKE); qmake qmake.pro
	make -C $(QMAKE)

./$(BD):
	mkdir $(BD)

arrange:
	rm -f $(QMAKE)qmake.*
	cd $(QMAKE); qmake -project ../src/; mv build.pro ../src/qmake.pro

./$(BD)qmake.pro:
	cp qmake.pro $(QMAKE)

./$(BD)%.o: */%.cpp
	$(CC) $(CFLAGS) $< -o $@

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

install: build 
	@mkdir $(APPDIR) || echo "Directory already exists. Skip."
	cp -rf manual/ $(APPDIR)manual/
	cp -rf datasets/ $(APPDIR)datasets/
	cp -rf $(APP) $(APPDIR)
	make clean

uninstall:
	rm -rf $(APPDIR)
	rm -rf $(HOME)/Applications/Maze.tar.gz

dvi:
	@open $(APPDIR)manual/manual.html || echo "Please, install application first!"

dist:
	tar -cvf $(APPDIR)../Maze.tar $(APPDIR)
	gzip $(APPDIR)../Maze.tar

#### TEST #####
test: clean $(BD)main_test_exe
	./$(BD)main_test_exe

./$(BD)main_test_exe: $(OBJ) $(BD)main_test.o
	$(CC) $(LDFLAGS) $^ -o $@ $(GTESTFLAGS)

#### GCOV #####
gcov_report: gcov_build $(BD)main_test.o
	$(CC) $(LDFLAGS) $(LCOVFLAGS) $(OBJ) $(BD)main_test.o -o $(BD)main_gcov_exe $(GTESTFLAGS)
	./$(BD)main_gcov_exe
	# mv *.gcda *.gcno ./$(BD)
	lcov -t "gcov_report" -o $(BD)gcov_report.info -c -d ./$(BD)
	genhtml -o $(BD)report $(BD)gcov_report.info
	open $(BD)report/$(PWD)/model/index.html

gcov_build:
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/matrix.cpp -o $(BD)matrix.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/maze.cpp -o $(BD)maze.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/generationMaze.cpp -o $(BD)generationMaze.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/cave.cpp -o $(BD)cave.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/pacman.cpp -o $(BD)pacman.o

clean:
	test -f $(QMAKE)Makefile && make distclean -C $(QMAKE) || printf ""
	rm -rf ./$(BD)*

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction ../src/

cpplint:
	cp ../materials/linters/CPPLINT.cfg . && python3 ../materials/linters/cpplint.py --filter=-runtime/references,-build/c++11 --exclude=view/qcustomplot.h --exclude=view/qcustomplot.cpp --extensions=cpp */*.cpp */*.h; rm -f CPPLINT.cfg

leaks:
	leaks --atExit -- ./$(BD)main_test_exe

valgrind:
	valgrind --undef-value-errors=no --log-file=valgrind-out.txt ./$(BD)main_test_exe
