/* проверка: является ли граф деревом*/



bool dfs(int i, int arr[SIZE][SIZE], bool col[SIZE]) {
  if (col[i]) {
    return 0;
  }
  col[i] = true;
  for (int j = 0; j < SIZE; ++j) {
    if (ar[i][j]) {
      dfs(j, arr, col);
    }
  }
}

bool IsTree(int arr[SIZE][SIZE]) {
  int edges = 0;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = i + 1; j < SIZE; ++j) {
      if (arr[i][j]) {
        edges++;
      }
    }
  }
  if (edges != SIZE - 1) {
    return false;
  }
  bool col[SIZE];
  memset(col, 0, sizeof(col));
  dfs(0, arr, col);
  for (int i = 0; i < SIZE; ++i) {
    if (!col[i]) {
      return false;
    }
  }
  return true;
}
