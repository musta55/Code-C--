#include <bits/stdc++.h>
using namespace std;

#define Long long long

struct Node
{
      vector<int> point;
      Node *left, *right;

      Node(int k)
      {
            this->point.resize(k);
      }

      Node(vector<int> &point)
      {
            this->point = point;
            this->left = this->right = NULL;
      }
};

struct Node *root = NULL;
int K;

int printMenu()
{
      int option;
      cout << "\n1. SEARCH A POINT\n2. RANGE QUERY\n3. INSERT POINT\n4. PRINT TREE\n->: ";
      cin >> option;
      return option;
}

bool searchAPoint(Node *curr, vector<int> &point, int index = 0)
{
      if (curr == NULL)
            return false;
      if (point == curr->point)
            return true;

      return searchAPoint((point[index] < curr->point[index]) ? curr->left : curr->right, point, (index + 1) % K);
}

void searchAPoint_init()
{
      vector<int> point(K);
      cout << "Point: ";
      for (int i = 0; i < K; ++i)
            cin >> point[i];

      searchAPoint(root, point) ? cout << "Found\n" : cout << "Not Found\n";
}

bool checkRange(vector<int> &point1, vector<int> &point2, vector<int> &point)
{
      for (int i = 0; i < K; ++i)
      {
            if (min(point1[i], point2[i]) > point[i] || max(point1[i], point2[i]) < point[i])
                  return false;
      }

      return true;
}

void rangeQuery(Node *curr, vector<vector<int>> &points, vector<int> &point1, vector<int> &point2, int index = 0)
{
      if (curr == NULL)
            return;
      if (checkRange(point1, point2, curr->point))
            points.push_back(curr->point);
      if (curr->point[index] >= min(point1[index], point2[index]) && curr->point[index] <= max(point1[index], point2[index]))
      {
            rangeQuery(curr->left, points, point1, point2, (index + 1) % K);
            rangeQuery(curr->right, points, point1, point2, (index + 1) % K);
      }
      else
      {
            if (curr->point[index] < min(point1[index], point2[index]))
                  rangeQuery(curr->right, points, point1, point2, (index + 1) % K);
            if (curr->point[index] >= max(point1[index], point2[index]))
                  rangeQuery(curr->left, points, point1, point2, (index + 1) % K);
      }
}

void rangeQuery_init()
{
      vector<int> point1(K), point2(K);
      cout << "Point1: ";
      for (int i = 0; i < K; ++i)
            cin >> point1[i];
      cout << "Point2: ";
      for (int i = 0; i < K; ++i)
            cin >> point2[i];

      vector<vector<int>> points;
      rangeQuery(root, points, point1, point2);

      if (points.empty())
            cout << "No point Found\n";
      for (vector<int> point : points)
      {
            cout << "[ ";
            for (int i = 0; i < K; ++i)
            {
                  if (i)
                        cout << ", ";
                  cout << point[i];
            }
            cout << " ]";
      }
}

Node *insertPoint(Node *curr, vector<int> &point, int index = 0)
{
      int count=1;
      if (curr == NULL)
            return curr = new Node(point);
            if(point[index] == curr->point[index])
            {
                  count++;
                  cout <<count;
            }
      else if (point[index] < curr->point[index])
            curr->left = insertPoint(curr->left, point, (index + 1) % K);
      else
            curr->right = insertPoint(curr->right, point, (index + 1) % K);
      return curr;
}

void insertPoint_init()
{
      vector<int> point(K);
      cout << "Point: ";
      for (int i = 0; i < K; ++i)
            cin >> point[i];

      if (root == NULL)
            root = new Node(point);
      else
            root = insertPoint(root, point);

      char YN;
      cout << "Want to continue the insert operation?(Y/N): ";
      cin >> YN;

      if (YN == 'Y' || YN == 'y')
            insertPoint_init();
}

void printtree(const string &prefix, const Node *node, bool isLeft)
{
      if (node != NULL)
      {
            cout << prefix;

            cout << (isLeft ? "|---" : "|***");

            cout << "(";

            for (int j = 0; j < K - 1; j++)
                  cout << node->point[j] << ",";
            cout << node->point[K - 1] << ")\n";

            printtree(prefix + (isLeft ? "|   " : "   "), node->left, true);
            printtree(prefix + (isLeft ? "|   " : "   "), node->right, false);
      }
}
void printtree(const Node *node)
{
      printtree("", node, false);
}
void printTree_init()
{
      printtree(root);
}

void menu()
{
      switch (printMenu())
      {
      case 1:
            searchAPoint_init();
            break;
      case 2:
            rangeQuery_init();
            break;
      case 3:
            insertPoint_init();
            break;
      case 4:
            printTree_init();
            break;
      default:
            cout << "Invalid choice.\n";
      }

      char YN;
      cout << "Go to the menu?(Y/N): ";
      cin >> YN;

      if (YN == 'Y' || YN == 'y')
            menu();
            else if(YN=='N' ||YN=='n'){
                  cout << "Are You sure?(Y|N)";
                  cin>>YN;
                     if (YN == 'Y' || YN == 'y')
                        return;
                        else menu();
            }
}

int main()
{
      cout << "Please enter the dimension of  k-D tree: ";
      cin >> K;

      menu();

      return 0;
}
