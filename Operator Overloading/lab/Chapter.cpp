#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}
	Chapter::Chapter() {
		init_chapter();
	}

	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title , title_);
	}
	Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}

	Chapter::operator int() const
	{
		return m_num_pages;
	}

	Chapter::operator double() const
	{
		return m_num_words;
	}

	Chapter::operator const char* () const
	{
		return m_title;
	}
	const Chapter& Chapter::operator=(const Chapter& right)
	{
		strcpy(m_title, right.m_title);
		m_num_pages = right.m_num_pages;
		m_chapter_number = right.m_chapter_number;
		m_num_words = right.m_num_words;
		return *this;
		// TODO: insert return statement here
	}
	Chapter& Chapter::operator++()
	{
		m_num_pages++;
		return *this;
		// TODO: insert return statement here
	}
	Chapter& Chapter::operator--()
	{
		m_num_pages--;
		return *this;
		// TODO: insert return statement here
	}
	std::ostream& operator<<(std::ostream& left, const Chapter& right)
	{
		return right.display(left);

		// TODO: insert return statement here
	}
}

