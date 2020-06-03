class Solution {
public:
   
       bool canFinish( int numCourses, vector<vector<int>>& prerequisites ) {
	/* Create adjacency list and indegree array for each course*/
	vector<int> indegree( numCourses, 0 );
	unordered_map<int, set<int> > adjList;
	for( auto prereq : prerequisites ) {
		adjList[ prereq[1] ].insert( prereq[0] );
		indegree[ prereq[0] ]++;
	}

	/* Add all the sources with indegree zero to queue for processing */
	queue<int> sources;
	for( int i=0; i < indegree.size(); i++ )
		if( indegree[i] == 0 )
			sources.push( i );

	/* For each source visit all neighbours and reduce their indegrees */
	int noOfCoursesTaken = 0;
	while( !sources.empty() ) {
		++noOfCoursesTaken;
		int curr = sources.front(); sources.pop();
		for( auto nbr : adjList[curr] ) {
			--indegree[nbr];
			if( indegree[nbr] == 0 )
				sources.push(nbr);
		}    
	}
	return noOfCoursesTaken == numCourses;
}
};
