#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>
using namespace std;
struct compare{
    bool operator()(const pair<long long int,long long int> &a,const pair<long long int,long long int>&b){
        return a.first > b.first;
    }
};
vector<long long int> dks(vector<list<pair<long long int,long long int>>> graph,long long int src){
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,compare>pq;
    vector<long long int>distance(graph.size(),LLONG_MAX);
    vector<bool>visited(graph.size(),false);
    pq.push(make_pair(0,src));
    distance[src]=0;
    while(!pq.empty()){
        pair<long long int,long long int>curr = pq.top();pq.pop();
        //cout << "at top :" << curr.first << ":" << curr.second << endl;
        if(visited[curr.second]==false){
            visited[curr.second]=true;
            //cout <<curr.second<<" adjacent nodes " << curr.second << " --> "; 
            for(list<pair<long long int,long long int>>::iterator it=graph[curr.second].begin();it!=graph[curr.second].end();it++){
            	//cout << it->first << "," << it->second << " ";
                if(visited[it->first] !=true and  distance[it->first]>(distance[curr.second]+it->second)){
                    distance[it->first]=distance[curr.second]+it->second;
                    pq.push(make_pair(distance[it->first],it->first));
                }
            }
            //cout << endl;
        }
    }
    return distance;
}
int main(){
    int t;
    cin >> t;
    while(t--){
 
        long long int vert,old_vertices,old_wght,new_vertices,src,src_vert,dest_vert,wght;
        cin >> vert >> old_vertices >> old_wght >> new_vertices >> src;
        vector<list<pair<long long int,long long int>>>graph;
        graph.resize(vert+1);
 		old_wght = old_wght * 2;
 		//cout << "new old_wght: " << old_wght<< endl;
        for(long long int i=0;i<new_vertices;i++){
            cin>>src_vert>>dest_vert>>wght;
            graph[src_vert].push_back(make_pair(dest_vert,wght * 2));
            graph[dest_vert].push_back(make_pair(src_vert,wght * 2));
        }
        for(long long int i=1;i<=old_vertices;i++){
            graph[i].push_back(make_pair(0,old_wght/2));
            graph[0].push_back(make_pair(i,old_wght/2));
        }
        vector<long long int>distance = dks(graph,src);
        for(long long int i=1;i<=vert;i++){
            cout<<distance[i] / 2<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
