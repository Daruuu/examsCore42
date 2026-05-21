#ifndef INC_42_EXAM_BIGINT_HPP
#define INC_42_EXAM_BIGINT_HPP
#include <iosfwd>
#include <vector>

#endif //INC_42_EXAM_BIGINT_HPP

class Bigint
{
	std::vector<unsigned char> digits_;

public:
	Bigint();
	Bigint(const Bigint& src);
	Bigint(unsigned long n);
	~Bigint();

	friend std::ostream& operator<<(std::ostream& os, const Bigint& b);
};
