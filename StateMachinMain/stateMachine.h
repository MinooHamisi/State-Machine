#include <iostream>
#include<vector>
using namespace std;

struct edge
{
	int src, dest, weight;
};
struct int2
{
	int a[2]; //  d=dest,w=weight
};
//------------------Weighted Graph-----------------------
class stateMachine
{
private:
	vector<vector<int2>> Nodes;
	vector<int> startOrFinish; //=1 :start node, =2 :finish node, =3 :start and finish node, =4 :it is not a start node or finish node 
public:

	stateMachine(vector<edge> E, int N, vector<int> sf);
	void print();
	bool findConnection(int s, int d);
	bool findRelationship(int s, int d);
};