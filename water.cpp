/**
 *
 *  Water.cpp
 *  
 *  Version: Water.cpp v 1.0  2014/01/12 10.20 AM
 *  
 *  @authors: 
 *         	an3395(Arjun Nair)
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
#include <sstream>
#include <string>
using namespace std;

int goal;
vector<int> bucket_Weight;
map<vector<int> , vector<int> > tree;
stack< vector<int> > stack_Of_Vectors;
vector<int> initial_Config;

vector<int> finder(map< vector<int> , vector<int> > Display_Tree , vector<int> child);
bool get_goal_config(vector<int> Config);
vector<int> empty_bucket(vector<int> bucket , int i );
vector<int> fill_bucket(vector<int> bucket , int i );
vector<int> transfer_bucket(vector<int> bucket , int from , int to);
vector< vector<int> > find_config( vector<int> v);
void Display(map< vector<int> , vector<int> > Display_Tree);
void goal_solver();

bool get_goal_config(vector<int> Config){
	
/**
 * This function returns the boolean value true if the goal has been found. 
 *
 *  @param   vector<int> Config		Configuration of the buckets
 *  
 */


	for (int i = 0; i < Config.size(); ++i)
	{
		if (Config[i]==goal)
		{
			return true;
		}
	}
	return false;
}


vector<int> empty_bucket(vector<int> bucket , int i ){

/**
 * This function is concerned with emptying the bucket number i passed to it as a 
 * part of a configuration of the buckets in the form of a vector. 
 *
 *  @param   vector<int> bucket 		represents a particular configuration of buckets. 
 *  @param   int i 	                    The bucket number which is to be emptied in the current configuration. 
 */
	bucket[i]=0;
	return bucket;
}

vector<int> fill_bucket(vector<int> bucket , int i ){
	/**
 * This function is concerned with filling the bucket number i passed to it as a 
 * part of a configuration of the buckets in the form of a vector. 
 *
 *  @param   vector<int> bucket 		represents a particular configuration of buckets. 
 *  @param   int i 	                    The bucket number which is to be filled in the current configuration. 
 */
	bucket[i]=bucket_Weight[i];
	return bucket;
}

vector<int> transfer_bucket(vector<int> bucket , int from , int to){
	/**
 * This function is concerned with transferring water from bucket number "from" to the bucket number "to"  
 * which are part of a configuration of the buckets passed in the form of a vector. 
 *
 *  @param   vector<int> bucket 		 represents a particular configuration of buckets. 
 *  @param   int from	                 The bucket number from which water  is to be transferred.
 *  @param   int to	                     The bucket number to which water  is to be transferred.
 */
	int transfering = bucket_Weight[to] - bucket[to];
    int minimum;
    if (transfering<bucket[from])
       {
            bucket[from] = bucket[from]-transfering;
            bucket[to] = bucket[to]+transfering;
        }
    else{
    		bucket[to] = bucket[to] + bucket[from];
            bucket[from] = bucket[from] - bucket[from];
        }
        return bucket;
}

vector< vector<int> > find_config( vector<int> v){

	/**
 * This function is concerned with finding all possible configurations possible from the configuration
 * which is passed to it as a vector. 
 *
 *  @param   vector<int> bucket 		 represents a particular configuration of buckets. 
*/
	vector< vector<int> > get_vector;
	
	for(int i=0;i<v.size();i++){
		get_vector.push_back(empty_bucket(v,i));
	}

	for(int i=0;i<v.size();i++){
		get_vector.push_back(fill_bucket(v,i));
	}

	for (int from = 0; from < v.size(); ++from)
	{
		for (int to = 0; to < v.size(); ++to)
		{
			get_vector.push_back(transfer_bucket(v,from,to));
		}
	}
	return get_vector;
}

void Display(map< vector<int> , vector<int> > Display_Tree){
	int count=0;
	vector< int > child = stack_Of_Vectors.top();
	while(stack_Of_Vectors.top()!=initial_Config){
		stack_Of_Vectors.push(finder(Display_Tree, child));
		child=stack_Of_Vectors.top();
	}
	cout<<"The Final Solution is:\n"<<endl;
	while(!stack_Of_Vectors.empty()){
		child=stack_Of_Vectors.top();
		for (int i = 0; i < child.size(); ++i)
		{
			cout<<child.at(i)<<" ";
		}
		cout<<"\n/************************/\n";
		cout<<endl;
		stack_Of_Vectors.pop();
	}
}

vector<int> finder(map< vector<int> , vector<int> > Display_Tree , vector<int> child){
	vector<int> v;
	for (map< vector<int> , vector<int> >::iterator it = Display_Tree.begin(); it!=Display_Tree.end(); ++it)
	{
		if (it->first == child)
		{
			v = it->second;
			return v; 
		}
	}
	return child;
}

void Display_map(map< vector<int> , vector<int> > Display_Tree){
	/**
 * This function displays the map which contains the tree like structure of configurations in the form of 
 * child value pairs. 
 *
 *  @param   vector<int> Display_tree 		  represents a particular configuration of buckets. 
 *  @param   map< vector<int>	              This map consists of the tree like structure of configurations
 * 
 */
	for (map< vector<int> , vector<int> >::iterator it = Display_Tree.begin(); it!=Display_Tree.end(); ++it){
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

	queue < vector<int> > queue_Of_Vectors;
	vector< vector<int> > new_Config;
	tree[initial_Config] = initial_Config;
	queue_Of_Vectors.push(initial_Config);
	while(!get_goal_config(queue_Of_Vectors.front()) && !queue_Of_Vectors.empty()){
		new_Config = find_config(queue_Of_Vectors.front());
		for (int i = 0; i < new_Config.size(); ++i)
		{
			if(tree.find(new_Config[i])==tree.end()){
				queue_Of_Vectors.push(new_Config[i]);
				tree[new_Config[i]]=queue_Of_Vectors.front();
			}
		}
		queue_Of_Vectors.pop();
		if (get_goal_config(queue_Of_Vectors.front()))
		{
			stack_Of_Vectors.push(queue_Of_Vectors.front());
			break;
		}
	}
	Display_map(tree);
	Display(tree);
}

 int main(int argc, char *argv[]) {
	int n;
	int c;
	n = argc-2;

	std::stringstream str(argv[1]);
	str >> goal;

	for (int i = 0; i < n; ++i)
	{
		initial_Config.push_back(0);
	}
	
	for (int i = 2; i < argc; ++i)
	{
		std::stringstream str(argv[i]);
	    str >> c;
		bucket_Weight.push_back(c);
	}
	goal_solver();
}