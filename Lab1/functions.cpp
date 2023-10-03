#include "functions.h"


std::vector<std::vector<double>> createMatrix(adjacency_list_t& lista, edge_list_t& paraKanter)
{
    //48 element
    meta_t nodMap = lista.first;
    size_t columnStorlek = nodMap.size();

    std::vector<std::vector<double>> vecMatris;
        
    for (size_t col = 0; col < columnStorlek; col++) {
        std::vector<double> rows;
        
        for (size_t row = 0; row < columnStorlek; row++) {
             
            rows.push_back(NOT_CONNECTED);
        }
        vecMatris.push_back(rows);
    }

    for (auto edges : paraKanter) {
        vecMatris[edges.n1][edges.n2] = edges.weight;
    }
    return vecMatris;
}


void DFS(std::vector <std::vector<double>>& matris, double startnod)
{   
    int counter = 0;
    std::stack<double> stackNeigh;
    stackNeigh.push(startnod);
    std::vector<bool> visited(matris.size(), false);

    while (!stackNeigh.empty()) 
    {
        double current = stackNeigh.top();
        stackNeigh.pop();
        if (visited[current]) { continue; }

        visited[current] = true;
        std::cout << current << " " << std::endl;

        for (double next = 0; next < matris.size(); next++) {
            if (matris[current][next] != NOT_CONNECTED ) {
                stackNeigh.push(next);
            }
        }
        counter++;
    }
    std::cout << std::endl << counter << std::endl; 
}

void BFS(std::vector <std::vector<double>>& matris, double startnod)
{
    int counter = 0;
    std::queue<double> queueNeigh;
    queueNeigh.push(startnod);
    std::vector<bool> visited(matris.size(), false);

    while (!queueNeigh.empty())
    {
        double current = queueNeigh.front();
        queueNeigh.pop();      
        std::cout << current << " " << std::endl;
        visited[current] = true;

        for (double next = 0; next < matris.size(); next++) {            
            if (visited[next]) { continue; }
            if (matris[current][next] != NOT_CONNECTED) {
                queueNeigh.push(next);
                visited[next] = true;
            }
        }
        counter++;
    }
    std::cout << std::endl <<"ANTAL GRANNAR " << counter << std::endl;
}

void dijkstra(std::vector <std::vector<double>>& matris, double startnod, double destination)
{
    /*
    i dijkstras algoritm finns det

    Noder!!
    är ALLA 48*48 i matris[col][row]

    Connections!!
    är där nod 0 har inte -1 som value mot alla andra 48 noder
    där tex col 2 har connections till row 1, 3, 18
    där col är "currentnod" och den är connectad till neighs noderna 1, 3, 18

    Weights!!
    är "valuen" på matris[col][row] != NOT_CONNECTED
    -------------------------------------------------

    */

    std::cout << std::endl << "DIJSTRKAS " << std::endl;

    std::vector<bool> visited(matris.size(), false);
    //nod 1 ska ha närmsta nod (0, weight)

    std::vector<weight_t> destWeight(matris.size(), INT_MAX);
    std::vector<node_id_t> nodeParent(matris.size(), NOT_CONNECTED);
    std::vector<node_id_t> shortestWay;

    lineweight lw (0.0, startnod);
    prio_queue pq;

    pq.push(lw);

    while (!pq.empty())
    {
        double currentWeight = pq.top().first;
        int current = pq.top().second;
        //poppen säger att det är den kortaste vägen
        pq.pop();

        //måste ha en check som kollar om det redan finns och isf om den är mindre än current weight.
        if (destWeight[current] > currentWeight) { destWeight[current] = currentWeight; }
       
        if (visited[current]) { continue; }
        visited[current] = true;

        for (int next = 0; next < matris.size(); next++) {
            if (visited[next]) { continue; }   
            if (matris[current][next] != NOT_CONNECTED) {
                if (destWeight[next] > destWeight[current] + matris[current][next])
                {
                    lw.first = matris[current][next] + currentWeight;
                    lw.second = next;                
                    pq.push(lw);
                    nodeParent[next] = current;
                }              
            }
        }        
    }
    
    std::cout << "------------------------" << std::endl;
   /* std::cout << "Distance to all vertices from the StartNode: " << std::endl;
    for (int nod = 0; nod < destWeight.size(); nod++) {
        std::cout << "Nod "<< nod << " weight: " << destWeight[nod] << std::endl;
    }
    */
    std::cout << std::endl << "The shortest path from " << startnod << " to " << destination << " is: " << std::endl;

    int parent = nodeParent[destination];
    while (parent != startnod) {
        shortestWay.push_back(parent);
        parent = nodeParent[parent];
    }
    
    std::cout << startnod << " -> ";
    for (int nod = shortestWay.size() -1; nod >= 0; nod--) {
        std::cout << shortestWay[nod] << " -> ";
    }
    std::cout << destination << std::endl << "With weight: " << destWeight[destination] << std::endl << std::endl;

    int debuggstop = 1;
}

std::ostream& operator<<(std::ostream& os, adjacency_list_t& lista) {
    for (auto edge : lista.second) {
        os << edge.n1 << " "
            << edge.n2 << " "
            << edge.weight << " "
            << edge.description << std::endl;
    }
    return os;
}
//skriver ut alla M rader dvs NODER

std::ostream& operator<<(std::ostream& os, std::vector <std::vector<double>> &matris) {
    
    for (const auto& col : matris) {
        for (auto& row : col) {
            os << row << " ";
        }
        os << std::endl;
        //os << matrix << std::endl;
    }
    return os;
    //skriver ut alla weights som -1 14.15 -1  -1  -1
    //                             ..    ..  ..  ..
}

void printMatrix(std::vector<std::vector<double>> matris)
{
    size_t size = matris.size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << matris[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

