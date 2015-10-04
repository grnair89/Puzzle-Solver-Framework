/**
 *
 *  lloyd.cpp
 *  
 *  Version: lloyd.cpp v 1.0  2014/04/12 04.12 PM
 *  
 *  @author: 
 *         	        an3395(Arjun Nair)
 *		   	sxo4955(Shivankar Ojha)
 *			gr4075(Ganesh Rajasekharan)
 *
 *  Revisions:  
 *         Initial Revision.
 *        
 *  $Log$ 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
using namespace std;


vector<string> goal;
map<vector<string> , vector<string> > tree;
stack< vector<string> > stack_Of_Vectors;
vector<string> initial_Config;
vector<string> store;

int stringsize;

vector<string> finder(map< vector<string> , vector<string> > Display_Tree , vector<string> child);
bool get_Goal_Config(vector<string> Config);

vector< vector<string> > find_config( vector<string> v);
void Display(map< vector<string> , vector<string> > Display_Tree);
void goal_solver();
vector<string> swap_up(vector<string> v1, int vp , int sp);
vector<string> swap_down(vector<string> v2, int vp , int sp);
vector<string> swap_right(vector<string> v3, int vp , int sp);
vector<string> swap_left(vector<string> v4, int vp , int sp);

bool get_Goal_Config(vector<string> Config){
	/**
 * This function returns the goal configuration
 *
 *  @param   vector<string> Config		Current configuration of the panels on the puzzle
 *  
 */

		 for (int i = 0; i < Config.size(); ++i)
		{
			if (Config[i]!=(goal[i]))
			{	
				return false;
			}
		}
		return true;
}

vector<string> swap_down(vector<string> v1, int vp , int sp){
	/**
 * This function is responsible for moving a particular panel downward and 
 *  exhanging it position with the downward panel; and then returning the resultant configuration. 
 *
 *  @param   vector<string> v1		Current configuration of the panels on the puzzle
 *  @param   int vp                 represents the vector point. 
 *  @param   int sp                 represents the string point. These two basically represent the position of the panel. 
 */
	
	if (vp>0)
	{
		char temp = v1[vp][sp];
		v1[vp][sp] = v1[vp-1][sp];
		v1[vp-1][sp] = temp;
	}
	return v1;
}

vector<string> swap_up(vector<string> v2, int vp , int sp){
	/**
 * This function is responsible for moving a particular panel upward and 
 *  exhanging it position with the upward panel; and then returning the resultant configuration. 
 *
 *  @param   vector<string> v2		Current configuration of the panels on the puzzle
 *  @param   int vp                 represents the vector point. 
 *  @param   int sp                 represents the string point. These two basically represent the position of the panel. 
 */
	if (vp < (v2.size()-1))
	{
		char temp = v2[vp][sp];
		v2[vp][sp] = v2[vp+1][sp];
		v2[vp+1][sp] = temp;
	}
	return v2;
}

vector<string> swap_right(vector<string> v3, int vp , int sp){
	/**
 * This function is responsible for moving a particular panel rightward and 
 *  exhanging it position with the leftward panel; and then returning the resultant configuration. 
 *
 *  @param   vector<string> v3  	Current configuration of the panels on the puzzle
 *  @param   int vp                 represents the vector point. 
 *  @param   int sp                 represents the string point. These two basically represent the position of the panel. 
 */

	if (sp < stringsize)
	{
		char temp = v3[vp][sp];
		v3[vp][sp] = v3[vp][sp+1];
		v3[vp][sp+1] = temp;
	}
	return v3;
}

vector<string> swap_left(vector<string> v4, int vp , int sp){
	/**
 * This function is responsible for moving a particular panel leftward and 
 *  exhanging it position with the rightward panel; and then returning the resultant configuration. 
 *
 *  @param   vector<string> v4		Current configuration of the panels on the puzzle
 *  @param   int vp                 represents the vector point. 
 *  @param   int sp                 represents the string point. These two basically represent the position of the panel. 
 */
	if (sp < stringsize)
	{
		char temp = v4[vp][sp];
		v4[vp][sp] = v4[vp][sp-1];
		v4[vp][sp-1] = temp;
	}
	return v4;
}
vector< vector<string> > find_config( vector<string> v){
	/**
 * This function is responsible for moving a for finding the next configuration 
 * by making all possible moves ; and then returning the resultant configuration. 
 *
 *  @param   vector<string> v	Current configuration of the panels on the puzzle
 *
 */
	vector< vector<string> > get_vector;
	int vector_position = -1;
	int string_position = -1;

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j]=='.')
			{
				vector_position=i;
				string_position=j;	
				vector<string> v_new = v;

				get_vector.push_back(swap_up(v_new,vector_position,string_position));
				 
				get_vector.push_back(swap_down(v_new,vector_position,string_position));
				
				get_vector.push_back(swap_right(v_new,vector_position,string_position));

				get_vector.push_back(swap_left(v_new,vector_position,string_position));

			}
		}
	}

	return get_vector;
}
void Display(map< vector<string> , vector<string> > Display_Tree){
	int count=0;
	vector< string > child = stack_Of_Vectors.top();
	while(stack_Of_Vectors.top()!=initial_Config){
		stack_Of_Vectors.push(finder(Display_Tree, child));
		child=stack_Of_Vectors.top();
	}

	cout<<"The Final Solution is:\n"<<endl;
	while(!stack_Of_Vectors.empty()){
		child=stack_Of_Vectors.top();
		for (int i = 0; i < child.size(); ++i)
		{
			cout<<child[i]<<endl;
		}
		cout<<"\n/************************/\n";
		cout<<endl;
		stack_Of_Vectors.pop();
	}
}
void Display_file(map< vector<string> , vector<string> > Display_Tree, string filename){
	/**
 * This function is responsible for displaying the 
 *  @param   vector<string> v1		Current configuration of the panels on the puzzle
 *  @param   int vp                 represents the vector point. 
 *  @param   int sp                 represents the string point. These two basically represent the position of the panel. 
 */
	int count=0;
	vector< string > child = stack_Of_Vectors.top();
	while(stack_Of_Vectors.top()!=initial_Config){
		stack_Of_Vectors.push(finder(Display_Tree, child));
		child=stack_Of_Vectors.top();
	}
   ofstream myfile;
   
   myfile.open (filename.c_str());
  	cout<<"The Final Solution is displayed in the file"<<endl;
	while(!stack_Of_Vectors.empty()){
		child=stack_Of_Vectors.top();
		for (int i = 0; i < child.size(); ++i)
		{
			
			myfile << child[i]<<endl;

		}
		myfile <<"\n/************************/\n";
		stack_Of_Vectors.pop();
	}
	myfile.close();
}




