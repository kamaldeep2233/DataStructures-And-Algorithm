#include<bits/stdc++.h>
using namespace std;

class HeapBuilders {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps;

  void WriteResponse() const {
    cout << swaps.size() << "\n";
    for (int i = 0; i < swaps.size(); ++i) {
      cout << swaps[i].first << " " << swaps[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int leftValue(int i){
    return 2*i + 1;
  }

  int rightValue(int i){
    return 2*i + 2;
  }

  int parent(int i){
    return floor((i-1)/2);
  }

  void swimDown(int i){
    int maxIndex = i;
    int l = leftValue(i);
    if(l <= data_.size()-1 && data_[l] > data_[maxIndex])
      maxIndex = l;
    int r = rightValue(i);
    if(r <= data_.size()-1 && data_[r] > data_[maxIndex])
      maxIndex = r;
    if(i != maxIndex){
      swap(data_[i], data_[maxIndex]);
      swaps.push_back(make_pair(i, maxIndex));
      swimDown(maxIndex);
    }
  }

  void GenerateSwaps() {
    swaps.clear();

      int n = data_.size();
      //cout << " size : " << n << endl;
      for(int i=1;i<=(n-1)/2;i++){
        swimDown(i);
      }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilders heap_builder;
  heap_builder.Solve();
  return 0;
}
