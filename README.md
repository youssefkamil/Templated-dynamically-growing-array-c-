# Templated dynamically growing array

A Templated dynamically growing array has the following :
   
   1-  **constructor** that receive 2 inputs from user
     
   -  size        : default 5
     
   -  defaultOpt  : default optimization to choose between ("RAM" or "TIME"), when expanding the array
                   if you choose "RAM" --> the array grow element by element, "TIME" --> will duplicate the capacity

   2- **cap** ->           the capacity of the array
   
   3- **nrOfEl** ->        number of elements in the
   
   4- **push_back** ->     adds a single element to the array
   
   5- **remove_if** ->     takes pointer to function and number to compare with to remove elements that satisfies that predicate
   
   6- **[] operator** ->   to access the elements
   
   7- **size() ->**        return the number of elements
