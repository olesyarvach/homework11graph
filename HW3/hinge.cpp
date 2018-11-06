/*Поиск точек сочленения (шарнира), 
(вершина, при удалении которой граф стоновится несвязным)*/



vector<int> g[N];
bool used[N];
int time, tin[N], fup[N];
 
void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = time++;
	int child = 0;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
				is_joint_point(v);
			++child;
		}
	}
	if (p == -1 && child > 1)
		is_joint_point(v);
}
 
int main() {
	int n;
	
 
	time = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	dfs (0);
}
