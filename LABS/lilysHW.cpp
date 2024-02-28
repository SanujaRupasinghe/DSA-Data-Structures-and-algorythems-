int lilysHomework(vector<int> arr) {
    
    vector<pair<int, int>> assendingPair, dessendingPair;
    int size_arr = arr.size();
    
    for (int i = 0; i < size_arr; i++)
        assendingPair.push_back({arr[i], i});    // initialize the indexes and value paired array
        
    for (int i = 0; i < size_arr; i++)
        dessendingPair.push_back({arr[i], i});    // initialize the indexes and value paired array
    
    //sort assending and dessending pairs
    sort(assendingPair.begin(),assendingPair.end());
    
    sort(dessendingPair.rbegin(),dessendingPair.rend());
    
    //take the count for assending and dessending coutns
    int ascending_count = 0, descending_count = 0;  
    
    
    int assendingPairSize = assendingPair.size(); 
    for (int i = 0; i < assendingPairSize; i++) {
        while (i != assendingPair[i].second) {
            swap(assendingPair[i], assendingPair[assendingPair[i].second]);
            ascending_count++;
        }
    }
    
    
    int dessendingPairSize = dessendingPair.size(); 
    for (int i = 0; i < dessendingPairSize; i++) {
        while (i != dessendingPair[i].second) {
            swap(dessendingPair[i], dessendingPair[dessendingPair[i].second]);
            descending_count++;
        }    
    }
    
    int result = min(ascending_count, descending_count);
    return result;

}