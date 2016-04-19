#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
class String;

struct Buffer {
    size_t size;
    char *buffer;
    size_t *link_counter;
};

class String {
    Buffer *buffer_;
public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    String& operator=(String);
    char operator[](int) const;
    char& operator[](int);
    operator std::string() const;
    String& operator+=(const String&);
    void print() const;
};


void String::print() const {
    std::cout << "buffer=" << (long)buffer_->buffer << std::endl;
    if (buffer_->buffer != NULL) {
        std::cout << "*buffer=" << buffer_->buffer << std::endl;
    }
    std::cout << "size=" << buffer_->size << std::endl;
    std::cout << "link_counter=" << (long)buffer_->link_counter << std::endl;
    if (buffer_->link_counter != NULL) {
        std::cout << "*link_counter=" << *buffer_->link_counter << std::endl;
    }
    std::cout << std::endl;
}

String::String() {
    buffer_ = new Buffer;
    buffer_->size = 1;
    buffer_->buffer = new char[1];
    buffer_->buffer[0] = 0;
    buffer_->link_counter = new size_t(1);
}

String::String(const char *s) {
    buffer_ = new Buffer;
    buffer_->size = strlen(s) + 1;
    buffer_->buffer = new char[buffer_->size];
    buffer_->link_counter = new size_t(1);
    strcpy(buffer_->buffer, s);
}

String::String(const String &s) {
    buffer_ = s.buffer_;
    ++(*buffer_->link_counter);
}

String::~String() {
    //std::cout << "~STRING():\n";
    //print();
    --*buffer_->link_counter;
    if (*buffer_->link_counter == 0) {
        delete[] buffer_->buffer;
        delete buffer_->link_counter;
        delete buffer_;
    }
}

String& String::operator=(String s) {
    std::swap(buffer_, s.buffer_);
    return *this;
}

String::operator std::string() const {
    return std::string(buffer_->buffer);

}

char String::operator[](int i) const {
    return buffer_->buffer[i];
}

char& String::operator[](int i) {
    if (*buffer_->link_counter > 1) {
        Buffer *tmp = new Buffer;
        char *new_buffer = new char[buffer_->size];
        strncpy(new_buffer, buffer_->buffer, buffer_->size);
        --*buffer_->link_counter;
        buffer_ = tmp;
        buffer_->buffer = new_buffer;
        buffer_->link_counter = new size_t(1);
    }
    return buffer_->buffer[i];
}

String& String::operator+=(const String &s) {
    char *new_buffer = new char[buffer_->size + s.buffer_->size - 1];
    strncpy(new_buffer, buffer_->buffer, buffer_->size - 1);
    strncpy(new_buffer + buffer_->size - 1, s.buffer_->buffer, s.buffer_->size);
    String s_tmp = *this;
    
    Buffer *tmp = new Buffer;
    tmp->size = buffer_->size + s.buffer_->size - 1;
    --*buffer_->link_counter;
    buffer_ = tmp;
    buffer_->link_counter = new size_t(1);
    buffer_->buffer = new_buffer;
    return *this;
}
/*
int main() {
    String a[100];
    String b[100];
    String c[100];
    //a[0][0] = 1;
    char *t = new char[2];
    for (int i = 0; i < 100; ++i) {
        t[0] = i;
        t[1] = 0;
        std::string s(t);
        a[i] = s.c_str();
    }
    delete[] t;
    for (int i = 0; i < 100; ++i) {
        b[i] += a[i];
        c[i] = a[i];
        c[i][0] = i + 1;
    }

    const String x = "abc";
    std::cout << x[1] << std::endl;
    std::cout << std::string(x) << std::endl;
    const String y = x;
    std::cout << y[1] << std::endl;
    std::cout << std::string(y) << std::endl;
    String z = x;
    z[1] = 'f';
    std::cout << std::string(z) << std::endl;
    std::cout << std::string(x) << std::endl;
}
*/
