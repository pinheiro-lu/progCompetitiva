#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    // Read A_0 ... A_N (total N+1 elements)
    vector<long long> A(N+1);
    for (int i = 0; i <= N; i++) {
        cin >> A[i];
    }

    // Compute B_i = A_i - i*K
    vector<long long> B(N+1);
    for (int i = 0; i <= N; i++) {
        B[i] = A[i] - i * K;
    }

    // First sweep: build monotonic decreasing stack of indices
    vector<int> initStack;
    initStack.reserve(N+1);
    for (int i = N; i >= 0; --i) {
        while (!initStack.empty() && B[initStack.back()] >= B[i]) {
            initStack.pop_back();
        }
        initStack.push_back(i);
    }

    // Second sweep: for each i, find the next smaller element index (with wrap)
    vector<int> nextSmaller(N+1, -1);
    vector<int> stk = initStack;  // copy for the second sweep

    for (int i = N; i >= 0; --i) {
        while (!stk.empty() && B[stk.back()] >= B[i]) {
            stk.pop_back();
        }
        nextSmaller[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
    }

    // Output the resulting indices j for each i = 0..N
    for (int i = 0; i <= N; i++) {
        cout << nextSmaller[i] << (i < N ? ' ' : '\n');
    }

    return 0;
}
