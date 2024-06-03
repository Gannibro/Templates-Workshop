#include "Book.h"

namespace seneca {

Book::Book(const std::string& title, unsigned chapters, unsigned pages)
    : m_title(title), m_chapters(chapters), m_pages(pages) {}

double Book::pagesToChaptersRatio() const {
    return m_chapters > 0 ? static_cast<double>(m_pages) / m_chapters : 0.0;
}

bool Book::operator<(const Book& other) const {
    return pagesToChaptersRatio() < other.pagesToChaptersRatio();
}

bool Book::operator>(const Book& other) const {
    return pagesToChaptersRatio() > other.pagesToChaptersRatio();
}

std::ostream& Book::print(std::ostream& os) const {
    if (m_title.empty() && m_chapters == 0 && m_pages == 0) {
        return os << "| Invalid book data";
    } else {
        return os << std::setw(50) << std::right << m_title << "," << m_chapters << "," << m_pages
           << " | (" << std::fixed << std::setprecision(6) << pagesToChaptersRatio() << ")    ";
    }
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    book.print(os);
    return os;
}

}