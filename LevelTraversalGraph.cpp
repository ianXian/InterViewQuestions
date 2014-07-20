#include<set>
#include<iostream>
#include<list>

using namespace std;

class Node
{
    int id;
    list<int> friends;

 public:
    Node(int i)
    {
        id = i;
    }
    void AddFriend(int id)
    {
        friends.push_back(id);
    }
}

void printLevelByLeve(Node& A)
{
}


int main()
{
    Node A(0);
    Node B(1);
    Node C(2);
    Node D(3);
    Node E(4);
    Node F(5);

    A.AddFriend(1);
    A.AddFriend(3);
    A.AddFriend(5);
    B.AddFriend(0);
    B.AddFriend(3);
    B.AddFriend(4);
    C.AddFriend(1);
    C.AddFriend(4);
    C.AddFriend(5);
    D.AddFriend(1);
    D.AddFriend(3);
    E.AddFriend(3);
    F.AddFriend(2);

    printLevelByLeve(A);

    return 0;
}