vector<string> finder(map< vector<string> , vector<string> > Display_Tree , vector<string> child){
	vector<string> v;
	for (map< vector<string> , vector<string> >::iterator it = Display_Tree.begin(); it!=Display_Tree.end(); ++it)
	{
		if (it->first == child)
		{
			v = it->second;
			return v; 
		}
	}
	return child;
}

void Display_map(map< vector<string> , vector<string> > Display_Tree){

	/**
 * This function displays the map which contains the tree like structure of configurations in the form of 
 * child value pairs. 
 *
 *  @param   vector<string> Display_tree 		  represents a particular configuration of buckets. 
 *  @param   map< vector<string>	              This map consists of the tree like structure of configurations
 * 
 */

	for (map< vector<string> , vector<string> >::iterator it = Display_Tree.begin(); it!=Display_Tree.end(); ++it){
		for(int j=0;j<initial_Config.size();j++)
		cout<< it->first.at(j)<<" "<< "=>" << it->second.at(j)<<" "<<endl;
		cout<<"\n/**********************************************/\n";
		cout<<endl;
	}
}

void goal_solver(){

	/**
 * This function is where each configuration is taken and pushed onto a queue from where we try and find out the solution by 
 * seeing if the goal is in one of the buckets. The function terminates and displays the solution when it is found. 
 *
 
 */
	queue < vector<string> > queue_Of_Vectors;
	vector< vector<string> > new_Config;
	tree[initial_Config] = initial_Config;
	queue_Of_Vectors.push(initial_Config);
	while(!get_Goal_Config(queue_Of_Vectors.front()) && !queue_Of_Vectors.empty()){
		new_Config = find_config(queue_Of_Vectors.front());

		for (int i = 0; i < new_Config.size(); ++i)
		{
			if(tree.find(new_Config[i])==tree.end()){		
				queue_Of_Vectors.push(new_Config[i]);
				tree[new_Config[i]]=queue_Of_Vectors.front();

			}
		}
		queue_Of_Vectors.pop();
		if (get_Goal_Config(queue_Of_Vectors.front()))
		{
			stack_Of_Vectors.push(queue_Of_Vectors.front());
			break;
		}
	}

	Display_map(tree);
}
int main(int argc, char *argv[]) {
	//filename=argv[2];
if (argc != 3) {
		cerr << "Incorrect number of arguments." << endl;
		return -1;
	}

	istream *isp;
	ifstream ifs;
	ostream *osp;
	ofstream ofs;

	if (argv[1][0] == '-' && argv[1][1] == '\0') {
		isp = &cin;
	} else {
		ifs.open(argv[1]);
		isp = &ifs;
	}
	istream &is = *isp;

	if (argv[2][0] == '-' && argv[2][1] == '\0') {
		osp = &cout;
	} else {
		ofs.open(argv[2]);
		osp = &ofs;
	}

	ostream &os = *osp;

	string line;
int counter=0;
int flag1=0;
int flag2=0;
	
int width, height;
 is >> height >> width;
	stringsize=width;
counter=1;

 
for( std::string line; getline( is, line ); )
{
	
	 if (line=="\0"){
	 	flag1++;
	 	counter++;
	 }
	 	
	 if (flag1==1){

	 	store.push_back(line);
		counter++;
	}

flag2++;
if (flag2==(2*height)+1)
break;

	
}
int j=0;
int counting_initial=1;
for(j=1;j<store.size();j++)
{
	if (counting_initial<=height){
counting_initial++;

	initial_Config.push_back(store[j]);
}
else{
	goal.push_back(store[j]);
counting_initial++;
}

}
 
goal_solver();
string filename = argv[2];
if (filename.compare("-")>0 || filename.compare("-")<0)
{
	Display_file(tree,filename);
}
else {
	Display(tree);
}

}
