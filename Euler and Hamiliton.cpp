#include <iostream>
#include <string>
using namespace std;

const string RESET = "\033[0m";
const string RED_TEXT = "\033[31m";
const string GREEN_TEXT = "\033[32m";
const string YELLOW_TEXT = "\033[33m";
const string BLUE_TEXT = "\033[34m";
const string CYAN_TEXT = "\033[36m";

struct VertexAndEdges
{
    string Vertex1;
    string Vertex2;
    string edgerepresentation = " -> ";
    int edge;
    int data;
};

class EulerAndHamiltonian
{
    int vertex;
    int edges;
    VertexAndEdges** adjacencyMatrix;
    int* StoreSum;
    int* pathArray;
    int pathCount;

public:
    EulerAndHamiltonian()
    {
        cout << BLUE_TEXT << "Enter The Number Of Vertices: ";
        cin >> vertex;
        cout << "Enter The Number Of Edges: ";
        cin >> edges;

        adjacencyMatrix = new VertexAndEdges * [vertex];
        for (int i = 0; i < vertex; i++)
        {
            adjacencyMatrix[i] = new VertexAndEdges[vertex];
        }

        pathArray = new int[vertex * vertex];
        for (int i = 0; i < vertex * vertex; i++)
        {
            pathArray[i] = -1;
        }
        pathCount = 0;
    }

