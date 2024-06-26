/*
 * Author: Sapir Dahan
 * ID: 325732972
 * Mail: sapirdahan2003@gmail.com
 */

#include "Graph.hpp"

using namespace ariel;


// Load the graph and check if it squares also no edge between a vertex to himself
void Graph::loadGraph(const std::vector<std::vector<int>>& graph){

    // Check the matrix is square
    for(unsigned int i = 0; i < graph.size(); i++){
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        // No edges allowed between the vertex to himself
		if (graph[i][i] != 0){
			throw invalid_argument("Invalid graph: No edges allowed between the vertex to himself.");
		}
    }
    // Assign the graph to the matrix member variable
    matrix = graph;
}

// Return how many vertex and edge the graph have
string Graph::printGraphEx1() const {
    int edges = 0;

    // counting the edges
    for (const auto& edge : matrix) {
        for (int num : edge) {
            if (num != 0) {
                edges++;
            }
        }
    }

    // Construct the string
    string description = "Graph with " + std::to_string(matrix.size()) + " vertices and " + to_string(edges) + " edges.";
    return description;
}

// Return the size
unsigned int Graph::size() const{
    return matrix.size();
}

// Get the edge
const int Graph::getEdge(unsigned int x, unsigned int y) const{

    // Check if x and y are within the bounds of the matrix
    if (x >= matrix.size() || y >= matrix[0].size()) {
        throw out_of_range("Index out of range");
    }

    return matrix[x][y];
}

// Get the vertex how are not 0
vector<unsigned int> Graph::getConnectedVertices(unsigned int vertex) const {

    vector<unsigned int> connectedVertices;

    // Check the bound
    if (vertex >= matrix.size()) {
        throw out_of_range("Vertex index out of range");
    }

    // Find the edges
    const vector<int>& edges = matrix[vertex];
    for (unsigned int i = 0; i < edges.size(); ++i) {
        if (edges[i] != 0) {
            connectedVertices.push_back(i);
        }
    }

    // Return the connected vertexes
    return connectedVertices;
}

// Transpose the vertices of the graph
void Graph::transposeGraph() {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i + 1; j < matrix.size(); j++) {

            // Swap elements at position (i, j) and (j, i)
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}


/// Project 2 ///

// Graph addition
Graph Graph::operator+(const Graph& other) const {

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw invalid_argument("Invalid operation: Graphs must have the same dimensions for addition.");
    }

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Perform addition per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }

    // Return the result
    return result;
}

// In-place Addition
void Graph::operator+=(const Graph& other){

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Invalid operation: Graphs must have the same dimensions for addition.");
    }

    // Perform addition per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
}

// Unary Plus
Graph& Graph::operator+() {
    return *this;
}

// Increment by 1 for each edge that already exist
Graph Graph::operator++(int) {

    // Perform addition per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] != 0){
                matrix[i][j] = matrix[i][j] + 1;
            }
        }
    }
    return *this;
}

// Graph subtraction
Graph Graph::operator-(const Graph& other) const {

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw invalid_argument("Invalid operation: Graphs must have the same dimensions for subtraction.");
    }

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Perform subtraction per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }

    // Return the result
    return result;
}

// In-place Subtraction
void Graph::operator-=(const Graph& other){

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Invalid operation: Graphs must have the same dimensions for subtraction.");
    }

    // Perform subtraction per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
}

// Unary Minus
Graph& Graph::operator-() {

    // Multiply every edge with -1
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] = (-1) * matrix[i][j];
        }
    }

    return *this;
}

// Decrement, Subtract 1 from each edge that already exist
Graph Graph::operator--(int) {

    // Perform subtraction per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] != 0){
                matrix[i][j] = matrix[i][j] - 1;
            }
        }
    }

    // Return the result
    return *this;
}


// Multiply by a factor
Graph Graph::operator*(int factor) const{

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Multiply by a factor
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            result.matrix[i][j] = matrix[i][j] * factor;
        }
    }

    // Return the result
    return result;
}


// In palace factor multiply
void Graph::operator*=(int factor){
    *this = *this * factor;
}

// Factor division
Graph Graph::operator/(int factor) const{

    // Dividing by 0 is not allowed
    if(factor == 0){
        throw std::invalid_argument("Invalid operation: dividing by 0 is not allowed.");
    }

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Divide by the factor
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            result.matrix[i][j] = matrix[i][j] / factor;
        }
    }

    // Return the result
    return  result;
}


// in place division
void Graph::operator/=(int factor){
    *this = *this / factor;
}


