#include <bits/stdc++.h>
using namespace std;

static bool cmp(const pair<int,int>&a, const pair<int,int>&b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
    
}

int main() {
	// your code goes here
    int n,m;
    cin>>n>>m;
    multiset<int> tickets;
for (int i = 0; i < n; i++) {
    int price; cin >> price;
    tickets.insert(price);
}

for (int i = 0; i < m; i++) {
    int max_price; cin >> max_price;
    auto it = tickets.upper_bound(max_price);
    
    if (it == tickets.begin()) {
        cout << -1 << "\n";
    } else {
        --it;
        cout << *it << "\n";
        tickets.erase(it); // Remove the specific ticket sold
    }
}
    
    
}
