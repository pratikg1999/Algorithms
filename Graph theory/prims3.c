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


Graph* newGraph(int n){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->noedges = 0;
    g->edges = (Edge*)malloc(sizeof(Edge)*n);
    return g;
}

Edge newEdge(int a,int b, int cost){
    Edge e;
    e.a = a;
    e.b = b;
    e.cost = cost;
    return e;
}

void addEdge(Graph* g, Edge e){
    (g->edges)[g->noedges++] = e; 
}
void swap(Edge* edges, int i,int j){
    Edge temp  = edges[i];
    edges[i] = edges[j];
    edges[j] = temp;
}
void sortEdges(Graph* g){
    int i=0;
    int j = 0;
    for(i=0;i<g->noedges;i++){
        for(j=0;j<g->noedges-1;j++){
            if(((g->edges)[j]).cost > ((g->edges)[j+1]).cost){
                swap(g->edges, j,j+1);
            }
        }
    }
}
Edge findMinEdge(Graph* g){
    int i =0;
    int minIndex = -1;
    Edge minEdge = (g->edges)[0];
    for(i=0;i<g->noedges;i++){
        if(((g->edges)[i]).cost<minEdge.cost){
            minEdge = (g->edges)[i];
            minIndex = i;
        }
    }
    ((g->edges)[minIndex]).cost = -1;
    return minEdge;
}

int canInsert(Graph* t, Edge e){
    int i=0;
    int fora = 0;
    int forb = 0;
    for(i=0;i<t->noedges;i++){
        if(e.a == (((t->edges)[i]).a) || e.a == (((t->edges)[i]).b)){
            fora = 1;
        }
        if(e.b == (((t->edges)[i]).a) || e.b == (((t->edges)[i]).b)){
            forb = 1;
        }
    }
    return fora^forb;
}

void buildTree(Graph* g, Graph* t){
    int i=0;
    /*int minIndex = -1;
    Edge minEdge = (g->edges)[t->noedges];
    for(i=t->noedges;i<g->noedges;i++){
        //if(((g->edges)[i]).cost < minEdge.cost){
            if(!isEdgePresentIn(t, (g->edges)[i])){
                minEdge = (g->edges)[i];
                minIndex = i;
            }
        //} 
    }*/
    for(i=0;i<g->noedges;i++){
        if(canInsert(t, (g->edges)[i])){
            addEdge(t, (g->edges)[i]);
        }
    }
}

void print(Graph* g){
    int i=0;
    for(i=0;i<g->noedges;i++){
        printf("%d %d %d\n", ((g->edges)[i]).a, ((g->edges)[i]).b, ((g->edges)[i]).cost);
    }
    printf("\n");
}
void main(){
    int n,i,j, noedges;
    int a,b,cost;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the no of edges: ");
    scanf("%d", &noedges);
    
    Graph* g = newGraph(n);
    Graph* t = newGraph(n);
    printf("Enter the edges and their cost\n");
    for(i=0;i<noedges;i++){
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &cost);
        addEdge(g, newEdge(a,b,cost));
    }
    sortEdges(g);
    print(g);
    addEdge(t, (g->edges)[0]);
    while(t->noedges < g->n-1 && g->noedges>0){
        buildTree(g, t);
    }
    print(t);
    printf("\n");
}
