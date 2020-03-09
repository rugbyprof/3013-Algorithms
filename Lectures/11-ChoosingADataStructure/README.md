## Selecting a Data Structure

It should go without saying that people write programs to solve problems. However, sometimes programmers forget this. 
So it is crucial to keep this truism in mind when selecting a **data structure** to solve a particular problem. 
Only by first analyzing the problem to determine the performance goals that must be achieved can there be any hope of 
selecting the right data structure for the job. Poor program designers ignore this analysis step and apply a data 
structure that they are familiar with but which is inappropriate to the problem. The result is typically a slow program. 
Conversely, there is no sense in adopting a complex representation to "improve" a program that can meet its performance 
goals when implemented using a simpler design.

### Step To Follow

When selecting a data structure to solve a problem, you should follow these steps.

- Analyze your problem to determine the basic operations that must be supported. 
  - Basic operations are: `Inserting` , `Finding`, and `Deleting` an item.
- Quantify the resource constraints for each operation 
  - What will each operation cost me?
- Select the data structure that best meets these requirements. 
  - The one that can minimize the cost (IF its worth the effort).
  
This **three-step** approach to selecting a data structure operationalizes a data-centered view of the design process. 
1. The first concern is for the data and the operations to be performed on them, 
2. the next concern is the representation for those data, 
3. and the final concern is the implementation of that representation.

Resource constraints on certain key operations, such as search, inserting data records, and deleting data records, normally drive the data structure selection process. 
Many issues relating to the relative importance of these operations are addressed by the following three questions, which you should ask yourself whenever you must choose a data structure.

- Are all data items inserted into the data structure at the beginning, or are insertions interspersed with other operations? 
  - Static applications (where the data are loaded at the beginning and never change) typically get by with simpler data structures to get an efficient implementation, 
  - while dynamic applications often require something more complicated.
- Can data items be deleted? If so, this will probably make the implementation more complicated.
- Are all data items processed in some well-defined order, or is search for specific data items allowed? 
  - "Random access" search generally requires more complex data structures.

Each data structure has associated costs and benefits. In practice, it is hardly ever true that one data structure is better than another for use in all situations. 
If one data structure or algorithm is superior to another in all respects, the inferior one will usually have long been forgotten. 

A data structure requires a certain amount of space for each data item it stores (**space complexity**), a certain amount of time to perform a single basic operation (**time complexity**), 
and a certain amount of programming effort. Each problem has constraints on available space and time. Each solution to a problem makes use of the basic operations in some relative proportion, and the data structure selection process must account for this. Only after a careful analysis of your problem's characteristics can you determine the best data structure for the task.