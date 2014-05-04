README

STEPS

1) Run 'make' command
2) Run command of the form ./BestFirstSearch <input> <output>

DATA STRUCTURES

Priority Queue
	A priority queue is used to pick the next highest bound during the search. This is implemented as a max heap

Vector
	A vector is used to store the traversal through the graph for printing to the output file once the search is complete

COMPUTATION TIME
I cant get it to run properly so I cant comment on the running time

CLASSES
Node - Used to create and store the profit, weight, bound, etc. of each of the nodes of the state space tree

Priority Queue - Used to pick the next best node by bound in the search algorithm

***NOTE***
This program compiles properly but does not run due to an infinite loop that I cannot fix. I cant even find where the problem originates from.