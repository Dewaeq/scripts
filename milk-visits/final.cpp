#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

vector<char> farms;
vector<vector<int>> adj;


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

	int group = 0;
	vector<int> groups(n, -1);

	for (int i = 0; i < n; i++) {
		if (groups[i] != -1) continue;

		vector<int> reachable = { i };
		char cow = farms[i];

		while (!reachable.empty()) {
			int farm = reachable.back();
			reachable.pop_back();
			groups[farm] = group;

			for (int f : adj[farm]) {
				if (farms[f] == cow && groups[f] == -1) {
					reachable.push_back(f);
				}
			}
		}

		group++;
	}


	std::string output = "";

	for (int i = 0; i < m; i++) {
		int start, end;
		char cow;
		cin >> start >> end >> cow;
		start--;
		end--;

		if (groups[start] != groups[end]) {
			output += "1";
		}
		else if (groups[start] == groups[end] && cow == farms[start]) {
			output += "1";
		}
		else {
			output += "0";
		}
	}

	cout << output;

	return 0;
}