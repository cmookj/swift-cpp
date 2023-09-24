//
//  CppEngine.hpp
//  CppBridgeTest
//
//  Created by Changmook Chun on 2023-02-27.
//

#ifndef CppEngine_hpp
#define CppEngine_hpp

#include <string>
#include <vector>

class integer_buffer {
public:
    integer_buffer() = delete;
    explicit integer_buffer (std::size_t sz, const std::string& name);
    ~integer_buffer() = default;
    
    std::string name() const;
    std::size_t size() const;
    
    int at(const std::size_t) const;
    void set_value_at(const std::size_t, const int&);
    
private:
    std::string _name;
    std::vector<int> _buffer;
};

#endif /* CppEngine_hpp */
