#include "graph.h"

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int graph_exit_code = FINE;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Graph* GraphCtor (int size, node_data_type* nodes_data)
{
    assert (size > 0);

    Graph* graph = (Graph*) calloc (1, sizeof(Graph));
    LinkedListNode** tmp_adj_list = (LinkedListNode**) calloc (size, sizeof(GraphNode*));

    if (graph == NULL or tmp_adj_list == NULL)
    {
        graph_exit_code = MEMORY_ALLOC_ERROR + GRAPH_CTOR_CODE;
        return NULL;
    }

    graph->adjlist = tmp_adj_list;
    graph->size = size;

    for (int i = 0; i < size; i++)
    {
        GraphNode* graph_node = GraphNodeCtor (i + 1, nodes_data[i]);
        LinkedListNode* ll_node = LLNodeCtor (graph_node);

        graph->adjlist[i] = ll_node;
    }

    return graph;
}


//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

GraphNode* GraphNodeCtor (int node_num, node_data_type data)
{   
    GraphNode* node = (GraphNode*) calloc (1, sizeof(GraphNode));

    if (node == NULL)
    {
        graph_exit_code = MEMORY_ALLOC_ERROR + GRAPH_NODE_CTOR_CODE;
        return NULL;
    }

    node->node_num = node_num;
    node->data = data;

    return node;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

LinkedListNode* LLNodeCtor (GraphNode* grpah_node)
{   
    LinkedListNode* ll_node = (LinkedListNode*) calloc (1, sizeof(LinkedListNode));

    if (ll_node == NULL)
    {
        graph_exit_code = MEMORY_ALLOC_ERROR + GRAPH_LL_NODE_CTOR_CODE;
        return NULL;
    }

    ll_node->next = NULL;
    ll_node->prev = NULL;
    ll_node->node = grpah_node;

    return ll_node;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void AddEdge (Graph* graph, int from_node_num, int to_node_num)
{
    assert (graph != NULL);
    assert (from_node_num >= 0 and from_node_num <= graph->size);
    assert (to_node_num >= 0 and to_node_num <= graph->size);
    
    LinkedListNode* from_node = graph->adjlist[from_node_num - 1];
    
    while (from_node->next)
    {
        from_node = from_node->next;
    }

    from_node->next = LLNodeCtor(graph->adjlist[to_node_num - 1]->node);
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void GraphFromFile (Graph* graph, char* filename)
{
    FILE* file = fopen (filename, "r");
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    ssize_t line_size = 0;

    if (file == NULL)
    {
        graph_exit_code = MEMORY_ALLOC_ERROR + GRAPH_LL_NODE_CTOR_CODE;
        return;
    }

    
    while ((line_size = getline (&line_buf, &line_buf_size, file)) > 0)
    {   
        int from_node_num = atoi (strtok (line_buf, " "));
        char* to_node_str;

        while ((to_node_str = strtok (NULL, " ")) != NULL)
        {   
            int to_node_num = atoi (to_node_str);
            AddEdge(graph, from_node_num, to_node_num);
        }
    }

    free(line_buf);
    fclose(file);
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void GraphToDotFile (Graph* graph, char* filename)
{   
    FILE* file = fopen (filename, "w");

    if (file == NULL)
    {
        graph_exit_code = MEMORY_ALLOC_ERROR + GRAPH_LL_NODE_CTOR_CODE;
        return;
    }

    fprintf (file, "digraph\n{\n");

    for(int i = 0; i < graph->size; i++)
    {   
        LinkedListNode* ll_node = graph->adjlist[i];
        fprintf  (file, "\"Num: %d\nData: %d\" -> {", ll_node->node->node_num, ll_node->node->data);
        while(ll_node->next != NULL)
        {   
            ll_node = ll_node->next;
            fprintf (file, "\"Num: %d\nData: %d\" ", ll_node->node->node_num, ll_node->node->data);
        }

        fprintf(file, "};\n");
    }

    fprintf (file, "}");

    fclose(file);
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int GraphDumpFunction(Graph* graph, const char* func_name, int line_number, const char* file_name, const char *graph_name)
{      
    int err_code = graph_exit_code / 256 * 256;
    int check = (err_code == FINE);

    if (check)
    {
        printf ("\n\nGraph[OK]: ");
    }

    else
    {
        printf ("\n\nGraph[ERROR][CODE: 0x%X]", graph_exit_code);
    }

    printf ("[%p] ", &graph->adjlist);

    printf ("\"%s\" %s line %d %s'\n", graph_name, func_name, line_number, file_name);

    if(!check)
        GraphPrintExitCode();

    printf ("\n{\n");              
                                                
    printf (" size = %d \n", graph->size);                 
                                                    
    printf ("\t{\n"); 

    
    for(int i = 0; i < graph->size; i++)
    {   
        LinkedListNode* ll_node = graph->adjlist[i];
        printf  ("\t\t[%d]", ll_node->node->node_num);
        while(ll_node->next != NULL)
        {   
            ll_node = ll_node->next;
            printf (" -> %d", ll_node->node->node_num);
        }

        printf("\n");
    }

    printf ("\t}\n}\n"); 
    
    return 0;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void GraphPrintExitCode ()
{   
    int func_code = graph_exit_code % 256;
    int err_code = graph_exit_code / 256 * 256;
    
    if (err_code == FINE)
    {
        printf ("No errors found\n");
        return;
    }

    switch (err_code)
    {
        case MEMORY_ALLOC_ERROR:
            printf ("Memory allocation error in ");
            break;

        default:
            printf ("Unkwonw exception with number %X in ", err_code);
            break;
    }


    switch (func_code)
    {
        case GRAPH_CTOR_CODE:
            printf ("func GraphCtor()\n");
            break;

        case GRAPH_NODE_CTOR_CODE:
            printf ("func GraphNodeCtor()\n");
            break;

        case GRAPH_LL_NODE_CTOR_CODE:
            printf ("func LLNodeCtor()\n");
            break;

        case GRAPH_ADD_EDGE_CODE:
            printf ("func AddEdge()\n");
            break;

        case GRAPH_FROM_FILE_CODE:
            printf ("func GraphFromFile()\n");
            break;

        case GRAPH_TO_FILE_CODE:
            printf ("func GraphToDotFile()\n");
            break;

        case GRAPH_UNIT_TEST_CODE:
            printf ("func UnitTest()\n");
            break;

        case GRAPH_DUMP_CODE:
            printf ("macro GraphDump()\n");
            break;

        default:
            printf ("unkwonw func with number %X\n", func_code);
            break;
    }

    return;
}

void DrawGraph(Graph* graph, char* filename)
{   
    GraphToDotFile(graph, filename);

    char* command = "dot -Tpng -O ";
    char* result_command = malloc(strlen(command) + strlen(filename) + 1);
    strcpy(result_command, command);
    strcat(result_command, filename);
    system(result_command);

}

void UnitTest ()
{   
    const int graph1_size = 12;
    const int graph2_size = 5;
    node_data_type data1[graph1_size];
    node_data_type data2[graph2_size];
    Graph* graph1 = GraphCtor(graph1_size, data1);
    Graph* graph2 = GraphCtor(graph2_size, data2);
    
    GraphFromFile(graph1, "graph_test_file.txt");

    AddEdge(graph2, 1, 2);
    AddEdge(graph2, 2, 3);
    AddEdge(graph2, 3, 4);
    AddEdge(graph2, 4, 5);
    AddEdge(graph2, 5, 1);

    GraphDump(graph1);
    GraphDump(graph2);
    DrawGraph(graph1, "result_grpah1.dot");
    DrawGraph(graph2, "result_grpah2.dot");

}