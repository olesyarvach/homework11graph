/* Топологическая сортировка. Пользуемся обходом в глубину*/




int n; // число вершин
vector<int> g[maxN]; // граф
bool used[maxN];
vector<int> answer;
 
void dfs (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs (to);
	}
	answer.push_back (v);
}
 
void top_sort() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	answer.clear();
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
	reverse (answer.begin(), answer.end());
}
