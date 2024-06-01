#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca {

class Book {
    std::string title;
    int chapters;
    int pages;

public:
    Book(const std::string& t = "", int c = 0, int p = 0);

    bool isValid() const;
    double pagesToChaptersRatio() const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    bool operator<(const Book& other) const;
    bool operator>(const Book& other) const;

    std::ostream& print(std::ostream& os) const;
};

}

#endif // BOOK_H
