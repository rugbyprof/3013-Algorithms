//Dijkstra's implementation based on code from the following web site.
//http://www.koders.com/cpp/fid21D0EBEC7ABAE94815232FFD476C43CB501DAF00.aspx?s=tree

#include<queue>
#include<stack>
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<string>
#include<ctime>

using namespace std;

#define MAXINT (int)(pow(2,30)-1)
#define MAX 100

int **graph;
int total;      
int tedges;       
                 

int distances[MAX];          
int previous[MAX];     
bool visit[MAX]; 

void PrintQueue(priority_queue<pair<int,int> > &Q){
	priority_queue<pair<int,int> > Temp;
	pair<int, int> P;
	while(Q.size()>0){
		P = Q.top();
		Q.pop();
		cout<<P.first<<","<<P.second<<endl;
		Temp.push(P);
	}
	while(Temp.size()>0){
		P = Temp.top();
		Temp.pop();
		Q.push(P);
	}


}


bool make2dArray(int ** &x, int numberOfRows, int numberOfColumns)

{// Create a two dimensional array.
 
   try {
          // create pointers for the rows
          x = new int * [numberOfRows];     

          // get memory for each row
          for (int i = 0; i < numberOfRows; i++)
              x[i] = new int [numberOfColumns];
          return true;
       }
   catch (bad_alloc) {return false;}

}

void PrintArrays(){
	cout<<endl<<"Total:"<<total<<endl;
	int i;
	cout<<" Node D "<<"  P "<<"  V "<<endl;
	cout<<"------------------"<<endl;
	for (i=1; i<=total; i++) {
		if(distances[i]==MAXINT)
			cout<<setw(3)<<(char)(i+64)<<" "<<setw(3)<<(char)(236)<<" "<<setw(3)<<(char)(previous[i]+64)<<" "<<setw(3)<<visit[i]<<endl;
		else
			cout<<setw(3)<<(char)(i+64)<<" "<<setw(3)<<distances[i]<<" "<<setw(3)<<(char)(previous[i]+64)<<" "<<setw(3)<<visit[i]<<endl;
	}
}


//
//http://www.koders.com/cpp/
void dijkstra(int start)
{
  
  priority_queue<pair<int,int> > queue;		//This actually a priority queue ordered by the first integer in the pair
											//which is the weight of the edge
  pair <int,int> nodotmp;					//		
  pair <int,int> temp;						//
  int i, j;									//
  
  //Initializes the three arrays that Dijkstras needs.
  for (i=1; i<=total; i++) {
    distances[i] = MAXINT;					//current distance to each vertex is set to infinity
    previous[i] = -1;						//the previous vertex in the path (father)
    visit[i] = false;						//been visited or not 
  }
 

  distances[start] = 0;						//Set the distance to the source vertex to be zero
  queue.push(pair <int,int> (distances[start], start));//push first edge onto the priority queue

 
  while(!queue.empty()) {
    nodotmp = queue.top();
    queue.pop();
    i = nodotmp.second;
    if (!visit[i]) {
      visit[i] = true;
      for (j = 1; j<=total; j++)
        if (!visit[j] && graph[i][j] > 0 && distances[i] + graph[i][j] < distances[j]) {
          distances[j] = distances[i] + graph[i][j];
          previous[j] = i;
          queue.push(pair <int,int>(distances[j], j));
        }
    }
  }
}


void getPath(int end) {
	stack<int> Path;
	Path.push(end);
	while (previous[end]!= -1) { 
		Path.push(previous[end]);
		end = previous[end];
	}
	while(!Path.empty()){
		cout << (char)(Path.top()+64) << " ";
		Path.pop();
	}
	cout << endl;
}


void RandGraph(){
	int NumVertex=0;
	int MaxEdges=0;
	int NumEdges=0;
	int MaxWeight=0;
	int CurrWeight=0;
	int ConnectTo=0;
	int i,j;

	string line="";

	cout<<"Enter Num Vertexes [20]:";
	getline(cin,line);
	if(line=="")
		NumVertex = 20;
	else
		NumVertex = atoi(line.c_str());

	make2dArray(graph,NumVertex+1,NumVertex+1);
	total=NumVertex;

	for(i=0;i<=NumVertex;i++){
		for(int j=0;j<=NumVertex;j++){
			graph[i][j]=0;
		}
	}

	cout<<"Enter level of connectivity[3]:";
	getline(cin,line);
	if(line=="")
		MaxEdges = 3;
	else
		MaxEdges = atoi(line.c_str());
	cout<<"Enter max weight for edges[1]:";
	getline(cin,line);
	if(line=="")
		MaxWeight = 1;
	else
		MaxWeight = atoi(line.c_str());
	cout<<"Enter seed for rand()[time(0)]:";
	getline(cin,line);
	if(line=="")
		srand(time(0));
	else
		srand(atoi(line.c_str()));

	for(i=1;i<=NumVertex;i++){
		NumEdges = (rand()%MaxEdges)+1;
		cout<<"Numedges;"<<NumEdges<<" "<<MaxEdges<<endl;
		for(int j=0;j<NumEdges;j++){
			CurrWeight = (rand()%MaxWeight)+1;
			ConnectTo = (rand()%NumVertex)+1;
			if(graph[i][ConnectTo]==0 && i != ConnectTo)
				graph[i][ConnectTo]=CurrWeight;
			else
				j--;

		}

	}


}

void PrintAllPairsShortestPath(){
	int a,i,j;

	cout<<endl<<"   ";
	for(a=1; a<=total; a++)
		cout<<setw(2)<<char(a+64);
	cout<<endl;

	for (i=1; i<=total; i++) {
		dijkstra(i);
		cout<<"  "<<char(i+64);
		for(j=1; j<=total; j++) {
			if(distances[j]==MAXINT){
				cout <<setw(2)<<char(236);
			}else{
				cout <<setw(2)<<distances[j];
			}

		}
		cout << endl;
	}
}

int main()
{

	RandGraph();
	int a, b, c,i,j;
	int S;
	int T;


	cout<<setw(3)<<" ";
	for(i=1; i<=total; i++)
		cout<<setw(2)<<char(i+64);
	cout<<endl;
	for(i=1; i<=total; i++) {
		cout<<setw(3)<<char(i+64)<<" ";
		for(j=1; j<=total; j++)
			printf("%d ", graph[i][j]);
		printf("\n");
	}

	//PrintAllPairsShortestPath();
	S = rand()%total+1;
	T = rand()%total+1;

	cout<<"Src:  "<<(char)(S+64)<<endl;
	cout<<"Dest: "<<(char)(T+64)<<endl;
	dijkstra(S);
	getPath(T);
	PrintArrays();

	return 0;
}

