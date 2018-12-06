#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
    int a;
    int b;
    int cost;
}Edge;

typedef struct Graph{
    int n;
    int noedges;
    Edge* edges;
}Graph;


Graph newGraph(int n){
    Graph g;
    g.n = n;
    g.noedges = 0;
    g.edges = (Edge*)malloc(sizeof(Edge)*n);
    return g;
}

Edge newEdge(int a,int b, int cost){
    Edge e;
    e.a = a;
    e.b = b;
    e.cost = cost;
    return e;
}

void addEdge(Graph g, Edge e){
    (g.edges)[g.noedges++] = e; 
}
void swap(Edge* edges, int i,int j){
    Edge temp  = edges[i];
    edges[i] = edges[j];
    edges[j] = temp;
}
void sortEdges(Graph g){
    int i=0;
    int j = 0;
    for(i=0;i<g.noedges;i++){
        for(j=0;j<g.noedges-1;j++){
            if(((g.edges)[j]).cost> ((g.edges)[j]).cost){
                swap(g.edges, j,j+1);
            }
        }
    }
}
Edge findMinEdge(Graph g){
    int i =0;
    int minIndex = -1;
    Edge minEdge = (g.edges)[0];
    for(i=0;i<g.noedges;i++){
        if(((g.edges)[i]).cost<minEdge.cost){
            minEdge = (g.edges)[i];
            minIndex = i;
        }
    }
    ((g.edges)[minIndex]).cost = -1;
    return minEdge;
}

buildTree(Graph g, Graph t){
    
}
void main(){
    int n,i,j, noedges;
    int a,b,cost;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the no of edges: ");
    scanf("%d", &noedges);
    
    Graph g = newGraph(n);
    printf("Enter the edges and their cost\n");
    for(i=0;i<noedges;i++){
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &cost);
        addEdge(g, newEdge(a,b,cost));
    }
    sortEdges(g);
    Graph t = newGraph(n);
    addEdge(t, (g.edges)[0]);
    while(t.noedges < g.n-1 && g.noedges>0){
        buildTree(g, t);
    }
}
