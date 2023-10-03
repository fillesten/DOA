#include "functions.h"
#include "reader.h"
#include <iostream>

int main()
{
	std::system("chcp 1252 >> NUL");
	adjacency_list_t indata = parse_file("export.txt");
	

	//size 48
	meta_t nodMap = indata.first;
	
	edge_list_t kanter = indata.second;
	//115
	std::vector<std::vector<double>> Matrix = createMatrix(indata, kanter);
	

	//std::cout << indata << std::endl;
	//std::cout << Matrix << std::endl;

	
	/*DFS(Matrix, 0);
	std::cout << Matrix << std::endl;
	BFS(Matrix, 0);*/



	/*for (size_t i = 0; i < 48; i++)
	{
		DFS(Matrix, i);
		std::cout << "ITERATION KLAR ------------ " << i << std::endl;

	}*/
	/*for (size_t i = 0; i < 48; i++)
	{
		BFS(Matrix, i);
		std::cout << "ITERATION KLAR ------------ " << i << std::endl;
	}*/

	//BFS(Matrix, 0);

	//dijkstra(Matrix, 0, 43);

	dijkstra(Matrix, 24, 37);
	std::cout <<"From " << indata.first[24] << " to " << indata.first[37] << std::endl;

	dijkstra(Matrix, 46, 47);
	std::cout << "From " << indata.first[46] << " to " << indata.first[47] << std::endl;

	dijkstra(Matrix, 30, 19);
	std::cout << "From " << indata.first[24] << " to " << indata.first[37] << std::endl;
	/*
	kan ej hantera denna eftersom man kan endast gå IFRÅN 19 inte gå dit. 
	Ta antingen bort den pathen eller lägg dit en till å tvinga pizzan ha öppet.
	*/
	



	int debuggstop = 1;
	return 0;
}