class Solution {
public:
 vector<string> topKFrequent(vector<string>& words, int k) {
	int size = words.size();
	vector<vector<string>> bucket(size+1);
	unordered_map<string, int> table;
	vector<string> res;

	//generate freq table
	for (int i = 0; i < size; i++) {
		table[words[i]]++;
	}

	//populate the bucket
	for (auto it = table.begin(); it != table.end(); it++) {
		vector<string>& temp = bucket[it->second];
		if (temp.empty()) temp.push_back(it->first);
		else {
			int j = 0, n = temp.size();
			while (j < n && temp[j] < it->first) j++;
			temp.insert(temp.begin()+j, it->first);
		}
	}

	//push topK freq words to res
	for (int i = bucket.size()-1; i >= 0 && k > 0; i--) {
		for (int j = 0; j < bucket[i].size() && k > 0; j++) {
			res.push_back(bucket[i][j]);
			k--;
		}
	}

	return res;
}
};