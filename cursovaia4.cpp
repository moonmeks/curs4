#include <iostream>
#include <vector>

using namespace std;

// Вспомогательная функция для рекурсивного поиска пути
void findPathHelper(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path, int current, int end, bool& found)
{
    if (current == end && path.size() >= graph.size()) {
        found = true;
        return;
    }
    for (int neighbor : graph[current]) {
        if (!visited[neighbor] || neighbor == end) {
            visited[neighbor] = true;
            //cout << neighbor << " ";
            path.push_back(neighbor);
            findPathHelper(graph, visited, path, neighbor, end, found);
            // Если путь найден, выходим из цикла
            if (found || neighbor == end) {
                return;
            }
            // Если путь не найден, отмечаем вершину как непосещенную и удаляем ее из пути
           visited[neighbor] = false;
           path.pop_back();
        }
    }
}
void findPath(vector<vector<int>>& graph, int start, int end) 
{
    setlocale(LC_ALL, "Russian");
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> path;

    // Помечаем начальную вершину как посещенную
    visited[start] = true;
    path.push_back(start);

    // Рекурсивно ищем путь
    bool found = false;
    findPathHelper(graph, visited, path, start, end, found);

    // Выводим найденный путь и его длину
    if (found) {
        cout << "Путь: ";
        for (int vertex : path) {
            cout << vertex + 1 << " ";
        }
        cout << endl;
        //cout << "Длина пути: " << path.size() - 1 << endl;
    }
    else {
        cout << "Путь не найден." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int start, end;

    cout << "Введите начальную вершину: ";
    cin >> start;
    cout << "Введите конечную вершину: ";
    cin >> end;

    start--;
    end--;

    vector<vector<int>> graph = {
        {1,2,3},
        {3,4},
        {4,5,7},
        {4},
        {2,11},
        {6,11},
        {5},
        {4, 8},
        {7, 10},
        {6},
        {9},
        {12, 14,15},
        {13},
        {11,14},
        {15,16},
        {16},
        {17},
        {}
    };
    double time_spent = 0.0;
    clock_t begin = clock();

    findPath(graph, start, end);

    clock_t end1 = clock();
    time_spent += (double)(end1 - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds", time_spent);
    return 0;
}
