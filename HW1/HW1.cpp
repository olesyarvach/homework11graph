/*Дан граф G=(V,E) и две вершины s и t. Необходимо проверить, существует ли путь из вершины s в вершину t по рёбрам графа G.*/


bool dfs(u, t: int, visit: bool[]):             
    if u == t
        return true    
    visit[u] = true                              // отметим вершину как пройденную
    for v: uv ∈ E                                  // пройдем по смежным с u вершинам
        if not visit[v]                          // проверка: не находились ли мы раннее в данной вершине
            if dfs(v, t, visit)
                return true
    return false
