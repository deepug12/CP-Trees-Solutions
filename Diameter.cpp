/* If Code goes infinite then type   taskkill -im 1.exe -f
  */
#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;

const int N = 1e5+10;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int par = -1){

    for (int child : g[vertex])
    {
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }

}


int main()
{
    // // ios_base::sync_with_stdio(false);
    // // cin.tie(NULL);
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin>>n;
        for (int i = 0; i < n-1; ++i)
        {
            int x, y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);

        }
        dfs(1);
        int mx_depth = -1;
        int mx_d_node;
        for (int i = 1; i <= n; ++i)
        {
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;              
        }
        dfs(mx_d_node);
        mx_depth = -1;
        for (int i = 1; i <= n; ++i)
        {
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
        }            
        }
        cout<<mx_depth<<"\n";

    // } 
    return 0;
}
