sample:
	 g++ Sample\ Client.cpp -o ./build/Client
	 g++ Sample\ Server.cpp -o ./build/Server

lib:
	echo "Building -- "
	g++ Client.h -o ./build/Client.program
	g++ Server.h -o ./build/Server.program
	echo "Done Buiding"


	

.PHONY: all test clean