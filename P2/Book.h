#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

namespace seneca {

class Book {
    std::string m_title;
    unsigned m_chapters;
    unsigned m_pages;

public:
    Book(const std::string& title = "", unsigned chapters = 0, unsigned pages = 0);

    double pagesToChaptersRatio() const;
    bool operator<(const Book& other) const;
    bool operator>(const Book& other) const;

    std::ostream& print(std::ostream& os) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

}

#endif // SENECA_BOOK_H