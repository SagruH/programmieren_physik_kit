
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

//prints 2D Martix; include vector
void printMatrix(vector<vector<double>> matrix, int n, int m) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cout << " " << matrix[i][j] << " ";
    }
    cout << endl;
  }
}


// copy pasted from https://gist.github.com/mortenpi/f20a93c8ed3ee7785e65
// Linear interpolation following MATLAB linspace
    std::vector<double> LinearSpacedArray(double a, double b, std::size_t N)
    {
        double h = (b - a) / static_cast<double>(N-1);
        std::vector<double> xs(N);
        std::vector<double>::iterator x;
        double val;
        for (x = xs.begin(), val = a; x != xs.end(); ++x, val += h) {
            *x = val;
        }
        return xs;
    }
