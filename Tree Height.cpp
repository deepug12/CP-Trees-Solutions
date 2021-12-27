/* If Code goes infinite then type   taskkill -im 1.exe -f
  */
#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;

const int N = 1e5+10;
vector<int> g[N];
int depth[N], height[N];

void dfs(int vertex, int par = 0){

    for (int child : g[vertex])
    {
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
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
            int v1, v2;
            cin>>v1>>v2;
            g[v1].push_back(v2);
            g[v2].push_back(v1);

        }
        dfs(1);
        int ct = 0;
        for (int i = 1; i <= n; ++i)
        {
            cout<<"Depth :"<<depth[i]<<"  height: "<<height[i]<<"\n";
                
        }
    // } 
    return 0;
}
