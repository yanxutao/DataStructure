
#define TRUE 1
#define FALSE 0

/* 图的邻接矩阵表示法（C语言实现） */
#define MaxVertexNum 100
#define INFINITY 65535
typedef char VertexType;
typedef int EdgeType;
enum GraphType { DG, UG, DN, UN };
/* 有向图,无向图,有向网图,无向网图*/
  
typedef struct {
    VertexType Vertices[MaxVertexNum];
    EdgeType Edges[MaxVertexNum][MaxVertexNum];
    int n, e;
    enum GraphType GType;
} MGraph;
  
void CreateMGraph(MGraph *G)
{  
    int i, j, k, w;
    G->GType = UN;
    printf("请输入顶点数和边数(输入格式为:顶点数, 边数):\n");
    scanf("%d, %d",&(G->n), &(G->e));
    printf("请输入顶点信息(输入格式为:顶点号<CR>):\n");
    for (i = 0; i < G->n; i++) 
       scanf("%c", &(G->Vertices[i]));
    for (i = 0; i < G->n; i++)
       for (j = 0; j < G->n; j++)  
           G->Edges[i][j] = INFINITY;
    printf("请输入每条边对应的两个顶点的序号和权值，输入格式为: i, j, w:\n");
    for (k = 0; k < G->e; k++) {
       scanf("%d,%d,%d ",&i, &j, &w);
       G->Edges[i][j] = w; 
       G->Edges[j][i] = w;
    }
}


/* 图的邻接表表示法（C语言实现） */
#define MaxVertexNum 100
enum GraphType { DG, UG, DN, UN }; 
typedef struct node {
    int AdjV;
    struct node *Next;
    /* 若要表示边上的权值信息，则应增加一个数据域Weight */
} EdgeNode;
typedef char VertexType;
typedef struct Vnode {
    VertexType Vertex;
    EdgeNode *FirstEdge;
} VertexNode;
typedef VertexNode AdjList[MaxVertexNum];
typedef struct {  
    AdjList adjlist;
    int n, e;
    enum GraphType GType;
} ALGraph;
  
void CreateALGraph(ALGraph *G)
{
    int i, j, k;
    EdgeNode *edge;
    G->GType = DG;
    printf("请输入顶点数和边数(输入格式为:顶点数,边数)：\n");
    scanf("%d,%d", &(G->n), &(G->e) );
    printf("请输入顶点信息(输入格式为:顶点号<CR>)：\n");
    for (i = 0; i < G->n; i++) {
        scanf("%c", &(G->adjlist[i].Vertex));
        G->adjlist[i].FirstEdge = NULL;
    }
    printf("请输入边的信息(输入格式为: i, j <CR>)：\n");
    for (k = 0; k < G->e; k++){
       scanf("%d, %d", &i, &j);
       edge = (EdgeNode *)malloc(sizeof(EdgeNode));
       edge->AdjV = j;
       edge->Next = G->adjlist[i].FirstEdge;
       G->adjlist[i].FirstEdge = edge;
       /* 若是无向图，还要生成一个结点，用来表示边< vj, vi>  */
    }
}



/* 邻接表存储的图 – DFS（C语言实现） */
/* Visited[]为全局变量，已经初始化为FALSE */
/* 以Vi为出发点对邻接表存储的图G进行DFS搜索 */
void DFS(ALGraph *G, int i)
{
    printf("visit vertex: %c\n", G->adjlist[i].Vertex);
    Visited[i] = TRUE;
    EdgeNode *W;
    for (W = G->adjlist[i].FirstEdge; W; W = W->Next)
        if (!Visited[W->AdjV])
           DFS(G, W->AdjV);
}


/* 邻接矩阵存储的图 – BFS（C语言实现） */
/* 按广度优先遍历图G。使用辅助队列Q和访问标志数组Visited */
void BFS(MGraph G)
{   
    VertexType U, V, W;
    for (U = 0; U < G.n; ++U)  
        Visited[U] = FALSE;
    Queue *Q = CreatQueue(MaxSize);
    for (U = 0; U<G.n; ++U)
        if (!Visited[U]) {
            Visited[U] = TRUE; 
            printf("visit vertex: %c\n", G.Vertices[U]);
            AddQ(Q, U);
            while (!IsEmptyQ(Q)) {
                V = DeleteQ(Q);
                for(W = FirstAdjV(G, V);  W;  W = NextAdjV(G, V, W))
                    if (!Visited[W]) {
                        Visited[W] = TRUE;
                        printf( "visit vertex: %c\n", G.Vertices[W] );
                        AddQ (Q, W);
                    }
           }
        }
}
/* FirstAdjV(G, V)和NextAdjV(G, V, W)请自己练习实现。*/