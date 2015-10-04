/**
 *
 *  Abstract_class.h
 *  
 *  Version: Abstract_class.h v 1.0  2014/01/12 10.20 AM
 *  
 *  @author: 
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
#include <queue>
using namespace std;

static int i=0;
static int z=0;
static int next_config_counter=0;
static int prev_config_counter=0;

class Abstract_class {
public:

	Abstract_class() {

	}

	int z;
	int n;
	int current_time;
	int goal;

	queue <int> queueObject;
	queue <int> queueObject1;

	int find_next_config(int l) {
		next_config_counter++;

		if(l==n)
			return 1;
		else
			return ++l;
	}

	int find_previous_config(int m) {
		prev_config_counter++;
		if(m==1)
			return n;
		else
			return --m;
	}

	int get_goal_config(){
		return goal;
	}

/**
 * This function solves the clock problem
 *
 *  @param   int array[]
 *  @param   int array1[]
 */

	void testing(int array[],int array1[]){

			int x=current_time;
			int y=current_time;

			queueObject.push(x);
			queueObject1.push(y); 

		while(queueObject.front()!= get_goal_config() && queueObject1.front()!= get_goal_config()){
				int flag=0;
				int flag1=0;

				if(queueObject.front() != get_goal_config()){
					cout<<"\n/***************************/";
					cout<<"\nThe Foward time  : "<<queueObject.front()<<endl;
					array[i] = queueObject.front();
					i++;
				
					x = find_next_config(queueObject.front());
					queueObject.pop();

				for(int j=0;j<i;j++){
					if(array[j]==x){
		    			flag=1;
		    		break;
		    		}
		    	}
		    		if(flag==0){
		    			queueObject.push(x);
		    		}
				}


				if(queueObject1.front() != get_goal_config()){
					cout<<"The Backward time: "<<queueObject1.front()<<endl;
					array1[z] = queueObject1.front();
					z++;
				
					y = find_previous_config(queueObject1.front());
					queueObject1.pop();

				for(int j=0;j<i;j++){
					if(array1[j]==y){
		    			flag1=1;
		    		break;
		    		}
		    	}
		    		if(flag1==0){
		    			queueObject1.push(y);
		    		}
				}				
			}

			if(queueObject.front()==get_goal_config()){
			cout<<"\nThe Goal has been achieved by moving the clock forward : "<<queueObject.front();
			cout<<"\nThe number of hours moved: "<<next_config_counter;
		}else{
			cout<<"\nThe Goal has been achieved by moving the clock backward: "<<queueObject1.front();	
			cout<<"\nThe number of hours moved: "<<prev_config_counter;
			}		
		}
		~Abstract_class() {
		}
};	

