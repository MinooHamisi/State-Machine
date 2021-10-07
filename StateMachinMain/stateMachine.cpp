#include "stateMachine.h"

stateMachine::stateMachine(vector<edge> E, int N, vector<int> sf)
{
	Nodes.resize(N); // 1-decrease amont of memory which complier will asign to Nodes
	                 // 2-access to each element like an array
	for (int i = 0;i < E.size();i++)
		Nodes[E[i].src].push_back({ E[i].dest, E[i].weight });
	startOrFinish = sf;
}
//-------------------------------------------------------------
void stateMachine::print()
{
	for (int i = 0;i < this->Nodes.size();i++)
	{
		cout << i << "is a ";
		switch (startOrFinish[i])
		{case 1:
			cout << "start node -> ";
			break;
		case 2:
			cout << "finish node -> ";
			break;
		case 3:
			cout << "start and finish node -> ";
			break;
		case 4:
			cout << "middle node -> ";
			break;
		}
		for (int j = 0;j < this->Nodes[i].size();j++)
		{
			cout << this->Nodes[i][j].a[0] << "," << Nodes[i][j].a[1] << " ";
		}
		cout << "\n";
	}
}
//-------------------------------------------------------------
bool stateMachine::findConnection(int s, int d)
{
	int i;
	for (i = 0;i < this->Nodes[s].size();i++)
		if (this->Nodes[s][i].a[0] == d)
			return true;
	for (i = 0;i < this->Nodes[d].size();i++)
		if (this->Nodes[d][i].a[0] == s)
			return true;
	return false;
}
//-------------------------------------------------------------
bool stateMachine::findRelationship(int s, int d)
{
	
	if (findConnection(s, d))
		return true;
	else
	{
		int i, j;
		for (i = 0;i < this->Nodes[s].size();i++)
		{
			if (findConnection(this->Nodes[s][i].a[0], d))
				return true;
		}
		for (i = 0;i < this->Nodes[d].size();i++)
		{
			if (findConnection(this->Nodes[d][i].a[0], s))
				return true;
		}
	}
	return false;
}
//-------------------------------------------------------------