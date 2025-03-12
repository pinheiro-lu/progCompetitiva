// dfs adapted to create sparse table
void dfs(int idx, int pai, int depth) {
	//cerr << pai << " me trouxe aqui " << idx << '\n';
	if (idx == -1) return;
	pos.at(idx) = cnt;
	id.at(cnt) = idx;
	if (nvl.at(idx) == -1) nvl.at(idx) = depth;
	dep.at(cnt) = nvl.at(idx);
	if (vis.at(idx)) return;
	vis.at(idx) = true;
	for (int &x : adj.at(idx)) {
		if (x == pai) continue;
		++cnt;
		dfs(x, idx, depth+1);
	}
	++cnt;
	dfs(pai, idx, depth+1);
}

// st is the array of sparse table
// m == n*2-1
// dep is the array of depth
st.push_back(dep);
for (int i = 1; (1 << i) < m; ++i) {
	st.push_back({});
	for (int j = 0; j <= m - (1 << i); ++j) {
		st.at(i).at(j) = min(st.at(i-1).at(j), st.at(i-1).at(j + (1 << (i-1))));
	}
}

// gets the minimum value between f and l (the depth of the lca)
int lca_dep = min(st.at(w).at(f), st.at(w).at(l+1 - (1<<w)));
