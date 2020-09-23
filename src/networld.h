#ifndef NETWORLD_H
#define NETWORLD_H

struct Str_Node {
    double x, y;
};
typedef struct Str_Node Node;

struct Str_NetWorld {
    int size;
    Node * nodes;
};
typedef struct Str_NetWorld NetWorld;

// Constructor / Destructor
NetWorld * NetWorld_new(int aSize);
void NetWorld_delete(NetWorld * aWorld);

// Initialization
void NetWorld_initNodePosition(NetWorld * self, int iNode, double x, double y); // position must be an float[size][2] array...

// To String
void NetWorld_print(NetWorld * self);

#endif //NETWORLD_H