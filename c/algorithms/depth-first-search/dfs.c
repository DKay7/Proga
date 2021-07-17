#include "dfs.h"


void RecursiveDepthFirstSearch (Graph* graph, int graph_node_num, int* discovery_index)
{
    LinkedListNode* ll_node = graph->adjlist[graph_node_num - 1];
    
    ll_node->node->is_discovered = *discovery_index;

    while (ll_node != NULL)
    {   

        if (ll_node->node->is_discovered == -1)
        {   
            *discovery_index += 1;
            RecursiveDepthFirstSearch (graph,  ll_node->node->node_num, discovery_index);
        }

        ll_node = ll_node->next;
    }

}

void StackDepthFirstSearch (Graph* graph)
{   
    int discovery_index = 0;
    LinkedListNode* ll_node = graph->adjlist[0];
    Stack* stack = StackCtor (2 * (graph->size + 1));
    StackPush (stack, ll_node->node->node_num);

    while (stack->pointer > 0)
    {   
        StackDump(stack);
        int node_num = StackPop (stack);
        LinkedListNode* ll_node = graph->adjlist[node_num - 1];

        if (ll_node->node->is_discovered == -1)
        {   
            ll_node->node->is_discovered = discovery_index;
            discovery_index += 1;

            while (ll_node->next != NULL)
            {   
                ll_node = ll_node->next;
                StackPush (stack, ll_node->node->node_num);
            }
        }

    }

}

int DFSUnitTest (const int graph_size, char* input_file, char* output_file1, char* output_file2)
{
    node_data_type data[graph_size];

    for (int i = 0; i < graph_size; i++)
    {
        data[i] = 424242 - 69 * i;
    }

    Graph* graphR = GraphCtor (graph_size, data);
    Graph* graphS = GraphCtor (graph_size, data);

    GraphFromFile (graphR, input_file);
    GraphFromFile (graphS, input_file);

    printf ("\n\n\nBEFORE DFS\n\n");
    GraphDump (graphS);

    int recursive_discovery_idx = 0;
    RecursiveDepthFirstSearch(graphR, 1, &recursive_discovery_idx);
    StackDepthFirstSearch(graphS);

    printf ("\n\n\nAFTER DFS (STACK + RECURSIVE)\n");

    GraphDump (graphS);
    GraphDump (graphR);
    DrawGraph (graphS, output_file1);
    DrawGraph (graphR,  output_file2);

    return 0;
}