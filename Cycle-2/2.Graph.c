#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct graph{

	int adjmat[MAX][MAX];
	int visited[MAX];
	int n;
}g;
int queue[MAX];
void dfs(int u);
void addnode(int x,int y);
void insert();
void enqueue(int x);
int dequeue();
int is_queue_empty();
void bfs(int u);
void reset();
int front=0,rear=-1;
int main()
{
    
    printf("Enter the number of vertices: ");
    scanf("%d", &g.n);
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
           g.adjmat[i][j]=0;
        }
    }
    reset();
	insert();
	printf("THE DFS SEARCH RESULTS...\n");
    dfs(0);
    reset();
    printf("THE BFS SEARCH RESULTS...\n");
    bfs(0);

    return 0;
}
void dfs(int u)
{
    
    g.visited[u] = 1;
    printf("%d \n",u);

    
    for (int v = 0; v < g.n; v++) {
        if (g.adjmat[u][v] && !g.visited[v]) {
            dfs(v);
        }
    }
}
void bfs(int u)
{
    
    g.visited[u] = 1;
    printf("%d \n ", u);
    enqueue(u);
    while (!is_queue_empty()) {
        int v = dequeue();
        for (int w = 0; w < g.n; w++) {
            if (g.adjmat[v][w] && !g.visited[w]) {
                g.visited[w] = 1;
                printf("%d \n", w);
                enqueue(w);
            }
        }
    }
}

void addnode(int x,int y)
{
	g.adjmat[x][y]=g.adjmat[y][x]=1;
}
void insert()
{

	int x,y;
    char opt;
    
    
    do{
  		 printf("the the vertices that have edge beteen them:");
    	scanf("%d %d",&x,&y);
    	addnode(x,y);
    	
    	printf ("Do you want to add more edges [y/n]:");
    	scanf (" %c", &opt);
    } while(opt == 'y');
    
}

void enqueue(int x)
{
    
     rear = (rear + 1) ;
     queue[rear] = x;
   
}
int dequeue()
{
    int x = queue[front];
    front = (front + 1) ;
    return x;
}
int is_queue_empty()
{
    if (rear<front)
    	return 1;
    return 0;
}
void reset()
{
	for(int i=0;i<g.n;i++)
    {
    	g.visited[i]=0;
    }
}
