//find number of element in range [minval, maxval] and (minval, maxval)
vector<int> vt = {1, -3, 5, 2, 10, 7, 3, 1};
int minval = 1, maxval = 5;
int cnt = count_if(vt.begin(), vt.end(), [minval, maxval](int x) {return x >= minval && x <= maxval;});
//int cnt = count_if(vt.begin(), vt.end(), [minval, maxval](int x) {return x > minval && x < maxval;});

//find min, max element
int minx = *min_element(vt.begin(), vt.end());
int maxx = *max_element(vt.begin(), vt.end());
