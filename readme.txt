/**
 *
 *  readme.txt
 *  
 *  Version: lloyd.cpp v 1.0  2014/04/12 09.19 PM
 *  
 *  @author: 
 *         	an3395(Arjun Nair)
 *			gr4075(Ganesh Rajasekharan)
 *		   	sxo4955(Shivankar Ojha)
 *			
 *
 *  Revisions:  
 *         Initial Revision.
 *        
 *  $Log$ 
 */

The clock problem

The first part of this problem is concerned with fixing a clock which has gone dead. The clock which has gone dead has only one hand. 
What we have is implemented an abstract class(Abstract_class.h)  which has the following functions basically: 

find_next_config(int l): This function takes an integer input and returns the the next configuration on the clock by moving the hand
forward.
 
find_prev_config(int m): This function takes an integer input and returns the the next configuration on the clock by moving the hand
backward. 

int get_goal_config(): This function returns the value of the goal configuration to be achieved. 

testing(int array[],int array1[]): This is the function which does the main work. It involves taking two arrays to store the already 
checked configurations. One in the forward direction and the other in the backward direction. These two arrays are used to check that
the current configuration in question hasn't already been checked. 
The queueObject being used keeps on storing the configurations and the method terminates as soon as the front of the queue is equal to 
the goal. 

The second file named clock. cpp is basically involved with setting the initial values and calling the functions of the abstract 
class to find the soultion to the given problem. 

Compilation: 
The program is run using the following sequence of commands: 
gmakemake>makefile
make
./clock number_of_hours current_time goal_time  

The code takes the input as command line arguments in the order mentioned above. 

/*****************************************************************************************************************************/

The Bucket Problem


This problem is concerned with the problem which involves taking a number of buckets with their capacities as their input, and then 
trying to get a particular amount of water in one of the buckets. 
The logic implemented here is pretty much the same as mentioned on the project website, i.e: 

"Create an initially empty queue of configurations.
    Insert the initial configuration into the queue.
    While
      the queue is not empty and
      the first configuration in the queue does not meet the goal,
    loop:
        Remove the first configuration from the queue and call it C.
        For each move applicable to C, loop:
          Make the move and enqueue the resulting
          configuration if it has not already been seen.
        end-loop.
    end-loop.
    The acceptable configuration is now at the head of the queue;
    but if the queue is empty, there is no solution to the problem."

Our logic stores all the initial configurations in a map called tree whose key value pair consists of two vectors, one representing
the configuration as the key, which is mapped onto its child configurations. The next configurations of each particular configuration
 are found using the next_config function, which in turn calls three functions for each configuration: empty_bucket, transfer_bucket 
and transfer bucket. All these configurations are stored in a map in a tree like structure as mentioned earlier. We then make use of a 
queue of Vectors into which we insert the configurations. We keep checking each configuration from this queue to see whether or not 
the front configuration of the queue has a bucket that meets the goal and the execution stops when the goal is achieved in one of the
 buckets or if the queue becomes empty,whichever comes first.
 


Compilation: 
The program is run using the following sequence of commands: 
gmakemake>makefile
make
./water goal_amount capacity_bucket_1 capacity_bucket_2 capacity_bucket_3.....   

The code takes the input as command line arguments in the order mentioned above. 


/******************************************************************************************************************************/

Lloyd's Puzzle 


This problem consists of a sequence of panels on a wooden board with a particular panel left blank, thereby enabling the blocks to be
slid forward, backward, downward or upward. The goal of the problem is to slide the panels and move them around in order to get a 
particular configuration of the panels from the given configuration. 

The logic used for this problem is again the same as the one used for the bucket problem. We use the same vectors , maps etc in order 
to solve this problem. The modifications made to the previos logic for this problem are as follows: 

1. The vector of vectors now has a string vector as its component which stores the configuration of the panels. 
2. the next_config function now has four function calls inside it, each representing a possible move for each of the panels i.e. 
forward, backward, upward and downward. 

Compilation: 
The program is run using the following sequence of commands: 
gmakemake>makefile
make

./lloyd - - 
OR 
./lloyd input_filename - 
OR 
./lloyd - output_filename 
OR
./lloyd input_filename output_filename

Here the command ./lloyd - - means that both the input and the output are concerned only with the console. 
./lloyd input_filename - means that the input is taken from a textfile whose name is provided on the commandline while the output is
displayed on the console. 


The format of the input file is as follows: 
no_of_row no_of_column
1st row of initial configuration
2nd row of initial configuration
...and so on
1st row of goal configuration
2nd row of goal configuration
..and so on. 


There is no space in between any lines of the input file. 
The "." character will represent spaces in the configurations entered. 

The map which is used to solve the problem is DISPLAYED IN ALL CASES on the console.  

We have also submitted a sample input file by the name of lloyd_sample_input.txt 

The output if required on a file, is written onto the file entered by the user on command line. 

References: A part of the code for the IO in the Lloyd's problem is taken from Professor Sidney Marshal's website. 
  
/******************************************************************************************************************************/