#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> cows(100000);
vector<int> adj[100000];
bool visited[100000];
int min_x, max_x, min_y, max_y;


void dfs(int cow) {
	if (visited[cow])
		return;

	visited[cow] = true;

	min_x = min(min_x, cows[cow].first);
	max_x = max(max_x, cows[cow].first);
	min_y = min(min_y, cows[cow].second);
	max_y = max(max_y, cows[cow].second);
	for (int i : adj[cow]) {
		dfs(i);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int per = 1000000000;

	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;

		min_x = cows[i].first;
		max_x = cows[i].first;
		min_y = cows[i].second;
		max_y = cows[i].second;

		dfs(i);

		per = min(per, 2 * (max_x - min_x + max_y - min_y));
	}

	cout << per << endl;
}
