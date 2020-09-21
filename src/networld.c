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
    float x, float y)
{
    self->nodes[iNode].x= x;
    self->nodes[iNode].y= y;
}
