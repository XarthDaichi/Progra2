#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Person {
private:
    int age;
    string name;
public:
    Person(int a, string n) : age(a), name(n) {}
    virtual ~Person() {}
    void setAge(int a) {age = a;}
    int getAge() {return age;}
    void setName(string n) {name = n;}
    string getName() {return name;}
    string toString() {
        stringstream s;
        s << age << name;
        return s.str();
    }
};

void print_vec(const std::vector<int>& vec)
{
    for (auto x: vec) {
         std::cout << ' ' << x;
    }
    std::cout << '\n';
}
 
int main ()
{
    std::vector<int> vec(3,100);
    print_vec(vec);
 
    auto it = vec.begin();
    it = vec.insert(it, 200);
    print_vec(vec);
 
    vec.insert(it,2,300);
    print_vec(vec);
 
    // "it" no longer valid, get a new one:
    it = vec.begin();
 
    std::vector<int> vec2(2,400);
    vec.insert(it+2, vec2.begin(), vec2.end());
    print_vec(vec);
 
    int arr[] = { 501,502,503 };
    vec.insert(vec.begin(), arr, arr+3);
    print_vec(vec);

    auto iterator = vec.begin();
    vec.insert(iterator, 1);

    Person person(1, "Diego");
    cout << person.toString() << endl;
    Person* p2 = new Person(person);
    cout << p2->toString();
}