    void AdjacencyMatrix()
    {
        char* variableNames = new char[vertex];
        for (int i = 0; i < vertex; i++)
        {
            variableNames[i] = char(65 + i);
        }

        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                cout << CYAN_TEXT << "Enter The Data For " << RESET << BLUE_TEXT << variableNames[i] << RESET
                    << CYAN_TEXT << " -> " << RESET << BLUE_TEXT << variableNames[j] << RESET
                    << CYAN_TEXT << " : ";
                adjacencyMatrix[i][j].Vertex1 = variableNames[i];
                adjacencyMatrix[i][j].Vertex2 = variableNames[j];
                cin >> adjacencyMatrix[i][j].data;
                cout << endl;
            }
        }

        StoreSum = new int[vertex];
        for (int i = 0; i < vertex; i++)
        {
            int rowSum = 0;
            for (int j = 0; j < vertex; j++)
            {
                rowSum += adjacencyMatrix[i][j].data;
            }
            StoreSum[i] = rowSum;
        }
    }

    void PrintAdjacencyMatrix()
    {
        cout << CYAN_TEXT << "Adjacency Matrix:" << RESET << endl;
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                cout << adjacencyMatrix[i][j].Vertex1
                    << adjacencyMatrix[i][j].edgerepresentation
                    << adjacencyMatrix[i][j].Vertex2
                    << "  " << adjacencyMatrix[i][j].data << endl;
            }
        }
    }

    void EulerCheck()
    {
        bool hasEulerCircuit = true;
        for (int i = 0; i < vertex; i++)
        {
            if (StoreSum[i] % 2 != 0)
            {
                hasEulerCircuit = false;
                break;
            }
        }
        if (hasEulerCircuit)
        {
            cout << GREEN_TEXT << "This is an Euler Circuit." << RESET << endl;
        }
        else
        {
            cout << RED_TEXT << "This is not an Euler Circuit. We need to find the Euler Path :)" << RESET << endl;
            FindEulerPath();
        }
    }

    void EulerPath(int start)
    {
        for (int i = 0; i < vertex; i++)
        {
            if (adjacencyMatrix[start][i].data > 0)
            {
                adjacencyMatrix[start][i].data--;
                adjacencyMatrix[i][start].data--;
                EulerPath(i);
            }
        }
        pathArray[pathCount] = start;
        pathCount++;
    }

    void Path()
    {
        cout << "Euler Path: ";
        for (int i = 0; i < vertex * vertex; i++)
        {
            if (pathArray[i] != -1)
            {
                cout << pathArray[i] << " ";
            }
        }
        cout << endl;
    }

    void FindEulerPath()
    {
        int count = 0;
        for (int i = 0; i < vertex; i++)
        {
            if (StoreSum[i] % 2 != 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            int startVertex = -1;
            StoreSum = new int[vertex];

            for (int i = 0; i < vertex; i++)
            {
                StoreSum[i] = 0;
                for (int j = 0; j < vertex; j++)
                {
                    StoreSum[i] += adjacencyMatrix[i][j].data;
                }
                if (StoreSum[i] % 2 != 0 && startVertex == -1)
                {
                    startVertex = i;
                }
            }

            if (startVertex == -1)
            {
                startVertex = 0;
            }

            EulerPath(startVertex);
            cout << endl;
            Path();
            cout << GREEN_TEXT << "\nThis is a Euler Path." << RESET << endl;
        }
        else
        {
            cout << RED_TEXT << "This is Not An Euler Path." << RESET << endl;
        }
    }

    void Hamiltonian()
    {
        bool flag = true;
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                if (StoreSum[i] + StoreSum[j] < vertex)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            cout << GREEN_TEXT << "\nThis is a Hamiltonian Circuit." << RESET << endl;
        }
        else
        {
            cout << RED_TEXT << "\nThis is Not a Hamiltonian Circuit." << RESET << endl;
            VertexDuplicate();
        }
    }

    void VertexDuplicate()
    {
        bool flag = true;
        for (int i = 1; i < pathCount - 1; i++)
        {
            for (int j = i + 1; j < pathCount - 1; j++)
            {
                if (pathArray[i] == pathArray[j])
                {
                    flag = false;
                    cout << RED_TEXT << "\nThis is not a Hamiltonian Path because vertices repeat :)" << RESET << endl;
                    return;
                }
            }
        }
        if (flag)
        {
            cout << GREEN_TEXT << "\nThis is a Hamiltonian Path." << RESET << endl;
            for (int i = 0; i < vertex; i++)
            {
                cout << pathArray[i] << " ";
            }
            cout << endl;
        }
    }
};
void printASCIIArt() {
    cout << "   ___  __ __  _        ___  ____        ____  ____   ___        __ __   ____  ___ ___  ____  _     ______   ___   ____   ____   ____  ____  " << endl;
    cout << "  /  _]|  T  T| T      /  _]|    \\      /    T|    \\ |   \\      |  T  T /    T|   T   Tl    j| T   |      T /   \\ |    \\ l    j /    T|    \\" << endl;
    cout << " /  [_ |  |  || |     /  [_ |  D  )    Y  o  ||  _  Y|    \\     |  l  |Y  o  || _   _ | |  T | |   |      |Y     Y|  _  Y |  T Y  o  ||  _  Y" << endl;
    cout << "Y    ]|  |  || l__ Y    ]|    /     |     ||  |  ||  D  Y    |  _  ||     ||  \\_/  | |  | | l__l_j  l_j|  O  ||  |  | |  | |     ||  |  |" << endl;
    cout << "|   [_ |  :  ||     T|   [_ |    \\     |  _  ||  |  ||     |    |  |  ||  _  ||   |   | |  | |     T |  |  |     ||  |  | |  | |  _  ||  |  |" << endl;
    cout << "|     Tl     ||     ||     T|  .  Y    |  |  ||  |  ||     |    |  |  ||  |  ||   |   | j  l |     | |  |  l     !|  |  | j  l |  |  ||  |  |" << endl;
    cout << "l____j \\__,_jl___jl___jlj\\_j    ljjljjl___j    ljjljjl_j_j|____jl___j lj   \\___/ ljj|____jljjlj_j" << endl;
}

int main()
{
    printASCIIArt();
    EulerAndHamiltonian obj;
    obj.AdjacencyMatrix();
    obj.PrintAdjacencyMatrix();

    bool flag = true;
    while (flag)
    {
        int choice;
        cout << CYAN_TEXT << "Choose an option:" << RESET << endl;
        cout << "1. Euler Check" << endl;
        cout << "2. Hamiltonian Check" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.EulerCheck();
            break;
        case 2:
            obj.Hamiltonian();
            break;
        case 3:
            cout << BLUE_TEXT << "Exiting the program." << RESET << endl;
            flag = false;
            break;
        default:
            cout << RED_TEXT << "Invalid choice. Please try again." << RESET << endl;
        }
    }

    return 0;
}