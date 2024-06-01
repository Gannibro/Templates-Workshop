#include "Book.h"

namespace seneca {

Book::Book(const std::string& t, int c, int p)
    : title(t), chapters(c), pages(p) {}

bool Book::isValid() const {
    return !title.empty() && chapters > 0 && pages > 0;
}

double Book::pagesToChaptersRatio() const {
    return isValid() ? static_cast<double>(pages) / chapters : 0.0;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    if (book.isValid()) {
        os << "| " << std::setw(45) << std::left << book.title
           << "," << book.chapters
           << "," << book.pages << " | ("
           << std::fixed << std::setprecision(6) << book.pagesToChaptersRatio()
           << ")    |";
    } else {
        os << "| Invalid book data |";
    }
    return os;
}

bool Book::operator<(const Book& other) const {
    return pagesToChaptersRatio() < other.pagesToChaptersRatio();
}

bool Book::operator>(const Book& other) const {
    return pagesToChaptersRatio() > other.pagesToChaptersRatio();
}

std::ostream& Book::print(std::ostream& os) const {
    return os << *this;
}

} // namespace seneca
