#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;  

vector<string> cities = {
    "Delhi", "Chandigarh", "Jaipur", "Agra", "Lucknow",
    "Varanasi", "Patna", "Kolkata", "Shimla", "Amritsar",
    "Ludhiana", "Ahmedabad", "Mumbai", "Pune", "Hyderabad",
    "Bangalore", "Chennai"
};

unordered_map<string, int> cityIndex;
vector<vector<pii>> graph;

void addRoad(int u, int v, int dist) {
    graph[u].push_back({v, dist});
    graph[v].push_back({u, dist});
}

void buildGraph() {
    int n = cities.size();
    graph.resize(n);

    for (int i = 0; i < n; i++)
        cityIndex[cities[i]] = i;

    addRoad(cityIndex["Delhi"],       cityIndex["Chandigarh"],  250);
    addRoad(cityIndex["Delhi"],       cityIndex["Jaipur"],      280);
    addRoad(cityIndex["Delhi"],       cityIndex["Agra"],        200);
    addRoad(cityIndex["Delhi"],       cityIndex["Lucknow"],     550);
    addRoad(cityIndex["Chandigarh"],  cityIndex["Shimla"],      115);
    addRoad(cityIndex["Chandigarh"],  cityIndex["Amritsar"],    230);
    addRoad(cityIndex["Chandigarh"],  cityIndex["Ludhiana"],     95);
    addRoad(cityIndex["Jaipur"],      cityIndex["Agra"],        240);
    addRoad(cityIndex["Jaipur"],      cityIndex["Ahmedabad"],   660);
    addRoad(cityIndex["Agra"],        cityIndex["Lucknow"],     330);
    addRoad(cityIndex["Lucknow"],     cityIndex["Varanasi"],    320);
    addRoad(cityIndex["Varanasi"],    cityIndex["Patna"],       250);
    addRoad(cityIndex["Patna"],       cityIndex["Kolkata"],     600);
    addRoad(cityIndex["Amritsar"],    cityIndex["Ludhiana"],    135);
    addRoad(cityIndex["Ahmedabad"],   cityIndex["Mumbai"],      530);
    addRoad(cityIndex["Mumbai"],      cityIndex["Pune"],        150);
    addRoad(cityIndex["Mumbai"],      cityIndex["Hyderabad"],   710);
    addRoad(cityIndex["Pune"],        cityIndex["Hyderabad"],   560);
    addRoad(cityIndex["Hyderabad"],   cityIndex["Bangalore"],   570);
    addRoad(cityIndex["Hyderabad"],   cityIndex["Chennai"],     630);
    addRoad(cityIndex["Bangalore"],   cityIndex["Chennai"],     350);
}

pair<vector<int>, vector<int>> dijkstra(int src) {
    int n = cities.size();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;  

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return {dist, prev};
}


vector<int> getPath(vector<int>& prev, int src, int dest) {
    vector<int> path;
    for (int cur = dest; cur != -1; cur = prev[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
    if (path.empty() || path[0] != src) return {};
    return path;
}

void printCities() {
    cout << "\n--- Available Cities ---\n";
    for (int i = 0; i < (int)cities.size(); i++)
        cout << "  " << i << ". " << cities[i] << "\n";
    cout << "------------------------\n";
}

int main() {
    buildGraph();

    cout << "====================================\n";
    cout << "  Route Optimization System\n";
    cout << "  Using Dijkstra's Algorithm\n";
    cout << "  DAA Mini Project | Group G\n";
    cout << "====================================\n";

    char again = 'y';
    while (again == 'y' || again == 'Y') {

        printCities();

        int src, dest;
        cout << "\nEnter source city number: ";
        cin >> src;
        cout << "Enter destination city number: ";
        cin >> dest;

        if (src < 0 || src >= (int)cities.size() ||
            dest < 0 || dest >= (int)cities.size()) {
            cout << "\nInvalid input. Try again.\n";
            continue;
        }

        if (src == dest) {
            cout << "\nSource and destination are the same!\n";
            continue;
        }

        // Run the algorithm
        auto [dist, prev] = dijkstra(src);

        if (dist[dest] == INT_MAX) {
            cout << "\nNo path found between " << cities[src]
                 << " and " << cities[dest] << "\n";
        } else {
            vector<int> path = getPath(prev, src, dest);

            cout << "\n--- Result ---\n";
            cout << "Source      : " << cities[src] << "\n";
            cout << "Destination : " << cities[dest] << "\n";
            cout << "Total Dist  : " << dist[dest] << " km\n";
            cout << "\nShortest Path:\n  ";
            for (int i = 0; i < (int)path.size(); i++) {
                cout << cities[path[i]];
                if (i != (int)path.size() - 1) cout << " -> ";
            }
            cout << "\n\nStep-by-step:\n";
            for (int i = 0; i < (int)path.size() - 1; i++) {
                int u = path[i], v = path[i+1];
                // find edge weight
                int w = 0;
                for (auto [nb, wt] : graph[u])
                    if (nb == v) { w = wt; break; }
                cout << "  " << cities[u] << " -> " << cities[v]
                     << " : " << w << " km\n";
            }
            cout << "--------------\n";
        }

        cout << "\nFind another route? (y/n): ";
        cin >> again;
    }

    cout << "\nThank you!\n";
    return 0;
}
