
<!-- * Author: Sapir Dahan -->
<!--ID: 325732972 -->
<!-- * Mail: sapirdahan2003@gmail.com -->



# Graph Operations

## Project Description
This C++ project provides a comprehensive set of functions for managing and manipulating graphs represented as adjacency matrices. The functions include capabilities to load graphs, calculate graph metrics, and perform arithmetic and comparison operations on graphs. The functions are designed to handle square matrices as graphs, ensuring no self-edges exist within the graph structure. The library offers a robust set of operations including addition, subtraction, multiplication (both scalar and matrix), division, and various comparison operations to facilitate extensive graph analysis and manipulation.

---

## How to Run the Project
### Compile the project

Use the provided `makefile` to build and run the project:
    
   - To build demo:
        ```bash
        make run
        ```
  - To build tests:
      ```bash
      make test
      ```
  - To check for memory leaks using Valgrind:
      ```bash
      make valgrind
      ```
  - To perform static code analysis using cppcheck:
      ```bash
      make cppcheck
      ```

### Run the project
After compiling, execute the relevant executable file.

- To run the demo
  ```bash
  ./demo
  ```
- To run the tests
  ```bash
  ./test
  ```

### Clean compiled files
To clean compiled files, run the command:
```bash
  make clean
  ```

---

## Files Included
- `Algorithms.cpp` and `Algorithms.hpp`: Implementation and header files for graph algorithms.
- `Graph.cpp` and `Graph.hpp`: Implementation and header files for the graph data structure.
- `Demo.cpp`: Demo application showcasing the implemented algorithms.
- `Test.cpp` and `TestCounter.cpp`: In Test we are checking a variety of scenarios and in TestCounter we count the tests and making sure there are more then 20.


---

## Functions
### Functions From Project 1
- **Strong Connectivity Check**: Determines if the graph is strongly connected, meaning there is a path between all pairs of vertices.
- **Shortest Path Calculation**: Utilizes the Bellman-Ford algorithm to find the shortest path between any two vertices. It will return the path if existed. In addition, if there is a negative cycle in the path the algorithm will output it.
- **Cycle Detection**: Identifies if the graph contains any cycles. It will return the cycle if existed. For this project, we say there is a cycle in the graph only if it contains at least 3 different vertexes.
- **Bipartite Verification**: Checks if the graph is bipartite, meaning it can be colored with two colors such that no two adjacent vertices share the same color. If it is, it will return the two groups.
- **Negative Cycle Detection**: Determining if there a negative cycle in the graph.
- **Load Graph**: Load a matrix to be a graph object and trows error if the matrix is not square. It will also trow error if there is an edge from a vertex to itself.
- **Print Graph**: Return how many edges and vertexes a graph have.

### Functions For Project 2 (Operators)
#### Addition (`operator+`)

Performs element-wise addition of two graphs. Both graphs must have the same dimensions.

**Usage:** `Graph result = graph1 + graph2;`

#### In-place Addition (`operator+=`)

Performs in-place element-wise addition of the current graph with another graph. Both graphs must have the same dimensions.

**Usage:** `graph1 += graph2;`

#### Unary Plus (`operator+`)

Returns a copy of the current graph.

**Usage:** `Graph result = +graph;`

#### Increment (`operator++`)

Increments all non-zero elements of the graph by 1.

**Usage:** `graph++;`

#### Subtraction (`operator-`)

Performs element-wise subtraction between two graphs. Both graphs must have the same dimensions.

**Usage:** `Graph result = graph1 - graph2;`

#### In-place Subtraction (`operator-=`)

Performs in-place element-wise subtraction of another graph from the current graph. Both graphs must have the same dimensions.

**Usage:** `graph1 -= graph2;`

#### Unary Minus (`operator-`)

Negates all elements of the graph.

**Usage:** `Graph result = -graph;`

#### Decrement (`operator--`)

Decrements all non-zero elements of the graph by 1.

**Usage:** `graph--;`

#### Scalar Multiplication (`operator*`)

Multiplies each element of the graph by a scalar value.

**Usage:** `Graph result = graph * factor;`

#### Scalar Division (`operator/`)

Divides each element of the graph by a scalar value. Division by zero throws an exception.

**Usage:** `Graph result = graph / factor;`

#### Multiplication Assignment Operator (`operator*=`)

Multiplies each element of the graph by a scalar value.

**Usage:** `graph *= factor;`

#### Division Assignment Operator (`operator/=`)

Divides each element of the graph by a scalar value. Division by zero throws an exception.

**Usage:** `graph /= factor;`

#### Matrix Multiplication (`operator*`)

Performs matrix multiplication between two graphs. Both graphs must have the same dimensions. The diagonal will be zeros.

**Usage:** `Graph result = graph1 * graph2;`

#### Matrix Multiplication Assignment Operator(`operator*=`)

Performs matrix multiplication between two graphs. Both graphs must have the same dimensions. The diagonal will be zeros.

**Usage:** `graph1 *= graph2;`

#### Comparison Operators (`operator==`, `operator!=`, `operator<`, `operator<=`, `operator>`, `operator>=`)

The comparison operators in this C++ graph library provide a comprehensive way to compare two graphs based on their size (number of vertices) and edges. The comparison takes into account both the structure and the weights of the edges to determine the relationship between the graphs.

- **Equality (`operator==`)**: This operator checks if two graphs are exactly equal. It compares the size, structure, and edge weights of both graphs. Returns true if the graphs are identical in all aspects.

- **Inequality (`operator!=`)**: The inequality operator determines if two graphs are not equal. It returns true if the graphs differ in size, structure, or edge weights.

- **Less Than (`operator<`)**: This operator compares two graphs based on their size and edges. It checks if one graph is a proper subset of the other with the same order of vertices, and there exists at least one edge in the larger graph that is not present in the smaller graph.

- **Less Than or Equal To (`operator<=`)**: The less than or equal to operator compares two graphs, ensuring that one graph is either smaller or equal to the other. It considers both size and edges in the comparison.

- **Greater Than (`operator>`)**: The greater than operator determines if one graph is a proper superset of the other with the same order of vertices. It checks for additional edges in the larger graph that are not present in the smaller graph.

- **Greater Than or Equal To (`operator>=`)**: This operator compares two graphs to find out if one graph is larger or equal to the other. It considers both size and edges in the comparison, ensuring that the larger graph contains all edges of the smaller graph and possibly more.

#### Output Stream Operator Overload (`operator<<`)
The `operator<<` overload for the `Graph` class in C++ enables objects of the class to be output to an output stream, such as `std::cout`, using the insertion operator `<<`. This overload, implemented as a friend function of the class, grants access to the private and protected members of the class. The `operator<<` function calls the `printGraph()` member function to generate a string representation of the graph and outputs it to the specified output stream.

**Usage:** `cout<<graph`

In addition to the main functionalities mentioned earlier, the project includes several helper functions to support the core algorithms.

In the current assignment, it is important to note that the algorithms from the previous assignment remain unchanged. The focus of this assignment primarily involved creating new graphs and conducting comparisons between them. As a result, the fundamental algorithms used for graph processing and analysis have not been altered or modified.
