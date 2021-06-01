/*
	Лабораторная работа №8. Имаев Азат. 16ПИ.
 
	Вариант 7. Найти самый длинный простой пусть в графе.
*/
#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <list>
 
using namespace std;
 
// Тип который переименнуется.
typedef int vertex_t;
 
// Схема хранения графа будет представленна через: Список (множеств) ребер.
class Graph_type1
{
public:
	// Конструктор без параматров (по умолчанию).
	Graph_type1() : vertexes_number(0), edges_numbers(0)
	{ }
 
	void Input()
	{
		cout << "Количество вершин в графе: ";
		cin >> vertexes_number;
		cout << "Количество ребер: ";
		cin >> edges_numbers;
 
		set_of_edges.clear();
		for (vertex_t i = 0; i < edges_numbers; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
			/*
				make_pair - формировать новый элемент пары.
				insert - добавление пары.
			*/
			set_of_edges.insert(make_pair(a, b));
		}
	}
 
	void print() const
	{
		cout << "\nКоличество вершин: " << vertexes_number << endl;
 
		// Перебор всех элементов. Принцип как у foreach в JS.
		for (auto edge : set_of_edges)
		{
			cout << '(' << edge.first << ", " << edge.second << ") ";
		}
		cout << endl;
	}
private:
	// Множество пар двух целочисленных структур.
	set< pair<vertex_t, vertex_t> > set_of_edges;
 
	// Количество вершин и ребер.
	int vertexes_number;
	int edges_numbers;
};
 
// Схема хранения графа будет представленна через: Матрицу смежности.
class Graph_type2
{
public:
	// Конструктор без параматров (по умолчанию).
	Graph_type2() : vertexes_number(0), edges_numbers(0)
	{ }
 
	int Input()
	{
		cout << "Количество вершин в графе: ";
		cin >> vertexes_number;
		cout << "Количество ребер: ";
		cin >> edges_numbers;
 
		// Заполняем весь массив и подставляем значения false во все ячейки.
		matrix.resize(vertexes_number, vector<bool>(vertexes_number, false));
 
 
		for (vertex_t i = 0; i < edges_numbers; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
 
			matrix[a][b] = 1;
			matrix[b][a] = 1;
		}
		return vertexes_number;
	}
 
	void DFS(int start, vector<bool>& visited)
	{
		visited[start] = true;
 
		cout << start << " ";
 
		for (int i = 0; i < vertexes_number; i++)
		{
			if ((matrix[start][i] == true) && (!visited[i]))
				DFS(i, visited);
		}
	}
 
	void print() const
	{
		cout << "\nКоличество вершин: " << vertexes_number << endl;
 
		// Проходимся по строкам.
		for (vertex_t a = 0; a < vertexes_number; a++)
		{
			// Проходимся по столбцам.
			for (vertex_t b = 0; b < vertexes_number; b++)
			{
				cout << matrix[a][b] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
private:
	// Множество векторов.
	vector< vector<bool> > matrix;
 
	// Количество вершин и ребер.
	int vertexes_number;
	int edges_numbers;
};
 
 
 
 
class Graph
{
	int V; 
 
	list<int> *adj;
 
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V); 
 
	void addEdge(int v, int w);
 
	void DFS(int v);
};
 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}
 
void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
 
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}
 
void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
 
	DFSUtil(v, visited);
}
 
int main()
{
	setlocale(LC_ALL, "Russian");
	// Вывод графа
	/*
	Graph_type1 g;
	g.Input();
	g.print();
	*/
 
	/*
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	*/
 
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2,4);
	g.addEdge(3,3);
	g.addEdge(4, 4);
 
 
	cout << "Выходной графф:\n";
	g.DFS(0);
	cout << endl;
	return 0;
}