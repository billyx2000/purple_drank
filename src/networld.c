#include "networld.h"
#include <stdio.h>
#include <stdlib.h>

// Constructor / Destructor
NetWorld * NetWorld_new(int size)
{
    NetWorld * p = malloc( sizeof(NetWorld) );
    p->size= size;
    p->nodes= malloc( p->size * sizeof(Node) );
    return p;
}

void NetWorld_delete(NetWorld * self)
{
    free( self->nodes );
    free( self );
}

// Initialization
void NetWorld_initNodePosition(
    NetWorld * self, int iNode,
    double x, double y)
{
    self->nodes[iNode].x= x;
    self->nodes[iNode].y= y;
}

// To String
void NetWorld_print(NetWorld * self)
{
    for(int i= 0 ; i < self->size ; ++i )
        printf("[%lf, %lf]\n", self->nodes[i].x, self->nodes[i].y);
}
