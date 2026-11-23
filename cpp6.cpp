#include <iostream>
#include <memory>
using namespace std;

// Resource class
class Resource
{
public:
    Resource()
    {
        cout << "Resource acquired" << endl;
    }
    ~Resource()
    {
        cout << "Resource released" << endl;
    }
    void use()
    {
        cout << "Resource is being used" << endl;
    }
};

// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;
public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
    }
    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }
    Resource* operator->()
    {
        return ptr;
    }
    // Disable copying to avoid double deletion
    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    cout << "----- Manual RAII Smart Pointer -----" << endl;
    {
        MySmartPointer smartPtr(new Resource());