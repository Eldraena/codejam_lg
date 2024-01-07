//Print unordered set
void print_set(string name, const unordered_set<int> st)
{
    cout << name << "(unordered_set): ";
    for (auto x : st)
        cout << x << " ";
    cout << endl;
}

//Initialize unordered set
unordered_set<int> st = {3, 1, 5, -4, 2, 9};
print_set("st", st);

//Get size
cout << st.size() << endl;

//Insert elements
st.insert(-31);
st.insert(5);
print_set("st", st);

//Find elements
int num = -4;
if(st.find(num) != st.end())
    cout << num << " is exist" << endl;
else
    cout << num << " is not exist" << endl;

//Delete elements
num = 2;
st.erase(num);
print_set("st", st);
