#include "types.hxx"
#include <iostream>
#include <string>

int main() {
    type::queue<int> test_queue;
    test_queue.push(100);
    std::cout << "getFirst: " << test_queue.getFirst() << "; getLast: " << test_queue.getLast() << "; getSize: " << test_queue.getSize() << "; isEmpty? " << test_queue.isEmpty() << std::endl;
    test_queue.push(0);
    std::cout << "getFirst: " << test_queue.getFirst() << "; getLast: " << test_queue.getLast() << "; getSize: " << test_queue.getSize() << "; isEmpty? " << test_queue.isEmpty() << std::endl;
    test_queue.push(101);
    std::cout << "getFirst: " << test_queue.getFirst() << "; getLast: " << test_queue.getLast() << "; getSize: " << test_queue.getSize() << "; isEmpty? " << test_queue.isEmpty() << std::endl;
    test_queue.pop();
    std::cout << "getFirst: " << test_queue.getFirst() << "; getLast: " << test_queue.getLast() << "; getSize: " << test_queue.getSize() << "; isEmpty? " << test_queue.isEmpty() << std::endl;
    test_queue.pop();
    std::cout << "getFirst: " << test_queue.getFirst() << "; getLast: " << test_queue.getLast() << "; getSize: " << test_queue.getSize() << "; isEmpty? " << test_queue.isEmpty() << std::endl;
    test_queue.pop();
    std::cout << "; getSize: " << test_queue.getSize() << "; isEmpty? " << test_queue.isEmpty() << std::endl;
    
    
    type::queue<std::string> test_string_queue;
    test_string_queue.push("I'm first!!!");
    std::cout << "getFirst: " << test_string_queue.getFirst() << "; getLast: " << test_string_queue.getLast() << "; getSize: " << test_string_queue.getSize() << "; isEmpty? " << test_string_queue.isEmpty() << std::endl;
    test_string_queue.push("yolo!");
    std::cout << "getFirst: " << test_string_queue.getFirst() << "; getLast: " << test_string_queue.getLast() << "; getSize: " << test_string_queue.getSize() << "; isEmpty? " << test_string_queue.isEmpty() << std::endl;
    test_string_queue.push("hii!!");
    std::cout << "getFirst: " << test_string_queue.getFirst() << "; getLast: " << test_string_queue.getLast() << "; getSize: " << test_string_queue.getSize() << "; isEmpty? " << test_string_queue.isEmpty() << std::endl;
    test_string_queue.pop();
    std::cout << "getFirst: " << test_string_queue.getFirst() << "; getLast: " << test_string_queue.getLast() << "; getSize: " << test_string_queue.getSize() << "; isEmpty? " << test_string_queue.isEmpty() << std::endl;
    test_string_queue.pop();
    std::cout << "getFirst: " << test_string_queue.getFirst() << "; getLast: " << test_string_queue.getLast() << "; getSize: " << test_string_queue.getSize() << "; isEmpty? " << test_string_queue.isEmpty() << std::endl;
    test_string_queue.pop();
    std::cout << "; getSize: " << test_string_queue.getSize() << "; isEmpty? " << test_string_queue.isEmpty() << std::endl;


    type::queue<int>* Test = new type::queue<int>;
    Test->push(84);
    std::cout << Test->getSize() << std::endl;
    Test->push(239);
    std::cout << Test->getSize() << std::endl;
    delete Test; 
    std::cout << Test->getSize() << std::endl;


    return 0;
}