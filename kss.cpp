#include<bits/stdc++.h>
#include<time.h>
using namespace std;
typedef long long ll;
template<typename T>inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;}
inline long long ceill(ll a , ll b){return (a % b == 0 ? a / b : a / b + 1);}
inline long long lcm(ll a , ll b){return a * b / gcd(a, b);}
#define endl '\n'
#define MOD 1000000007
#define MAX 1e18
#define pb push_back
#define ppb emplace_back
#define int long long
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
vector<int> parent;
vector<int> Rank;
struct Edge{
    int src , dest ;
};
int find(int x){
    if(parent[x] == x) return x; 
    return find(parent[x]);
}
void Union(int u , int v){
    int a = find(u) ;
    int b = find(v) ; 
    if(a != b){
        if(Rank[a] < Rank[b]){
            swap(a , b);
        }
        parent[b] = a ; 
        if(Rank[a] == Rank[b]){
            Rank[a]++;
        }
    }
}
int Mincut(int n , int m , vector<Edge> & G){
    int V = n ; 
    while(V > 2){
        int i = rand() % m;
        int u = find(G[i].src); 
        int v = find(G[i].dest);
        if(u == v){
            continue;
        } 
        cout << "Contracting edge : " << u <<" " << v << endl;
        Union(u , v);
        V--;
    }
    int cut = 0; 
    for(int i = 0 ; i < m ; i++){
        if(find(G[i].src) != find(G[i].dest)){
            cut++;
        }
    }   
    return cut;
}
void solve(){
    int n , m ; 
    cin >> n >> m; 
    parent.assign(n + 1 , 0);
    Rank.assign(n + 1 , 0);
    vector<Edge> Grph ; 
    for(int i = 0 ; i < m ; i++){
        int u , v ; 
        cin >> u >> v; 
        Grph.pb({u , v});
    }
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i ; 
    }
    srand(time(NULL));

    cout << "Mincut FOund !::: \n" << Mincut(n , m , Grph) << endl;
    
}
int32_t main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int t ; 
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}