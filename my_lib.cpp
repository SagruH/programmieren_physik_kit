
//reads 2D file ; inculde fstream; vector; 
vector<vector<int>> readfile(string filename, int n) { //columns ; lines
  fstream ffile;
  ffile.open(filename, ios::in);
  int a;
  int i=0, j=0;
  vector<vector <int>> content;
  vector<int> temp;

  while (ffile >> a) {
    temp.push_back(a);
    i++;
    if (i==n) {
      i=0;
      content.push_back(temp);
      temp.clear();
    }
  }

  ffile.close();
  return content;
}
