install:
	cp include/*.hpp ./src
	g++ src/*.cpp -o chess
	rm -rf ./src/*.hpp
uninstall:
	rm -rf chess
reinstall:
	make uninstall;
	make install;
