#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#define or  ||
#define and &&
#define GraphDump(grpah) GraphDumpFunction (grpah, __PRETTY_FUNCTION__, __LINE__, __FILE__, #grpah);

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

typedef int node_data_type;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

extern int graph_exit_code;
//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

typedef struct GraphNode
{
    int node_num;
    int is_discovered;
    node_data_type data;
} GraphNode;

typedef struct LinkedListNode
{
    GraphNode* node;
    struct LinkedListNode* prev;
    struct LinkedListNode* next;  
} LinkedListNode;

typedef struct Graph
{   
    int size;
    LinkedListNode** adjlist
} Graph;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

enum GraphExitCodes
{
    GRAPH_FINE                        = 0x001000,     //  If all is OK
    GRAPH_MEMORY_ALLOC_ERROR          = 0x002000,     //  Error while allocation memory in functions calloc/realloc
    GRAPH_FILEOPEN_ERROR              = 0x003000,     //  Error with file opening
};

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

enum GraphFunctionNumbers
{
    GRAPH_CTOR_CODE = 1,         // Code of GraphCtor()
    GRAPH_NODE_CTOR_CODE = 2,    // Code of GraphNodeCtor()   
    GRAPH_LL_NODE_CTOR_CODE = 3, // Code of LLNodeCtor()   
    GRAPH_ADD_EDGE_CODE = 4,     // Code of AddEdge()
    GRAPH_FROM_FILE_CODE = 5,    // Code of GraphFromFile()
    GRAPH_TO_FILE_CODE = 6,      // Code of GraphToDotFile()
    GRAPH_UNIT_TEST_CODE = 7,    // Code of UnitTest()
    GRAPH_DUMP_CODE = 8,         // Code of GraphDumpFunction()
};

Graph* GraphCtor (int, node_data_type*);
GraphNode* GraphNodeCtor (int, node_data_type);
LinkedListNode* LLNodeCtor(GraphNode*);
void AddEdge (Graph*, int, int);
void GraphFromFile (Graph*, char*);
void GraphUnitTest ();
void GraphToDotFile (Graph*, char*);
int GraphDumpFunction(Graph*, const char*, int, const char*, const char*);
void GraphPrintExitCode ();
void DrawGraph(Graph*, char*);
