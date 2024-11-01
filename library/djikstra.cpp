// dist is a vector of size n+1, initialized to INF
// q is a priority queue of pairs of ints
// adj is a vector of vectors of bools
// we are calculating the weights adding the mana related to the monsters
// proc is a vector of bools initialized to false
// first item of queue pair is the distance, second is the node
// complexity: O(n + m log m) where n is the number of nodes and m is the number of edges
dist.at(0) = 0;
q.push({-dist.at(0),0});
while (!q.empty()) {
	int a = q.top().second; q.pop();
	if (proc.at(a)) continue;
	proc.at(a) = true;
	for (int i = 0; i <= n; ++i) {
		if (!adj.at(a).at(i)) continue;
		vector<int> &u = mon.at(a).at(i);
		int sum = 0;
		for (int &x : u) sum += mana.at(x);
		if (sum + dist.at(a) < dist.at(i)) {
			dist.at(i) = sum + dist.at(a);
			q.push({-dist.at(i), i});
		}
	}
}
