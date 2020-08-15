// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <queue>

using namespace std;

int main () {
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);
  priority_queue<int> q(myints, myints+5);

 

  make_heap (v.begin(),v.end());
  cout << "initial max heap   : " << v.front() << '\n';
  cout << "initial priority queue: " << q.top() << endl << endl;

  pop_heap (v.begin(),v.end());
  v.pop_back();
  q.pop();
  cout << "max heap after pop : " << v.front() << '\n';
  cout << "priority queue after pop: " << q.top() << endl << endl;

  v.push_back(99);
  q.push(99);
  push_heap (v.begin(),v.end());
  cout << "max heap after push: " << v.front() << '\n';
  cout << "priority queue after push: " << q.top() << endl;

   sort_heap (v.begin(),v.end());

  cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
      cout << ' ' << v[i];
cout << endl;
   

   while(!q.empty())
{
    cout << q.top() << " ";
    q.pop();
}

  cout << '\n';

  return 0;
}
