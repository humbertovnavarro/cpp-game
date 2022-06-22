libs = -lsfml-graphics -lsfml-window -lsfml-system
outfile = ./build/cpp-game
default:
	g++ ./src/main.cpp -o $(outfile) $(libs)
run:
	make default && $(outfile)
watch:
	while true; do make -q || make run; sleep 0.5; done
