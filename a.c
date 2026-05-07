#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next
};

struct graph
{
    int V; // number of vertices
    struct Node **arr;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct graph *creategraph()
{
    int V;
    struct graph *gp = malloc(sizeof(struct graph));

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    gp->arr = calloc(V, sizeof(struct Node *));
    gp->V = V;

    return gp;
}

void add_an_edge(struct graph *gp)
{
    int v1, v2;

    printf("Enter 1st and 2nd vertices: ");
    scanf("%d %d", &v1, &v2);

    //edge v1-> v2
    struct Node *newNode = createNode(v2);
    newNode->next = gp->arr[v1];
    gp->arr[v1] = newNode;

    struct Node *newNode2 = createNode(v1);
    newNode2->next = gp->arr[v2];
    gp->arr[v2] = newNode2;
}

void show_the_graph(struct graph *gp)
{
    int i;

    for (i = 0; i < gp->V; i++)
    {
        printf("|%d |", i);

        struct Node *cr = gp->arr[i];
        while (cr)
        {
            printf("%d -> ", cr->data);
            cr = cr->next;
        }
        printf("\n\n");
    }
}

int main()
{
    int inp;
    struct Graph *gp = NULL;

    while (1)
    {
        printf("\n\n Press 1 to create a new graph\n2 to add an edge\n3 to show the graph:");
        scanf("%d", &inp);

        switch (inp)
        {
        case 1:
            gp = creategraph();
            break;
        case 2:
            if (gp)
            {
                add_an_edge(gp);
            }
            else
            {
                printf("Graph not created yet.\n");
            }
            break;
        case 3:
            if (gp)
            {
                show_the_graph(gp);
            }
            else
            {
                printf("Graph not created yet.\n");
            }
            break;
        default:
            exit(0);
        }
    }
    return 0;
}