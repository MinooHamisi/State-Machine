
#include <iostream>
#include <vector>
#include "stateMachine.h"
using namespace std;

int main()
{
    vector<edge> E;
    edge e;
    int n, i = 0;
    vector<int> sf;
    cout << "you will be asked about specifications of the nodes if you have nothing, enter a NEGATIVE number:\n";
    cout << "enter your source node:\n";
    cin >> n;
    while (n >= 0)
    {
        e.src = n;
        int s;
        if (i < n)
            i = n;
        cout << "enter the dest:\n";
        cin >> e.dest;
        if (i < e.dest)
            i = e.dest;
        cout << "enter the weight:\n";
        cin >> e.weight;
        E.push_back(e);
        cout << "enter the next sorce:\n";
        cin >> n;
    }
    if (i >= 0)
    {
        //---------------value sf
        cout << "be ready to determine each node situation:\n";
        cout << "if your node is a start Node enter 1\n"; //(1,0)
        cout << "if it is a finish Node enter 2\n";//(0,1)
        cout << "if it is a finishand and start Node enter 3\n";//(1,1)
        cout << "if it is not a finish or start Node enter 4\n ";//(0,0)
        n = 0;
        i = i++;
        sf.resize(i);
        int s;
        while (n < i )
        {
            cout << "node " << n << ":\n";
            cin >> s;
            if(s==1 || s==2 || s==3 || s==4)
                sf[n] = s;
            else
            {
                cout << "enter a valid number!(1 or 2 or 3 or 4)\n";
                n--;
            }
            n++;
        }
        //---------------end value sf
        stateMachine STM(E, i , sf);
        STM.print();

        cout << "enter 2 nodes and check wheter there is a connection between them or not:\n";
        cin >> n >> i;
        if (STM.findConnection(n, i))
            cout << "YES! there is an edge between them.\n";
        else
            if (STM.findRelationship(n, i))
                cout << "there isn't any edges between them, BUT there is a relationship between them.\n";
            else
                cout << "NO! there isn't any edges and relationships between them!\n";
    }
    return 0;
}