// Graph multiplying
Graph Graph::operator*(const Graph& other) const {

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw invalid_argument("Invalid operation: Graphs must have the same dimensions for multiplication.");
    }

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Matrix multiplication
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        for (unsigned int j = 0; j < matrix.size(); ++j) {
            for (unsigned int k = 0; k < matrix.size(); ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    // Put zeros on the diagonal
    for(unsigned int i = 0; i < size(); i++){
        result.matrix[i][i] = 0;
    }

    // Return the result
    return result;
}


// In palace Graph multiplication
void Graph::operator*=(const Graph& other){
    *this = *this * other;
}

// Equals
bool Graph::operator==(const Graph& other) const{

    // Check the size
    if(size() != other.size()){

        // Not equals
        return false;
    }

    // Check each element
    for(unsigned int i = 0; i < size(); i++){
        for(unsigned int j = 0; j < size(); j++){
            if(getEdge(i, j) != other.getEdge(i, j)){

                // Not equals
                return false;
            }
        }
    }

    // Equals
    return true;
}

// Not equals
bool Graph::operator!=(const Graph& other) const{

    if(*this == other){
        return false; // Equals
    }
    return true; // Not equals
}

// Less than
bool Graph::operator<(const Graph& other) const{

    // If the other graph has fewer vertices, it cannot be larger than the current graph
    if(size() > other.size()){
        return false;
    }

    // If the other graph has fewer edges, it cannot be larger than the current graph
    if(countEdges() >= other.countEdges()){
        return false;
    }

    // Get all the combinations of vertexes that can be subgraph
    vector<vector<unsigned int>> combinations = getAllCombinations(size(), other.size());

    bool flag = true;

    // Go over all the combinations
    for (const std::vector<unsigned int>& comb : combinations) {
        for(unsigned int i = 0; i < size(); i++){
            for(unsigned int j = 0; j < size(); j++){
                if(getEdge(i, j) != 0){
                    if(other.getEdge(comb[i], comb[j]) != getEdge(i, j)){
                        flag = false;
                    }
                }
            }
        }

        if(flag){
            return true; // It is subgraph
        }

        // Reset for the next run
        flag = true;
    }

    // It not subgraph
    return false;
}

// Less equal
bool Graph::operator<=(const Graph& other) const{

    // If less or if equals
    if(*this == other || *this < other){
        return true;
    }

    return false;
}

// Greater than
bool Graph::operator>(const Graph& other) const{

    // Using <
    if(other < *this){
        return true;
    }
    return false;
}

// Greater equals
bool Graph::operator>=(const Graph& other) const{

    // If > or equals
    if(*this > other || *this == other){
        return true;
    }

    return false;
}

/// Help Functions ///
// Recursive function to generate combinations in ascending order
void Graph::generateCombinations(vector<vector<unsigned int>>& result, vector<unsigned int>& combination, unsigned int start, unsigned int n, unsigned int m) const{

    // Base case: when n elements have been chosen
    if (n == 0) {
        result.push_back(combination); // Add the current combination to the result
        return;
    }

    // Recursive case: choose elements in ascending order
    for (unsigned int i = start; i <= m - n; i++) {
        combination.push_back(i); // Include the current element in the combination
        generateCombinations(result, combination, i + 1, n - 1, m); // Recur with the next element
        combination.pop_back(); // Backtrack: remove the last element to try other possibilities
    }
}

// Function to get all combinations of choosing n elements from a set of size m in ascending order
vector<vector<unsigned int>> Graph::getAllCombinations(unsigned int n, unsigned int m) const{
    std::vector<std::vector<unsigned int>> result; // Store all combinations
    std::vector<unsigned int> combination; // Current combination being built
    generateCombinations(result, combination, 0, n, m); // Start generating combinations
    return result;
}


// Count the edges
int Graph::countEdges() const{
    int counter = 0;
    for(unsigned int i = 0; i < size(); i++){
        for(unsigned int j = 0; j < size(); j++){
            if(getEdge(i, j) != 0){
                counter++;
            }
        }
    }

    // Return the counter
    return counter;
}

// Print the graph
string Graph::printGraph() const {
    string str = "";
    for(unsigned  int i = 0; i < matrix.size(); i++){
        str += "[";
        for(unsigned  int j = 0; j < matrix.size(); j++){
            str += to_string(matrix[i][j]) + ", ";
        }

        // Erase the last 2 chars
        str.erase(str.size() - 2);

        // In order to make use "\n" won't be at the end
        if(i != matrix.size() - 1){
            str += "]\n";
        }
        else{
            str += "]";
        }
    }
    return str;
}

