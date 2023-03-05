#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

vector<char> farms;
vector<vector<int>> adj;

bool walk(int start, int end, char cow, bool found, vector<bool> visited)
{
	if (cow == farms[start])
		found = true;
	if (start == end)
		return found;
	if (adj[start].size() == 0)
		return false;

	visited[start] = true;

	for (int farm : adj[start])
	{
		if (!visited[farm] && walk(farm, end, cow, found, visited)) {
			visited[start] = false;
			return true;
		}
	}

	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	farms = vector<char>(n, -1);
	for (char& f : farms)
	{
		cin >> f;
	}

	adj = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	std::string output = "";

	for (int i = 0; i < m; i++) {
		int start, end;
		char cow;
		cin >> start >> end >> cow;
		start--;
		end--;

		vector<bool> visited(n, false);

		if (walk(start, end, cow, false, visited)) {
			output += "1";
		}
		else {
			output += "0";
		}
	}

	cout << output;

	return 0;
}