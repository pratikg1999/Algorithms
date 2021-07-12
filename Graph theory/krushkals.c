#include<stdio.h>
#include<stdlib.h>

// a structure to represent a weighted edge in graph
typedef struct Edge{
    int a;
    int b;
    int cost;
}Edge;

// a structure to represent a connected, undirected 
// and weighted graph 
typedef struct Graph{
    int n;
    int noedges;
    Edge* edges;
}Graph;


// A structure to represent a subset for union-find
typedef struct Subset{
    int parent;
    int rank;
}Subset;

void printSet(Subset *subsets, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", subsets[i].parent);
    }
    printf("\n");
}

// Creates a graph with n vertices
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
    (g->edges)[g->noedges] = e; 
    g->noedges++;
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
        if(((g->edges)[i]).cost<minEdge.cost && ((g->edges)[i]).cost!=-1){
            minEdge = (g->edges)[i];
            minIndex = i;
        }
    }
    ((g->edges)[minIndex]).cost = -1;
    return minEdge;
}

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(Subset* subsets, int v, int n){
    // find root and make root as parent of i  
    // (path compression) 
    if(subsets[v].parent == v){
        return v;
    }
    subsets[v].parent = find(subsets, subsets[v].parent, n);
    return subsets[v].parent;
}

// A function that does union of two sets of x and y 
// (uses union by rank) 
void un(Subset* subsets, int a,int b){
    subsets[b].parent = subsets[a].parent;
    subsets[subsets[a].parent].rank++;
}

// Function to check whether Edge e can be inserted in tree t
int canInsert(Graph* t, Edge e, Subset* subsets,int n){
    int i=0;
    //int fora = 0;
    //int forb = 0;
    find(subsets, e.a, n);
    find(subsets, e.b, n);
    int xRoot = subsets[e.a].parent;
    int yRoot = subsets[e.b].parent;
    if(xRoot==yRoot){
        return 0;
    }
    else{
        return 1;
    }

    /*
    for(i=0;i<t->noedges;i++){
        if(e.a == (((t->edges)[i]).a) || e.a == (((t->edges)[i]).b)){
            fora = 1;
        }
        if(e.b == (((t->edges)[i]).a) || e.b == (((t->edges)[i]).b)){
            forb = 1;
        }
    }
    */
    //return fora^forb;
}

//Function to build a tree from Graph
void buildTree(Graph* g, Graph* t, Subset* subsets, int n){
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
        printSet(subsets, n);
        if(canInsert(t, (g->edges)[i], subsets, n)){
            if(subsets[(g->edges)[i].a].rank>=subsets[(g->edges)[i].b].rank){
                un(subsets, subsets[(g->edges)[i].a].parent, subsets[(g->edges)[i].b].parent);
            }
            else if (subsets[(g->edges)[i].a].rank<subsets[(g->edges)[i].b].rank){
                un(subsets, subsets[(g->edges)[i].a].parent, subsets[(g->edges)[i].b].parent);

            }
            addEdge(t, (g->edges)[i]);
            break;
        }
    }
}

//Utility function to print a grapph
void print(Graph* g){
    printf("\n");
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
        a--;//if error remove it
        scanf("%d", &b);
        b--;//if error remove it
        scanf("%d", &cost);
        addEdge(g, newEdge(a,b,cost));
    }
    Subset subsets[n];
    for(i=0;i<n;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Step 1:  Sort all the edges in non-decreasing order of their weight.
    sortEdges(g);
    print(g);
    //addEdge(t, (g->edges)[0]);
    while(t->noedges < g->n-1 && g->noedges>0){
        buildTree(g, t, subsets, n);
    }
    print(t);
    printf("\n");
}
