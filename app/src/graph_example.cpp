// Απλή υλοποίηση κλάσης γραφήματος για τα προβλήματα Toronto --> Graph
// Απευθείας γειτονικές κορυφές για κάθε κορυφή --> set<int> Graph::get_neighbors(int v)
// Έλεγχος εγκυρότητας χρωματισμού --> bool check_coloring(Graph g, int *solution)
// -------------------------------------------------------------------------------
// WARNING: Η συγκεκριμένη υλοποίηση προσπαθεί να είναι απλή, αυτό δεν σημαίνει ότι είναι και αποδοτική (:

#include <iostream>
#include <set>

using namespace std;

class Graph
{
private:
    int V;     // πλήθος των κορυφών του γραφήματος
    int *data; // πίνακας γειτνίασης

public:
    Graph(int v) : V(v)
    {
        data = new int[v * v];
        for (int i = 0; i < v * v; i++)
        {
            data[i] = 0;
        }
    }
    ~Graph()
    {
        delete[] data;
    }

    int get_V()
    {
        return V;
    }

    void insert_edge(int i, int j, int value)
    {
        data[i * V + j] = value;
    }

    int get_edge_value(int i, int j)
    {
        return data[i * V + j];
    }

    // επιστρέφει ένα set από ακεραίους που είναι
    // οι αριθμοί κορυφών με τους οποίους συνδέεται απευθείας η κορυφή v
    set<int> get_neighbors(int v)
    {
        set<int> neighbors;
        for (int j = 0; j < V; j++)
        {
            if (get_edge_value(v, j) > 0)
                neighbors.insert(j);
        }
        return neighbors;
    }
};

bool check_coloring(Graph g, int *solution)
{
    bool proper_coloring = true;
    for (int v = 1; v <= g.get_V(); v++)
    {
        int color_v = solution[v];
        set<int> neighbors_of_v = g.get_neighbors(v);
        for (int v2 : neighbors_of_v)
        {
            int color_v2 = solution[v2];
            if (color_v == color_v2)
            {
                proper_coloring = false;
                goto jump;
            }
        }
    }
jump:
    return proper_coloring;
}

int main()
{
    int V = 5; // αριθμός κορυφών

    Graph a_graph(V + 1); // δεδομένα από το toy_e5_s6.stu
    a_graph.insert_edge(1, 2, 1);
    a_graph.insert_edge(2, 1, 1);
    a_graph.insert_edge(1, 3, 1);
    a_graph.insert_edge(3, 1, 1);
    a_graph.insert_edge(3, 4, 1);
    a_graph.insert_edge(4, 3, 1);
    a_graph.insert_edge(3, 5, 3);
    a_graph.insert_edge(5, 3, 3);
    a_graph.insert_edge(4, 5, 1);
    a_graph.insert_edge(5, 4, 1);

    for (int v = 1; v <= V; v++)
    {
        set<int> neighbors = a_graph.get_neighbors(v);
        cout << "Vertex:" << v << " has neighbors: ";
        for (int v2 : neighbors)
        {
            cout << v2 << " ";
        }
        cout << endl;
    }

    // 1 --> κόκκινο
    // 2 --> μπλε
    // 3 --> μωβ
    int solution[] = {-1, 1, 2, 2, 1, 3}; // το πρώτο στοιχείο του πίνακα δεν χρησιμοποιείται

    bool proper_coloring = check_coloring(a_graph, solution);
    if (proper_coloring)
    {
        cout << "This is a proper coloring" << endl;
    }
    else
    {
        cout << "This is not a proper coloring" << endl;
    }

    solution[4] = 2; // ανάθεση του "χρώματος" 2 στην κορυφή 4
    proper_coloring = check_coloring(a_graph, solution);
    if (proper_coloring)
    {
        cout << "This is a proper coloring" << endl;
    }
    else
    {
        cout << "This is not a proper coloring" << endl;
    }
}

/*
Vertex:1 has neighbors: 2 3 
Vertex:2 has neighbors: 1   
Vertex:3 has neighbors: 1 4 5
Vertex:4 has neighbors: 3 5
Vertex:5 has neighbors: 3 4
This is a proper coloring
This is not a proper coloring
*/