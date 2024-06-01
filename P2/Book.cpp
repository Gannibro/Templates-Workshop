#include "Book.h"

namespace seneca {

Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
    : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

bool Book::isValid() const {
    return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
}

std::string Book::getTitle() const {
    return m_title;
}

unsigned Book::getNumChapters() const {
    return m_numChapters;
}

unsigned Book::getNumPages() const {
    return m_numPages;
}

double Book::getAveragePagesPerChapter() const {
    if (m_numChapters == 0) return 0;
    return static_cast<double>(m_numPages) / m_numChapters;
}

bool Book::operator<(const Book& other) const {
    return getAveragePagesPerChapter() < other.getAveragePagesPerChapter();
}

bool Book::operator>(const Book& other) const {
    return getAveragePagesPerChapter() > other.getAveragePagesPerChapter();
}

std::ostream& Book::print(std::ostream& os) const {
    if (isValid()) {
        os << std::setw(56) << std::right << m_title << ", "
           << m_numChapters << ", " << m_numPages << " | "
           << std::setw(15) << std::left << getAveragePagesPerChapter();
    } else {
        os << "| Invalid book data |";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Book& bk) {
    return bk.print(os);
}

} // namespace seneca
