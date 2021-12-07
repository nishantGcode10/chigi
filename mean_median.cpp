#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {

	ifstream ip("data.csv");

	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';
	vector<vector<string>> mat;

	while (ip.good()) {
		string temp;
		getline(ip, temp, '\n');
		string str = temp;
		vector<string> v;

		stringstream ss(str);

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}
		mat.push_back(v);
	}
	ip.close();
	int n = mat.size();
	int m = mat[0].size();
	cout<<"There are "<<n<<" data entries"<<endl;
	cout<<"There are "<<m<<" features"<<endl;
	for(int j=0;j<m;j++){
	double mean = 0;
	for (int i = 0; i < n; i++) {
		mean += stoi(mat[i][j]);
	}
	mean /= (double)n;
	double variance = 0;
	for (int i = 0; i < n; i++) {
		double x = abs(mean - stoi(mat[i][j]));
		x = x * x;
		variance += x;
	}
	variance /= (double)n;
	double std_deviation = sqrt(variance);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		vec.push_back(stoi(mat[i][j]));
	}
	sort(vec.begin(), vec.end());
	double median = 0;
	if (n & 1) {
		int idx = (n + 1) / 2;
		idx--;
		median = vec[idx];
	}
	else {
		int idx = n/ 2;
		median = vec[idx];
		median += vec[idx - 1];
		median /= (double)2;
	}
	cout<<"Measures for "<<j<<" feature : "<<endl;
	cout << "mean" << " : " << mean << endl;
	cout << "median" << " : " << median << endl;
	cout << "variance" << " : " << variance << endl;
	cout << "standard deviation" << " : " << std_deviation << endl;
	}
	return 0;
}
