/**
 * A tree is a nonempty collection of vertices and edges that satisfies certain
 * requirements.
 *
 * A vertex is a simple object (also referred to as a node) that can have a
 * name and can carry other associated information.
 *
 * An edge is a connection between two vertices.
 *
 * A path in a tree is a list of distinct vertices in which successive vertices
 * are connected by edges in the tree.
 *
 * The defining property of a tree is that there is precisely one path
 * connecting any two nodes.
 *
 * If there is more than one path between some pair of nodes, or if there is no
 * path between some pair of nodes, then we have a graph.
 *
 * Each node (except the root) has exactly one node above it, which is called
 * its parent; the nodes directly below a node are called its children.
 *
 * An M-ary tree is either an external node or an internal node connected to an
 * ordered sequence of M trees that are also M-ary trees.
 *
 * A tree (also called an ordered tree) is a node (called the root) connected
 * to a sequence of disjoint trees. Such a sequence is called a forest.
 *
 * tree-isomorphism problem
 *
 * A graph is a set of nodes together with a set of edges that connect pairs of
 * distinct nodes (with at most one edge connecting any pair of nodes)
 *
 * A sequence of edges leading from one node to another in this way with no node
 * appearing twice is called a simple path.
 *
 * A graph is connected if there is a simple path connecting any pair of nodes.
 *
 * A path that is simple except that the first and final nodes are the same is
 * called a cycle.
 *
 * Every tree is a graph; which graphs are trees? A graph to be a tree if:
 *  G has N – 1 edges and no cycles.
 *  G has N – 1 edges and is connected.
 *  Exactly one simple path connects each pair of vertices in G.
 *  G is connected, but does not remain connected if any edge is removed.
 *                where N = Number of Nodes
 *
 * Free Tree;
 * Ordered Tree/Unordered Tree;
 *
 **/

#include <iostream>
using namespace std;

struct node {
  int value;
  node *l, *r;
};
// Pointer to nodes as link
typedef struct node *link;

int main(void) {}