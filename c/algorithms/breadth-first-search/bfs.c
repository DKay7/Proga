#include "bfs.h"


GraphNode* BreadthFirstSearch (Graph* graph, node_data_type target_data)
{
    Queue* queue = QueueCtor ();
    GraphNode* return_node;
    int discovered_index = 0;
    QueuePush (queue, graph->adjlist[0]->node->node_num - 1);

    while (queue->size > 0)
    {
        int current_ll_node_num = QueuePop (queue);
        LinkedListNode* current_ll_node = graph->adjlist[current_ll_node_num];
        
        //printf("\n\nCUR LL NOD NUM [%p] NXT [%p]\n", current_ll_node, current_ll_node->next);
        // printf("\n\nCUR G NOD NUM [%d] DIS [%d]\n", current_graph_node->node_num, current_graph_node->is_discovered);

        while (current_ll_node != NULL)
        {   
            if (current_ll_node->node->is_discovered == -1)
            {   

                if (current_ll_node->node->data == target_data)
                {
                    return_node = current_ll_node->node; 
                }

                current_ll_node->node->is_discovered = discovered_index;
                discovered_index += 1;
                QueuePush (queue, current_ll_node->node->node_num - 1);
                // printf("\nAPD [%d] \n", current_ll_node->node->node_num);
            }

            current_ll_node = current_ll_node->next;
        }

    }

    return return_node;


}

int BFSUnitTest (const int graph_size, char* input_file, char* output_file1, char* output_file2)
{
    node_data_type data[graph_size];

    for (int i = 0; i < graph_size; i++)
    {
        data[i] = 6969 - 42 * i;
    }

    Graph* graph = GraphCtor (graph_size, data);
    
    GraphFromFile (graph, input_file);

    GraphDump (graph);
    DrawGraph (graph, output_file1);

    GraphNode* result_node = BreadthFirstSearch(graph, 6507);

    printf ("\n\n\nAFTER BFS\n");
    printf("[result node num %d] data: [%d]", result_node->node_num, result_node->data);
    GraphDump (graph);
    DrawGraph (graph,  output_file2);

    return 0;
}